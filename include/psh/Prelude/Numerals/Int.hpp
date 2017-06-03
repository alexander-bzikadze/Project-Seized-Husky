#pragma once
#include <cstdint>

template <int v>
struct cint {
	constexpr static int val = v;
};

template <int v>
using ci = cint<v>;

#define ci(v) ci<v>;