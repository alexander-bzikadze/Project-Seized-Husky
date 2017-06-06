#pragma once

#include "Ord.hpp"

namespace Ord {

template <typename ord_1, typename ord_2>
struct Leq<Just<ord_1>, Just<ord_2>> {
	using val = typename Ord::Leq<ord_1, ord_2>::val;
};

template <typename ord_1>
struct Leq<Just<ord_1>, Nothing> {
	using val = cfalse;
};

template <typename ord_2>
struct Leq<Nothing, Just<ord_2>> {
	using val = ctrue;
};

template <>
struct Leq<Nothing, Nothing> {
	using val = ctrue;
};

} // end of namespace Ord