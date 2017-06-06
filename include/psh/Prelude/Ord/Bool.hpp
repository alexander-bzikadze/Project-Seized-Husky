#pragma once

#include "Ord.hpp"

namespace Ord {

template <bool ord_1, bool ord_2>
struct Leq<cbool<ord_1>, cbool<ord_2>> {
	using val = cbool<ord_1 <= ord_2>;
};
 
} // end of namespace Ord