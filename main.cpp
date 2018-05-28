#include <iostream>

#include "include/psh.hpp"

using namespace std;

template <typename T, T i>
struct constexpr_checker {
	static constexpr auto value = i;
};

auto maybe_test() {
	auto constexpr x = make_just<int>(1);
	static_assert(constexpr_checker<int, x.value>::value == 1);

	struct maybe_test_helper {
		constexpr maybe_test_helper() {};
		int constexpr operator()(int) {return 0;}
	} constexpr mth;
	static_assert(constexpr_checker<int, maybe(1, mth, x)>::value == 0);

	auto constexpr y = Nothing<int>();
	static_assert(constexpr_checker<int, maybe(1, mth, y)>::value == 1);
}

auto eighter_test() {
	auto constexpr x = make_left(2);
	auto constexpr y = make_right(nullptr);
	static_assert(constexpr_checker<int, x.value>::value == 2);
	static_assert(constexpr_checker<nullptr_t, y.value>::value == nullptr);

	struct left_test_helper {
		constexpr left_test_helper() {};
		auto constexpr operator()(int) {return 1;}
	} constexpr lth;

	struct right_test_helper {
		constexpr right_test_helper() {};
		auto constexpr operator()(nullptr_t) {return nullptr;}
	} constexpr rth;

	static_assert(constexpr_checker<int, either(lth, rth, x)>::value == 1);

	static_assert(constexpr_checker<nullptr_t, either(lth, rth, y)>::value == nullptr);
}

auto constexpr uncurry_helper(int, int, int) {
	return 0;
}

auto constexpr curry_helper(tuple<int, int, int>) {
	return 0;
}

auto tuple_test() {
	static_assert(constexpr_checker<int, uncurry(uncurry_helper)(make_tuple(0,0,0))>::value == 0);
	static_assert(constexpr_checker<int, curry(curry_helper)(0,0,0)>::value == 0);
}

auto list_test() {
	auto constexpr l = make_list({1, 2, 3});
	auto constexpr l1 = make_list(1, 2, 3);
	static_assert(l == l1);
	List<int, 2> constexpr l2(1);
	static_assert(l2 == make_list(1, 1));
	static_assert(l2.push_forward(1) == make_list(1, 1, 1));
	static_assert(l.append(l1) == make_list(1, 2, 3, 1, 2, 3));
	static_assert(l.last() == 3);
	static_assert(l.init() == make_list(1, 2));
	static_assert(get<0>(l.uncons().value) == 1);
	static_assert(l.length() == 3);

	struct list_test_helper {
		constexpr list_test_helper() {}
		auto constexpr operator()(int i) const { return 2 * i; }
	} constexpr lth;
	static_assert(l.map(lth).head() == 2);
	static_assert(l.reverse() == make_list(3, 2, 1));
}

int main()
{
	return 0;
}