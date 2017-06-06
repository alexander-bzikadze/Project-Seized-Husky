#pragma once

#include <climits>

#include "Bounded.hpp"
#include "../Types.hpp"

template <char a>
struct Bounded<cchar<a>> {
	using minBound = cc<(char)CHAR_MIN>;
	using maxBound = cc<(char)CHAR_MAX>;
};