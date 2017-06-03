#pragma once
#include <cstdint>

template <int64_t v>
struct cint64 {
	constexpr static int64_t val = v;
};

template <int64_t v>
using ci64 = cint64<v>;

#define ci64(v) ci64<v>;