#pragma once

template <typename a, typename b>
struct Pair;

// For tuples of any size use Lists.

template <typename pair>
struct fst;

template <typename a, typename b>
struct fst<Pair<a, b>> {
	using val = a;
};



template <typename pair>
struct snd;

template <typename a, typename b>
struct snd<Pair<a, b>> {
	using val = b;
};



template <template <typename pair> class Func, typename a, typename b>
struct curry {
	using val = typename Func<Pair<a,b>>::val;
};



template <template <typename a, typename b> class Func, typename pair>
struct uncurry;

template <template <typename a1, typename b1> class Func, typename a, typename b>
struct uncurry<Func, Pair<a, b>> {
	using val = typename Func<a, b>::val;
};