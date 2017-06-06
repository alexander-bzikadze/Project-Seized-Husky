#pragma once

#include "Eq.hpp"
#include "../Types.hpp"

namespace Eq {

template <bool b1, bool b2>
struct equals<cbool<b1>, cbool<b2>> {
	using val = cbool<!(b1 ^ b2)>;
};

} // end of namespace Eq