#pragma once

#include <cstdint>

struct Servo {
    std::uint16_t min_ms;
    std::uint16_t max_ms;
    std::int16_t min_deg;
    std::int16_t max_deg;
};

auto calc_servo_duty(Servo servo, std::uint16_t max_duty, std::int16_t deg) -> std::uint16_t;
