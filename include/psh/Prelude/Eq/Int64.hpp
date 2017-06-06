#pragma once

#include "Eq.hpp"
#include "../Types.hpp"

namespace Eq {

template <int64_t a, int64_t b>
struct equals<cint64<a>, cint64<b>> {
	using val = cbool<a == b>;
};

} // end of namespace Eq