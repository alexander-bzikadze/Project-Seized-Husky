#pragma once

#include "../Eq.hpp"
#include "../If_then_else.hpp"

namespace Ord {

template <typename ord_1, typename ord_2>
struct compare;
template <typename ord_1, typename ord_2>
struct Leq;

template <typename ord_1, typename ord_2>
struct compare {
private:
	using if_eq = EQ;
	using if_neq = typename If_then_else<typename Leq<ord_1, ord_2>::val, LT, GT>::val;
public:
	using val = typename If_then_else<typename Eq::equals<ord_1, ord_2>::val, if_eq, if_neq>::val;
};

template <typename ord_1, typename ord_2>
struct Leq {
private:
	using comparison = typename compare<ord_1, ord_2>::val;
public:
	using val = typename cor<typename Eq::equals<comparison, EQ>::val, typename Eq::equals<comparison, LT>::val>::val;
};

template <typename ord_1, typename ord_2>
struct Lt {
	using val = typename Eq::equals<typename compare<ord_1, ord_2>::val, LT>::val;
};

template <typename ord_1, typename ord_2>
struct Gt {
	using val = typename Eq::equals<typename compare<ord_1, ord_2>::val, GT>::val;
};

template <typename ord_1, typename ord_2>
struct Geq {
	using val = typename cnot<typename Lt<ord_1, ord_2>::val>::val;
};

template <typename ord_1, typename ord_2>
struct max {
	using val = typename If_then_else<typename Gt<ord_1, ord_2>::val, ord_1, ord_2>::val;
};

template <typename ord_1, typename ord_2>
struct min {
	using val = typename If_then_else<typename Lt<ord_1, ord_2>::val, ord_1, ord_2>::val;
};

}
