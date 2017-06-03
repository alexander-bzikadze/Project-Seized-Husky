#pragma once

template <typename T>
struct Left {
	using val = T;
};

template <typename T>
struct Right {
	using val = T;
};

template <template <typename a> class fa, template <typename b> class fb, typename eighter>
struct either;

template <template <typename a> class fa, template <typename b> class fb, typename a>
struct either<fa, fb, Left<a>> {
	using val = typename fa<a>::val;
};

template <template <typename a> class fa, template <typename b> class fb, typename b>
struct either<fa, fb, Right<b>> {
	using val = typename fb<b>::val;
};