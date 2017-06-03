#pragma once
#include "Eq.hpp"
#include "../Char.hpp"

namespace Eq { namespace mEq {

template <char c1, char c2>
struct equals<cc<c1>, cc<c2>> {
	using val = cbool<c1 == c2>;
};

}} // end of namespace Eq::mEq