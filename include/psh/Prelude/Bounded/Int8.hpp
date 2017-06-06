#pragma once

#include <climits>

#include "Bounded.hpp"
#include "../Types.hpp"

template <int8_t a>
struct Bounded<cint8<a>> {
	using minBound = cint8<CHAR_MIN>;
	using maxBound = cint8<CHAR_MAX>;
};