#pragma once
#include "../Bool.hpp"

namespace Eq { 

namespace mEq {

template <typename eq_1, typename eq_2>
struct equals;

} // end of namespace Eq::mEq

template <typename eq_1, typename eq_2>
struct equals {
	using val = typename mEq::template equals<eq_1, eq_2>::val;
};

template <typename eq_1, typename eq_2>
struct not_equals {
	using val = typename cnot<typename mEq::equals<eq_1, eq_2>::val>::val;
};

}// end of namespace Eq