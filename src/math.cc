#include <cmath>
#include <limits>
#include <robo/math.hh>

template<std::floating_point T>
auto approximately_equal(T a, T b) -> bool {
    return std::abs(a - b) < std::numeric_limits<T>::epsilon();
}

template<std::floating_point T, std::floating_point U>
auto cartesian_to_polar(std::complex<U> cartesian) -> Polar<T> {
    auto r = std::hypot(cartesian.real(), cartesian.imag());
    auto theta = std::atan2(cartesian.imag(), cartesian.real());
    return Polar {.r = static_cast<T>(r), .theta = static_cast<T>(theta)};
}

template<std::floating_point T>
auto inverse_lerp(T from, T to, T value) -> T {
    return (value - from) / (to - from);
}
