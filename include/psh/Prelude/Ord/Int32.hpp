#pragma once

#include "Ord.hpp"

namespace Ord {

template <int32_t ord_1, int32_t ord_2>
struct Leq<cint32<ord_1>, cint32<ord_2>> {
	using val = cbool<ord_1 <= ord_2>;
};

}