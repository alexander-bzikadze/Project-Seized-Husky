#pragma once

#include "Eq.hpp"
#include "../Types.hpp"

namespace Eq {

template <int16_t a, int16_t b>
struct equals<cint16<a>, cint16<b>> {
	using val = cbool<a == b>;
};

} // end of namespace Eq