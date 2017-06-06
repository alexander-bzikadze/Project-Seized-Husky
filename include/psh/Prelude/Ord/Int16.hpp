#pragma once

#include "Ord.hpp"

namespace Ord {

template <int16_t ord_1, int16_t ord_2>
struct Leq<cint16<ord_1>, cint16<ord_2>> {
	using val = cbool<ord_1 <= ord_2>;
};

}