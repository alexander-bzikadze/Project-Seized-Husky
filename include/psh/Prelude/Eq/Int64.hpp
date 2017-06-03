#pragma once

namespace Eq { namespace mEq {

template <int64_t a, int64_t b>
struct equals<cint64<a>, cint64<b>> {
	using val = cbool<a == b>;
};

}} // end of namespace Eq::mEq