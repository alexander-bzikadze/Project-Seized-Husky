#pragma once

template <int T>
struct Ordering {
	static_assert(T <= 1 && T >= -1, "Only three instances of Ordering are allowed.");
};

constexpr Ordering<-1> LT;
constexpr Ordering<0> EQ;
constexpr Ordering<1> GT;