#pragma once

namespace Eq {

template <int64_t a, int64_t b>
struct equals<cint64<a>, cint64<b>> {
	using val = cbool<a == b>;
};

} // end of namespace Eq::mEq