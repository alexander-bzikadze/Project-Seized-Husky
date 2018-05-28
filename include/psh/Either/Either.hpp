#pragma once

template <typename T>
struct Left {
	constexpr Left(T value) :
		value(std::move(value))
	{}

	T const value;
};

template<typename T>
auto constexpr make_left(T&& args) {
    return Left<T>(std::forward<T>(args));
}


template <typename T>
struct Right {
	constexpr Right(T value) :
		value(std::move(value))
	{}

	T const value;
};

template<typename T>
auto constexpr make_right(T&& args) {
    return Right<T>(std::forward<T>(args));
}

template <typename A_C, typename B_C, typename A>
constexpr auto either(A_C fun, B_C, Left<A> eigh) {
	return fun(eigh.value);
}

template <typename A_C, typename B_C, typename B>
constexpr auto either(A_C, B_C fun, Right<B> eigh) {
	return fun(eigh.value);
}