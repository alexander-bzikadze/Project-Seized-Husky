#pragma once
#include "List.hpp"
#include "../Functor.hpp"

template <>
struct mFunctor<List> {
	template <template <typename a> class Func, typename list>
	struct fmap;

	template <template <typename a> class Func, typename ...a>
	struct fmap<Func, List<a...>> {
		using val = typename map<Func, List<a...>>::val;
	};
};
