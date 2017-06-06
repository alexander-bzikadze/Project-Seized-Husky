#pragma once

#include "Eq.hpp"
#include "../Types.hpp"

namespace Eq {

template <>
struct equals<LT, LT> {
	using val = ctrue;
};

template <>
struct equals<EQ, EQ> {
	using val = ctrue;
};

template <>
struct equals<GT, GT> {
	using val = ctrue;
};

template <>
struct equals<LT, EQ> {
	using val = cfalse;
};

template <>
struct equals<LT, GT> {
	using val = cfalse;
};

template <>
struct equals<EQ, LT> {
	using val = cfalse;
};

template <>
struct equals<EQ, GT> {
	using val = cfalse;
};

template <>
struct equals<GT, LT> {
	using val = cfalse;
};

template <>
struct equals<GT, EQ> {
	using val = cfalse;
};

} // end of namespace Eq