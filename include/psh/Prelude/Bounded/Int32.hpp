#pragma once

#include <climits>

#include "Bounded.hpp"
#include "../Types.hpp"

template <int32_t a>
struct Bounded<cint32<a>> {
	using minBound = cint32<INT_MIN>;
	using maxBound = cint32<INT_MAX>;
};