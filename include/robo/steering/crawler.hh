#pragma once

#include <array>
#include <cstdint>
#include <robo/steering.hh>

class Crawler: public ISteering<2> {
public:
    auto calc_speed(
        Steering steering,
        std::complex<float> l,
        std::complex<float> r,
        PIDData *pid_data[2] = nullptr
    ) -> std::array<std::int16_t, 2> const override;
};
