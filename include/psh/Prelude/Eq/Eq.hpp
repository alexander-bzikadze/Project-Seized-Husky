#pragma once

#include "../Bool.hpp"

namespace Eq { 

template <typename eq_1, typename eq_2>
struct equals;
template <typename eq_1, typename eq_2>
struct not_equals;

template <typename eq_1, typename eq_2>
struct equals {
	using val = typename cnot<typename Eq::not_equals<eq_1, eq_2>::val>::val;
};

template <typename eq_1, typename eq_2>
struct not_equals {
	using val = typename cnot<typename Eq::equals<eq_1, eq_2>::val>::val;
};

}// end of namespace Eq