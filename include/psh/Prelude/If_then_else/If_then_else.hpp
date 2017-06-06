#pragma once

#include "../Bool.hpp"

template <typename cbool, typename then, typename celse>
struct If_then_else;

template <typename then, typename celse>
struct If_then_else<ctrue, then, celse> {
	using val = then;
};

template <typename then, typename celse>
struct If_then_else<cfalse, then, celse> {
	using val = celse;
};