#pragma once

#include "Ord.hpp"

namespace Ord {

template <typename ord_1, typename ord_2>
struct Leq<Left<ord_1>, Right<ord_2>> {
	using val = cfalse;
};

template <typename ord_1, typename ord_2>
struct Leq<Right<ord_1>, Left<ord_2>> {
	using val = ctrue;
};

template <typename ord_1, typename ord_2>
struct Leq<Left<ord_1>, Left<ord_2>> {
	using val = typename Ord::Leq<ord_1, ord_2>::val;
};

template <typename ord_1, typename ord_2>
struct Leq<Right<ord_1>, Right<ord_2>> {
	using val = typename Ord::Leq<ord_1, ord_2>::val;
};

} // end of namespace Ord