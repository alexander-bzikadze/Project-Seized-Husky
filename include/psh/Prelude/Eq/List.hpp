#pragma once

#include "Eq.hpp"
#include "../List.hpp"

namespace Eq { namespace mEq {

template <typename a_1, typename a_2>
struct equals<List<a_1>, List<a_2>> {
	using val = typename Eq::equals<a_1, a_2>::val;
};

template <typename a_1, typename ...args_1, typename a_2, typename ...args_2>
struct equals<List<a_1, args_1...>, List<a_2, args_2...>> {
	using val = typename cand<typename Eq::equals<a_1, a_2>::val, typename Eq::equals<List<args_1...>, List<args_2...>>::val>::val;
};

}} // end of namespace Eq::mEq