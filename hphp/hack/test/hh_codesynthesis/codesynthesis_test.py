#!/usr/bin/env python3
# pyre-strict
# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the "hack" directory of this source tree.
import tempfile
import unittest

from hphp.hack.src.hh_codesynthesis import hh_codesynthesis, hackGenerator
from hphp.hack.src.hh_codesynthesis.hh_codesynthesis import ClingoContext


class GenerateLogicRulesTest(unittest.TestCase):
    def test_depth_less_than_nodes(self) -> None:
        ClingoContext.number_of_nodes = 12
        ClingoContext.min_depth = 3
        exp = [
            'internal_symbols("S0", 0;"S1", 1;"S2", 2;"S3", 3;"S4", 4;"S5", 5;"S6", 6;"S7", 7;"S8", 8;"S9", 9;"S10", 10;"S11", 11).',
            'extends_to("S0", "S4").',
            'extends_to("S4", "S8").',
        ]
        self.assertListEqual(exp, hh_codesynthesis.generate_logic_rules())

    def test_depth_more_than_nodes(self) -> None:
        # In this case, the graph has no way to satisfy the min_depth requirement.
        # The user, or the higher level wrapper should make sure given proper
        # parameters. Otherwise, we will create the following output.
        ClingoContext.number_of_nodes = 3
        ClingoContext.min_depth = 5
        with self.assertRaises(
            expected_exception=RuntimeError, msg="Received unreasonable parameters."
        ):
            hh_codesynthesis.generate_logic_rules()

    def test_depth_equals_to_nodes(self) -> None:
        ClingoContext.number_of_nodes = 7
        ClingoContext.min_depth = 7
        exp = [
            'internal_symbols("S0", 0;"S1", 1;"S2", 2;"S3", 3;"S4", 4;"S5", 5;"S6", 6).',
            'extends_to("S0", "S1").',
            'extends_to("S1", "S2").',
            'extends_to("S2", "S3").',
            'extends_to("S3", "S4").',
            'extends_to("S4", "S5").',
            'extends_to("S5", "S6").',
        ]
        self.assertListEqual(exp, hh_codesynthesis.generate_logic_rules())

    def test_hack_code_gen(self) -> None:
        ClingoContext.number_of_nodes = 12
        ClingoContext.min_depth = 3
        ClingoContext.min_classes = 3
        ClingoContext.min_interfaces = 4
        ClingoContext.lower_bound = 1
        ClingoContext.higher_bound = 5
        ClingoContext.avg_width = 0
        exp = """\
<?hh
class S9   {}
class S10   {}
class S11   {}
interface S0  {}
interface S1  {}
interface S2  {}
interface S3  {}
interface S4 extends S0 {}
interface S5  {}
interface S6  {}
interface S7  {}
interface S8 extends S4 {}
"""

        hack_codegen = hackGenerator.HackCodeGenerator()
        hh_codesynthesis.do_reasoning(
            additional_programs=hh_codesynthesis.generate_logic_rules(),
            generator=hack_codegen,
        )
        self.assertEqual(str(hack_codegen), exp)

    def test_hack_code_gen_with_partial_dependency_graph_given_by_user(self) -> None:
        ClingoContext.number_of_nodes = 12
        ClingoContext.min_depth = 3
        ClingoContext.min_classes = 3
        ClingoContext.min_interfaces = 4
        ClingoContext.lower_bound = 1
        ClingoContext.higher_bound = 5
        ClingoContext.avg_width = 0
        deps = """\
Extends A -> Type B
Extends I -> Type B
Extends T -> Type A
Type A -> Type B
Type I -> Type B
Type T -> Type A, Type B"""
        exp = """\
<?hh
class S9   {}
class S10   {}
class S11   {}
interface A extends T {}
interface B extends A,I {}
interface I  {}
interface T  {}
interface S0  {}
interface S1  {}
interface S2  {}
interface S3  {}
interface S4 extends S0 {}
interface S5  {}
interface S6  {}
interface S7  {}
interface S8 extends S4 {}
"""

        hack_codegen = hackGenerator.HackCodeGenerator()
        combined_rules = (
            hh_codesynthesis.generate_logic_rules()
            + hh_codesynthesis.extract_logic_rules(deps.split("\n"))
        )
        hh_codesynthesis.do_reasoning(
            additional_programs=combined_rules,
            generator=hack_codegen,
        )
        self.assertEqual(str(hack_codegen), exp)

    def test_unsatisfiable_parameters(self) -> None:
        # Given 5 nodes, but asking for 3 classes + 4 interfaces with
        ClingoContext.number_of_nodes = 5
        ClingoContext.min_classes = 3
        ClingoContext.min_interfaces = 4
        hack_codegen = hackGenerator.HackCodeGenerator()

        with self.assertRaises(expected_exception=RuntimeError, msg="Unsatisfiable."):
            hh_codesynthesis.do_reasoning(
                additional_programs=hh_codesynthesis.generate_logic_rules(),
                generator=hack_codegen,
            )


class ExtractLogicRulesTest(unittest.TestCase):
    def test_wrong_format(self) -> None:
        exp = [
            'extends_to("A", "B").',
            'extends_to("I", "B").',
            'extends_to("T", "A").',
            'symbols("A";"B";"I";"T").',
        ]
        deps = """\
Extends A -> Type B
Extends I -> Type B
Extends T -> Type A, Broke
Type A -> Type B
Type I -> Type B
Type T -> Type A, Type B"""
        self.assertListEqual(
            exp, hh_codesynthesis.extract_logic_rules(deps.split("\n"))
        )

    def test_multiple_lines(self) -> None:
        exp = [
            'extends_to("I1", "C1").',
            'extends_to("I1", "C2").',
            'extends_to("I1", "C3").',
            'extends_to("I1", "I2").',
            'extends_to("I3", "C4").',
            'extends_to("I4", "C5").',
            'symbols("C1";"C2";"C3";"C4";"C5";"I1";"I2";"I3";"I4").',
        ]
        deps = """\
Extends I1 -> Type C1, Type C2, Type C3, Type I2
Extends I3 -> Type C4,
                Type C6,
                Type I5,
                Type I6,
                Type I7,
                Type I8
Extends I4 -> Type C5,
               Type C6,
               Type I9,
               Type I10,
               Type I11,
               Type I12,
               Type I13,
               Type I14"""
        self.assertListEqual(
            exp, hh_codesynthesis.extract_logic_rules(deps.split("\n"))
        )

    def test_multiple_lines_all(self) -> None:
        # T92303034 Temporary handle for the multiple lines using replace(",\n", ","),
        exp = [
            'extends_to("I1", "C1").',
            'extends_to("I1", "C2").',
            'extends_to("I1", "C3").',
            'extends_to("I1", "I2").',
            'extends_to("I3", "C4").',
            'extends_to("I3", "C6").',
            'extends_to("I3", "I5").',
            'extends_to("I3", "I6").',
            'extends_to("I3", "I7").',
            'extends_to("I3", "I8").',
            'extends_to("I4", "C5").',
            'extends_to("I4", "C6").',
            'extends_to("I4", "I9").',
            'extends_to("I4", "I10").',
            'extends_to("I4", "I11").',
            'extends_to("I4", "I12").',
            'extends_to("I4", "I13").',
            'extends_to("I4", "I14").',
            'symbols("C1";"C2";"C3";"C4";"C5";"C6";"I1";"I10";"I11";"I12";"I13";"I14";"I2";"I3";"I4";"I5";"I6";"I7";"I8";"I9").',
        ]
        deps = """\
Extends I1 -> Type C1, Type C2, Type C3, Type I2
Extends I3 -> Type C4,
                Type C6,
                Type I5,
                Type I6,
                Type I7,
                Type I8
Extends I4 -> Type C5,
               Type C6,
               Type I9,
               Type I10,
               Type I11,
               Type I12,
               Type I13,
               Type I14"""
        self.assertListEqual(
            exp,
            hh_codesynthesis.extract_logic_rules(deps.replace(",\n", ",").split("\n")),
        )

    def test_extends_dependency(self) -> None:
        exp = [
            'extends_to("A", "B").',
            'extends_to("I", "B").',
            'extends_to("T", "A").',
            'symbols("A";"B";"I";"T").',
        ]
        deps = """\
Extends A -> Type B
Extends I -> Type B
Extends T -> Type A
Type A -> Type B
Type I -> Type B
Type T -> Type A, Type B"""
        self.assertListEqual(
            exp, hh_codesynthesis.extract_logic_rules(deps.split("\n"))
        )


class DoReasoningTest(unittest.TestCase):
    def test_clingo_exception(self) -> None:
        deps = ["rule_without_period(symbol1, symbol2)"]
        raw_codegen = hh_codesynthesis.CodeGenerator()
        with self.assertRaises(expected_exception=RuntimeError, msg="parsing failed"):
            hh_codesynthesis.do_reasoning(
                additional_programs=deps, generator=raw_codegen
            )

    def test_extends_dependency(self) -> None:
        exp = [
            'class("B")',
            'class("I")',
            'extends("A","T")',
            'extends("B","I")',
            'implements("B","A")',
            'interface("A")',
            'interface("T")',
        ]
        rules = [
            'extends_to("A", "B").',
            'extends_to("I", "B").',
            'extends_to("T", "A").',
            'symbols("A";"B";"I";"T").',
        ]
        raw_codegen = hh_codesynthesis.CodeGenerator()
        hh_codesynthesis.do_reasoning(additional_programs=rules, generator=raw_codegen)
        self.assertListEqual(sorted(str(raw_codegen).split()), exp)

    def test_extends_dependency_with_rule_extraction(self) -> None:
        exp = [
            'class("B")',
            'class("I")',
            'extends("A","T")',
            'extends("B","I")',
            'implements("B","A")',
            'interface("A")',
            'interface("T")',
        ]
        deps = """\
Extends A -> Type B
Extends I -> Type B
Extends T -> Type A
Type A -> Type B
Type I -> Type B
Type T -> Type A, Type B
"""
        raw_codegen = hh_codesynthesis.CodeGenerator()
        additional_programs = hh_codesynthesis.extract_logic_rules(deps.split("\n"))
        hh_codesynthesis.do_reasoning(
            additional_programs=additional_programs, generator=raw_codegen
        )
        self.assertListEqual(sorted(str(raw_codegen).split()), exp)

    def test_extends_dependency_hack_codegen(self) -> None:
        exp = """\
<?hh
class B extends I implements A {}
class I   {}
interface A extends T {}
interface T  {}
"""
        rules = [
            'extends_to("A", "B").',
            'extends_to("I", "B").',
            'extends_to("T", "A").',
            'symbols("A";"B";"I";"T").',
        ]
        hack_codegen = hackGenerator.HackCodeGenerator()
        hh_codesynthesis.do_reasoning(additional_programs=rules, generator=hack_codegen)
        self.assertEqual(str(hack_codegen), exp)

    def test_extends_dependency_with_rule_extraction_hack_codegen(self) -> None:
        exp = """\
<?hh
class B extends I implements A {}
class I   {}
interface A extends T {}
interface T  {}
"""
        deps = """\
Extends A -> Type B
Extends I -> Type B
Extends T -> Type A
Type A -> Type B
Type I -> Type B
Type T -> Type A, Type B
"""
        hack_codegen = hackGenerator.HackCodeGenerator()
        additional_programs = hh_codesynthesis.extract_logic_rules(deps.split("\n"))
        hh_codesynthesis.do_reasoning(
            additional_programs=additional_programs, generator=hack_codegen
        )
        self.assertEqual(str(hack_codegen), exp)


class ReadFromFileTest(unittest.TestCase):
    def test_read(self) -> None:
        exp = [
            'extends_to("A", "B").',
            'extends_to("I", "B").',
            'extends_to("T", "A").',
            'symbols("A";"B";"I";"T").',
        ]
        deps = """\
Extends A -> Type B
Extends I -> Type B
Extends T -> Type A
Type A -> Type B
Type I -> Type B
Type T -> Type A, Type B
"""
        with tempfile.NamedTemporaryFile(mode="w") as fp:
            fp.write(deps)
            fp.flush()
            self.assertListEqual(
                exp,
                hh_codesynthesis.extract_logic_rules(
                    hh_codesynthesis.read_from_file_or_stdin(fp.name)
                ),
            )

    def test_non_exist(self) -> None:
        test_file = "non_exist.in"
        with self.assertRaises(expected_exception=FileNotFoundError):
            hh_codesynthesis.extract_logic_rules(
                hh_codesynthesis.read_from_file_or_stdin(test_file)
            )


class WriteToFileTest(unittest.TestCase):
    def test_hack_output(self) -> None:
        exp = """\
<?hh
class C1   {}
class C2 extends C1 implements I1 {}
interface I1  {}
"""
        generator = hackGenerator.HackCodeGenerator()
        generator._add_class("C1")
        generator._add_class("C2")
        generator._add_interface("I1")
        generator._add_extend("C2", "C1")
        generator._add_implement("C2", "I1")
        with tempfile.NamedTemporaryFile("r") as fp:
            hh_codesynthesis.output_to_file_or_stdout(generator, fp.name)
            lines = fp.readlines()
            self.assertEqual("".join(lines), exp)
