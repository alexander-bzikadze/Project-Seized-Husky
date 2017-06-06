#pragma once

#include "Ord.hpp"

namespace Ord {

template <typename a_1, typename b_1, typename a_2, typename b_2>
struct Leq<Pair<a_1, b_1>, Pair<a_2, b_2>> {
	using val = typename If_then_else<typename Eq::equals<a_1, a_2>::val, typename Ord::Leq<b_1, b_2>::val, typename Ord::Leq<a_1, a_2>::val>::val;
};

}