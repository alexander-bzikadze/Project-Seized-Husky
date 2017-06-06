#pragma once

#include "Bounded.hpp"
#include "../Types.hpp"

template <bool a>
struct Bounded<cbool<a>> {
	using minBound = cfalse;
	using maxBound = ctrue;
};