#include <numbers>
#include <robo/encoder.hh>

auto get_degree(Encoder encoder) -> double {
    return static_cast<double>(encoder.count) / static_cast<double>(encoder.ppr) / 4.0 * 360.0;
}

auto get_radian(Encoder encoder) -> double {
    return static_cast<double>(encoder.count) / static_cast<double>(encoder.ppr) / 4.0 * 2.0
        * std::numbers::pi_v<double>;
}

auto get_revolution(Encoder encoder) -> std::int64_t {
    return encoder.count / static_cast<std::int64_t>(encoder.ppr) / 4;
}

auto update(Encoder encoder, std::int64_t delta) -> Encoder {
    auto count = encoder.count + delta;
    return Encoder { .ppr = encoder.ppr, .count = count };
}
