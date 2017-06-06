#pragma once

#include "Eq.hpp"
#include "../Types.hpp"

namespace Eq {

template <>
struct equals<Nothing, Nothing> {
	using val = ctrue;
};

template <typename eq_2>
struct equals<Nothing, Just<eq_2>> {
	using val = cfalse;
};

template <typename eq_1>
struct equals<Just<eq_1>, Nothing> {
	using val = cfalse;
};

template <typename eq_1, typename eq_2>
struct equals<Just<eq_1>, Just<eq_2>> {
	using val = Eq::equals<eq_1, eq_2>;
};

} // end of namespace Eq

