#pragma once

#include <climits>

#include "Bounded.hpp"
#include "../Types.hpp"

template <int a>
struct Bounded<cint<a>> {
	using minBound = cint<INT_MIN>;
	using maxBound = cint<INT_MAX>;
};