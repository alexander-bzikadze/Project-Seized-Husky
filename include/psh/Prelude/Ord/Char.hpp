#pragma once

#include "Ord.hpp"

namespace Ord {

template <char ord_1, char ord_2>
struct Leq<cc<ord_1>, cc<ord_2>> {
	using val = cbool<ord_1 <= ord_2>;
};

} // end of namespace Ord