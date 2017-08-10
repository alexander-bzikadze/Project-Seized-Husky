#pragma once

template <typename T>
struct Maybe;

template <typename T>
struct Nothing : public Maybe<T> {};

template <typename T, T v>
struct Just : public Maybe<T> {
	constexpr static T val = v;
};