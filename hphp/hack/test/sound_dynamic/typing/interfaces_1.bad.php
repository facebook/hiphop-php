<?hh
// Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved.

// A class that implements an interface that extends dynamic,
// must itself implements dynamic

interface I extends dynamic {}

class D implements I {}
