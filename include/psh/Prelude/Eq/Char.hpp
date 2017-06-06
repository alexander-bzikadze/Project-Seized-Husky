#pragma once

#include "Eq.hpp"
#include "../Types.hpp"

namespace Eq {

template <char c1, char c2>
struct equals<cc<c1>, cc<c2>> {
	using val = cbool<c1 == c2>;
};

} // end of namespace Eq