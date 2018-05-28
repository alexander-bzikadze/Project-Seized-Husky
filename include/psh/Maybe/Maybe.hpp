#pragma once

template <typename T>
struct Just {
	template <typename ...Args>
	constexpr Just(Args&&... value) :
		value(std::move(value)...)
	{}

	T const value;
};

template<typename T, typename ...Args>
auto constexpr make_just(Args&&... args) {
    return Just<T>(std::forward<Args>(args)...);
}

template <typename T>
struct Nothing {
	constexpr Nothing()
	{}
};

template <typename B, typename A_B, typename A>
constexpr auto maybe(B, A_B fun, Just<A> may) {
	return fun(may.value);
}

template <typename B, typename A_B, typename A>
constexpr auto maybe(B b, A_B, Nothing<A>) {
	return b;
}