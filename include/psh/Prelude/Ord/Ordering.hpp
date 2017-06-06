#pragma once

#include "Ord.hpp"

namespace Ord {

template <>
struct Leq<GT, GT> {
	using val = ctrue;
};

template <>
struct Leq<EQ, GT> {
	using val = ctrue;
};

template <>
struct Leq<LT, GT> {
	using val = ctrue;
};

template <>
struct Leq<GT, EQ> {
	using val = cfalse;
};

template <>
struct Leq<EQ, EQ> {
	using val = ctrue;
};

template <>
struct Leq<LT, EQ> {
	using val = ctrue;
};

template <>
struct Leq<GT, LT> {
	using val = cfalse;
};

template <>
struct Leq<EQ, LT> {
	using val = cfalse;
};

template <>
struct Leq<LT, LT> {
	using val = ctrue;
};

} // end of namespace Ord