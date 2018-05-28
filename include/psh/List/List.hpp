#pragma once

#include "../Maybe.hpp"

template <typename T, size_t N = 0> struct List;

template <typename T, size_t N>
auto constexpr last(List<T, N> const& list) {
	return last(list.tail());
}

template <typename T>
T constexpr last(List<T, 1> const& list) {
	return list.head();
}

template <typename T, size_t N>
auto constexpr init(List<T, N> const& list) {
	return init(list.tail()).push_forward(list.head());
}

namespace list_details {
	template <typename T, size_t N>
	auto constexpr last_helper(List<T, N> const& list) {
		return last(list);
	}

	template <typename T, size_t N>
	auto constexpr init_helper(List<T, N> const& list) {
		return init(list);
	}

	template <typename T1, size_t N, typename T2>
	auto constexpr rev(List<T1, 0> const& list1, List<T2, N> const& list2) {
		return list2;
	}

	template <typename T1, size_t N1, typename T2, size_t N2>
	auto constexpr rev(List<T1, N1> const& list1, List<T2, N2> const& list2) {
		return rev(list1.tail(), list2.push_forward(list1.head()));
	}
}

template <typename T, size_t N>
struct List {
	constexpr List(T value, List<T, N - 1> _tail) :
		value(std::move(value)),
		_tail(std::move(_tail))
	{}
	constexpr List(const T(&ar)[N]) :
		value(ar[0]),
		_tail(from_array(ar))
	{}
	template <typename ...U>
	constexpr List(T value, U ..._tail) :
		value(value),
		_tail(_tail...)
	{}
	constexpr explicit List(const T& value) :
		value(value),
		_tail(value)
	{}

	constexpr List(List const& copied) = default;

	auto constexpr push_forward(T value) const {
		return List<T, N + 1>(std::move(value), *this);
	}

	auto constexpr head() const {
		return value;
	}

	template <typename T1, size_t N1> 
	auto constexpr append(List<T1, N1> const& list) const {
		return List<T1, N + N1>(head(), _tail.append(list));
	}

	auto constexpr tail() const {
		return _tail;
	}

	auto constexpr last() const {
		return list_details::last_helper(*this);
	}

	auto constexpr init() const {
		return list_details::init_helper(*this);
	}

	auto constexpr uncons() const {
		using tuple_type = std::tuple<T, List<T, N - 1>>;
		return make_just<tuple_type>(value, _tail);
	}

	auto constexpr null() const {
		return false;
	}

	auto constexpr length() const {
		return N;
	}

	template <typename Func>
	auto constexpr map(Func func) const {
		return List<typename std::result_of<Func(T)>::type, N>(func(value), _tail.map(func)); 
	}

	auto constexpr reverse() const {
		return list_details::rev(*this, List<T, 0>());
	}

public:
	T const value;
	List<T, N - 1> const _tail;
private:

	template <size_t i = 1>
	auto constexpr static from_array(const T(&ar)[N]) {
		if constexpr (N != i)
			return List<T, N - i>(ar[i], from_array<i + 1>(ar));
		else
			return List<T>();
	}
};

template <typename T, size_t N>
auto constexpr make_list(const T(&ar)[N]) {
	return List<T, N>(std::move(ar));
}

template <typename T, typename ...U>
auto constexpr make_list(T value, U ...values) {
	return List<T, 1 + sizeof...(U)>(std::move(value), std::move(values)...);
}

template <typename T>
struct List<T, 0> {
	constexpr List() = default;
	constexpr List(List const&) = default;
	constexpr List(List&&) = default;
	constexpr List(const T& value) {};

	template <typename T1, size_t N1> 
	auto constexpr append(List<T1, N1> const& list) const {
		return list;
	}

	auto constexpr push_forward(T value) const {
		return List<T, 1>(std::move(value), *this);
	}

	auto constexpr uncons() const {
		using tuple_type = std::tuple<T, List<T>>;
		return Nothing<tuple_type>();
	}

	auto constexpr null() const {
		return true;
	}

	auto constexpr length() const {
		return 0;
	}

	template <typename Func>
	auto constexpr map(Func) const {
		return List<T, 0>();
	}

	auto constexpr reverse() const {
		return *this;
	}
};

template <typename T>
auto constexpr make_list() {
	return List<T>();
}

template <typename T, size_t N>
auto constexpr push_forward(T value, List<T, N> const& list) {
	return list.push_forward(std::move(value));
}

template <typename T, size_t N>
auto constexpr head(List<T, N> const& list) {
	return list.head();
}

template <typename T1, typename T2, size_t N1, size_t N2> 
auto constexpr append(List<T1, N1> const& list1, List<T2, N2> const& list2) {
	return list1.append(list2);
}


template <typename T, size_t N>
auto constexpr tail(List<T, N> const& list) {
	return list.tail();
}

template <typename T>
auto constexpr init(List<T, 1> const& list) {
	return make_list<T>();
}

template <typename T, size_t N>
auto constexpr uncons(List<T, N> const& list) {
	return list.uncons();
}

template <typename T, size_t N>
auto constexpr null(List<T, N> const& list) {
	return list.null();
}

template <typename T, size_t N>
auto constexpr length(List<T, N> const& list) {
	return list.lenght();
}

template <typename T1, typename T2, size_t N>
auto constexpr operator==(List<T1, N> const& list1, List<T2, N> const& list2) {
	return list1.head() == list2.head() && list1.tail() == list2.tail();
}

template <typename T1, typename T2, size_t N1, size_t N2>
auto constexpr operator==(List<T1, N1> const& list1, List<T2, N2> const& list2) {
	return false;
}

template <typename T1, typename T2>
auto constexpr operator==(List<T1, 0> const& list1, List<T2, 0> const& list2) {
	return true;
}

template <typename T, size_t N, typename Func>
auto constexpr map(List<T, N> const& list, Func func) {
	return list.map(func);
}

template <typename T, size_t N>
auto constexpr reverse(List<T, N> const& list) {
	return list.reverse();
}

