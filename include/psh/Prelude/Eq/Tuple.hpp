#pragma once

#include "Eq.hpp"
#include "../Tuple.hpp"

namespace Eq {

template <typename a_1, typename b_1, typename a_2, typename b_2>
struct equals<Pair<a_1, b_1>, Pair<a_2, b_2>> {
	using val = typename cand<typename Eq::equals<a_1, a_2>::val, typename Eq::equals<b_1, b_2>::val>::val;
};

} // end of namespace Eq::mEq