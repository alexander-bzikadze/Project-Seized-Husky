#pragma once

#include "Ord.hpp"

namespace Ord {

template <int8_t ord_1, int8_t ord_2>
struct Leq<cint8<ord_1>, cint8<ord_2>> {
	using val = cbool<ord_1 <= ord_2>;
};

}