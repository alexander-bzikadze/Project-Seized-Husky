#pragma once

template <bool v>
struct cbool {
	constexpr bool static val = v;
};

using ctrue = cbool<true>;
using cfalse = cbool<false>;

template <typename cb1, typename cb2>
struct cand;

template <bool a, bool b>
struct cand<cbool<a>, cbool<b>> {
	using val = cbool<a && b>;
};

template <typename cb1, typename cb2>
struct cor;

template <bool a, bool b>
struct cor<cbool<a>, cbool<b>> {
	using val = cbool<a || b>;
};

template <typename cb>
struct cnot;

template <bool a>
struct cnot<cbool<a>> {
	using val = cbool<!a>;
};

using otherwise = ctrue;