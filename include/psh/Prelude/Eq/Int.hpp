#pragma once

namespace Eq { namespace mEq {

template <int a, int b>
struct equals<cint<a>, cint<b>> {
	using val = cbool<a == b>;
};

}} // end of namespace Eq::mEq