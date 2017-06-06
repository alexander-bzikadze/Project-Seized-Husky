#pragma once

#include "Ord.hpp"

namespace Ord {

template <int ord_1, int ord_2>
struct Leq<cint<ord_1>, cint<ord_2>> {
	using val = cbool<ord_1 <= ord_2>;
};

} // end of namespace Ord