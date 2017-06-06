#pragma once

template <int>
struct Ordering;

using LT = Ordering<-1>;
using EQ = Ordering<0>;
using GT = Ordering<1>;