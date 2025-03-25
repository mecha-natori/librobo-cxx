#pragma once

#include <complex>
#include <concepts>

template<std::floating_point T>
struct Polar {
    T r;
    T theta;
};

template<std::floating_point T>
auto approximately_equal(T a, T b) -> bool;

template<std::floating_point T, std::floating_point U>
auto cartesian_to_polar(std::complex<U> cartesian) -> Polar<T>;

template<std::floating_point T>
auto inverse_lerp(T from, T to, T value) -> T;
