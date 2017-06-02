#pragma once

template <template <typename ...a> class functor>
struct mFunctor {
	template <template <typename a> class Func, typename functor_inst>
	struct fmap;

	template <template <typename a> class Func, typename ...a>
	struct fmap<Func, functor<a...>>;
};

template <template <typename ...a> class functor>
struct Functor {
	template <template <typename a> class Func, typename functor_inst>
	struct fmap;

	template <template <typename a> class Func, typename ...a>
	struct fmap<Func, functor<a...>> {
		using val = typename mFunctor<functor>::template fmap<Func, functor<a...>>::val;
	};
};