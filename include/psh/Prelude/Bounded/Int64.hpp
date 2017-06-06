#pragma once

#include <climits>

#include "Bounded.hpp"
#include "../Types.hpp"

template <int64_t a>
struct Bounded<cint64<a>> {
	using minBound = cint64<LLONG_MIN>;
	using maxBound = cint64<LLONG_MAX>;
};