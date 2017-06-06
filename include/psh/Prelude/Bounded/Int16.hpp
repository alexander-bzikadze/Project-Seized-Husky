#pragma once

#include <climits>

#include "Bounded.hpp"
#include "../Types.hpp"

template <int16_t a>
struct Bounded<cint16<a>> {
	using minBound = cint16<SHRT_MIN>;
	using maxBound = cint16<SHRT_MAX>;
};