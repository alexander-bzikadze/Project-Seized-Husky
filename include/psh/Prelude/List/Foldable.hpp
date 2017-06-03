#pragma once

#include "../Foldable.hpp"

template <>
struct mFoldable<List> {
	template <template <typename b, typename a> class Func, typename init, typename list>
	struct foldl;

	template <template <typename b, typename a> class Func, typename init>
	struct foldl<Func, init, List<>> {
		using val = init;
	};

	template <template <typename b, typename a> class Func, typename init, typename f, typename ...a>
	struct foldl<Func, init, List<f, a...>> {
		using val = typename foldl<Func, typename Func<init, f>::val, List<a...>>::val;
	};
};
