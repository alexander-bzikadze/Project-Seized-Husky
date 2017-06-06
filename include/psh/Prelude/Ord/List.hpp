#pragma once

#include "Ord.hpp"

namespace Ord {

template <typename a_1, typename ...ord_1, typename a_2, typename ...ord_2>
struct Leq<List<a_1, ord_1...>, List<a_2, ord_2...>> {
	using val = typename If_then_else<typename Eq::equals<a_1, a_2>::val, typename Ord::Leq<List<ord_1...>, List<ord_2...>>::val, typename Ord::Leq<a_1, a_2>::val>::val;
};

template <typename ...ord_1>
struct Leq<List<ord_1...>, List<>> {
	using val = ctrue;
};

template <typename ...ord_1>
struct Leq<List<>, List<ord_1...>> {
	using val = cfalse;
};

}