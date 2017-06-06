#pragma once

#include "Eq.hpp"
#include "../Types.hpp"

namespace Eq {

template <int a, int b>
struct equals<cint<a>, cint<b>> {
	using val = cbool<a == b>;
};

} // end of namespace Eq