#pragma once

#include "Ord.hpp"

namespace Ord {

template <int64_t ord_1, int64_t ord_2>
struct Leq<cint64<ord_1>, cint64<ord_2>> {
	using val = cbool<ord_1 <= ord_2>;
};

} // end of namespace Ord