#pragma once

#include "../Prelude.hpp"

template <typename f, typename s>
struct Pair {
	using first = f;
	using second = s;
};

template <typename ...Args>
struct List;

template <typename H, typename ...Args>
struct List<H, Args...> {
	using Head = H;
	using Tail = List<Args...>;
};



template <typename a, typename list2>
struct conc;

template <typename a, typename ...b>
struct conc<a, List<b...>> {
	using val = List<a, b...>;
};



template <typename list1, typename list2>
struct concat2;

template <typename ...a, typename ...b>
struct concat2<List<a...>, List<b...>> {
	using val = List<a..., b...>;
};



template <typename list>
struct head;

template <typename ...a>
struct head<List<a...>> {
	using val = typename List<a...>::Head;
};



template <typename list>
struct last;

template <typename ...a>
struct last<List<a...>> {
	using val = typename last<typename List<a...>::Tail>::val;
};

template <typename a>
struct last<List<a>> {
	using val = a;
};



template <typename list>
struct tail;

template <typename ...a>
struct tail<List<a...>> {
	using val = typename List<a...>::Tail;
};



template <typename list>
struct init;

template <typename a>
struct init<List<a>> {
	using val = List<>;
};

template <typename h, typename ...a>
struct init<List<h, a...>> {
	using val = typename concat2<List<h>, typename init<List<a...>>::val>::val;
};



template <typename list>
struct uncons;

template <typename ...a>
struct uncons<List<a...>> {
	using val = Just<Pair<typename List<a...>::Head, typename List<a...>::Tail>>;
};



template <typename list>
struct null;

template <>
struct null<List<>> {
	static constexpr bool val = false;
};

template <typename ...a>
struct null<List<a...>> {
	static constexpr bool val = true;
};



template <typename list>
struct length;

template <>
struct length<List<>> {
	static constexpr uint64_t val = 0;
};

template <typename ...a>
struct length<List<a...>> {
	static constexpr uint64_t val = length<typename List<a...>::Tail>::val + 1;
};



template <template <typename a> class Func, typename list>
struct map;

template <template <typename a> class Func, typename ...a>
struct map<Func, List<a...>> {
	using val = List<typename Func<a>::val...>;
};



template <typename list>
struct reverse;

template <>
struct reverse<List<>> {
	using val = List<>;
};

template <typename ...a>
struct reverse<List<a...>> {
	using val = concat2<typename reverse<typename List<a...>::Tail>::val, List<typename List<a...>::Head>>;
};



template <typename a, typename list>
struct intersperse;

template <typename a, typename b>
struct intersperse<a, List<b>> {
	using val = List<b>;
};

template <typename a, typename ...b>
struct intersperse<a, List<b...>> {
	using val = typename concat2<List<typename List<b...>::Head, a>, typename intersperse<a, typename List<b...>::Tail>::val>::val;
};



template <typename list_of_list>
struct transpose;

template <>
struct transpose<List<>> {
	using val = List<>;
};

template <typename ...lists>
struct transpose<List<List<>, lists...>> {
	using val = typename transpose<List<lists...>>::val;
};

template <typename ...lists, typename a, typename ...b>
struct transpose<List<List<a, b...>, lists...>> {
private:
	using xheads = typename conc<a, List<typename lists::Head...>>::val;
	using xstails = typename conc<List<b...>, List<typename lists::Tail...>>::val;
	using trans = typename transpose<xstails>::val;
public:
	using val = typename conc<xheads, trans>::val;
};

