<?hh

class A<T> {}

<<__SupportDynamicType>>
function foo(A<int> $a) : void {}

<<__SupportDynamicType>>
class C {
  public function bar(A<int> $v) : void {
    foo($v);
  }
}
