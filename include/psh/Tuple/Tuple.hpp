#pragma once

template <typename Return_type, typename ...Args>
constexpr auto curry(Return_type (*fun)(std::tuple<Args...>)) {
	struct Curry_helper {
		constexpr Curry_helper(Return_type (*fun)(std::tuple<Args...>)) :
			fun(fun)
		{}
		Return_type (*const fun)(std::tuple<Args...>);

		auto constexpr operator()(Args ...args) const {
			return fun(std::make_tuple(args...));
		}
	} ret(fun);
	return ret;
}

namespace tuple_details {

template <typename Func>
struct Curry_helper {};

template <typename Func, typename Return_type, typename ...Args>
struct Curry_helper<Return_type (Func::*)(std::tuple<Args...>)> {
	constexpr Curry_helper(Func func) :
		func(func)
	{}
	Func const func;

	auto constexpr operator()(Args ...args) const {
		return func(std::make_tuple(args...));
	}
};

template <size_t ...I>
struct I_container;

template <size_t i, typename added>
struct I_container_adder;

template <size_t i, size_t ...I>
struct I_container_adder<i, I_container<I...>> {
	using val = I_container<I..., i>;
};

template <size_t i>
struct I_container_helper {
	using val = typename I_container_adder<i - 1, typename I_container_helper<i - 1>::val>::val;
};

template <>
struct I_container_helper<0> {
	using val = I_container<>;
};

template <typename T, typename U>
struct apply;

template <typename ...Args, size_t ...I>
struct apply<std::tuple<Args...>, I_container<I...>> {
	template <typename Functor>
	constexpr static auto val(Functor fun, std::tuple<Args...> tup) {
		return fun(std::get<I>(tup)...);
	}
};

template <typename>
struct Uncurry_helper;

template <typename Func, typename Return_type, typename ...Args>
struct Uncurry_helper<Return_type (Func::*)(Args...)> {
	constexpr Uncurry_helper(Func func) :
		func(func)
	{}
	Func const func;

	auto constexpr operator()(std::tuple<Args...> tup) const {
		using tuple_type = std::tuple<Args...>;
		return apply<tuple_type, typename I_container_helper<std::tuple_size<tuple_type>::value>::val>::val(func, tup);
	}
};

} // end of namespace tuple_details

template <typename Functor>
constexpr auto curry(Functor func) {
	return tuple_details::Curry_helper<decltype(&Functor::operator())>(func);
}

template <typename Return_type, typename ...Args>
constexpr auto uncurry(Return_type (*fun)(Args...)) {
	struct Uncurry_helper {
		constexpr Uncurry_helper(Return_type (*fun)(Args...)) :
			fun(fun)
		{}
		Return_type (*const fun)(Args...);

		auto constexpr operator()(std::tuple<Args...> tup) const {
			using tuple_type = std::tuple<Args...>;
			return tuple_details::apply<tuple_type, typename tuple_details::I_container_helper<std::tuple_size<tuple_type>::value>::val>::val(fun, tup);
		}
	} ret(fun);
	return ret;
}

template <typename Functor>
constexpr auto uncurry(Functor func) {
	return tuple_details::Uncurry_helper<decltype(&Functor::operator())>(func);;
}
