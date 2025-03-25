#pragma once

#include <cstdint>

struct Encoder {
    std::uint16_t ppr;
    std::int64_t count;
};

auto get_degree(Encoder encoder) -> double;
auto get_radian(Encoder encoder) -> double;
auto get_revolution(Encoder encoder) -> std::int64_t;
auto update(Encoder encoder, std::int64_t delta) -> Encoder;
