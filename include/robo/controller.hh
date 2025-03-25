#pragma once

#include <cstdint>

struct Sticks {
    std::int16_t l[2];
    std::int16_t r[2];
    std::uint8_t dead_zone;
};

struct NormalizedSticks {
    float l[2];
    float r[2];
};

auto normalize_sticks(Sticks sticks) -> NormalizedSticks;
