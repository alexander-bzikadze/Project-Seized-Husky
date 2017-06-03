#pragma once

namespace Eq { namespace mEq {

template <int8_t a, int8_t b>
struct equals<cint8<a>, cint8<b>> {
	using val = cbool<a == b>;
};

}} // end of namespace Eq::mEq