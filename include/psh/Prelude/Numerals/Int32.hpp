#pragma once
#include <cstdint>

template <int32_t v>
struct cint32 {
	constexpr static int32_t val = v;
};

template <int32_t v>
using ci32 = cint32<v>;

#define ci32(v) ci32<v>;