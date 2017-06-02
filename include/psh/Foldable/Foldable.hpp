#pragma once

template <template <typename ...a> class foldable>
struct mFoldable {
	template <template <typename b, typename a> class Func, typename init, typename foldable_inst>
	struct foldl;

	template <template <typename b, typename a> class Func, typename init, typename ...a>
	struct foldl<Func, init, foldable<a...>>;
};

template <template <typename ...a> class foldable>
struct Foldable {
	template <template <typename b, typename a> class Func, typename init, typename foldable_inst>
	struct foldl;

	template <template <typename b, typename a> class Func, typename init, typename ...a>
	struct foldl<Func, init, foldable<a...>> {
		using val = typename mFoldable<foldable>::template foldl<Func, init, foldable<a...>>::val;
	};
};