#pragma once

namespace Eq { namespace mEq {

template <int32_t a, int32_t b>
struct equals<cint32<a>, cint32<b>> {
	using val = cbool<a == b>;
};

}} // end of namespace Eq::mEq