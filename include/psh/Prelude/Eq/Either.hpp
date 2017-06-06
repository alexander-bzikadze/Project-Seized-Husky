#pragma once

#include "Eq.hpp"
#include "../Types.hpp"

namespace Eq {

template <typename eq_1, typename eq_2>
struct equals<Right<eq_1>, Right<eq_2>> {
	using val = typename Eq::equals<eq_1, eq_2>::val;
};

template <typename eq_1, typename eq_2>
struct equals<Left<eq_1>, Left<eq_2>> {
	using val = typename Eq::equals<eq_1, eq_2>::val;
};

template <typename eq_1, typename eq_2>
struct equals<Right<eq_1>, Left<eq_2>> {
	using val = cfalse;
};

template <typename eq_1, typename eq_2>
struct equals<Left<eq_1>, Right<eq_2>> {
	using val = cfalse;
};

} // end of namespace Eq