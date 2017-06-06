#pragma once

struct Nothing;

template <typename T>
struct Just
{
	using val = T;
};


// maybe :: b -> (a -> b) -> Maybe a -> b
template <typename b, template <typename a1> class Func, typename m>
struct maybe;

template <typename b, template <typename a1> class Func, typename a>
struct maybe<b, Func, Just<a>>
{
	using val = Just<typename Func<typename Just<a>::val>::val>;
};

template <typename b, template <typename a1> class Func>
struct maybe<b, Func, Nothing>
{
	using val = Just<b>;
};


// isJust :: Maybe a -> Bool
template <typename maybe>
struct isJust;

template <typename a>
struct isJust<Just<a>> {
	static constexpr bool val = true;
};

template <>
struct isJust<Nothing> {
	static constexpr bool val = false;
};


// isNothing :: Maybe a -> Bool
template <typename maybe>
struct isNothing;

template <typename a>
struct isNothing<Just<a>> {
	static constexpr bool val = false;
};

template <>
struct isNothing<Nothing> {
	static constexpr bool val = true;
};


// fromJust :: Maybe a -> a
template <typename maybe>
struct fromJust;

template <typename a>
struct fromJust<Just<a>> {
	using val = a;
};

template <>
struct fromJust<Nothing>;


// fromMaybe :: a -> Maybe a -> a
template <typename a, typename maybe>
struct fromMaybe;

template <typename a, typename b>
struct fromMaybe<a, Just<b>> {
	using val = b;
};

template <typename a>
struct fromMaybe<a, Nothing> {
	using res = a;
};



