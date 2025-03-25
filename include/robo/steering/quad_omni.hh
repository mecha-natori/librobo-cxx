#pragma once

#include <array>
#include <cstdint>
#include <robo/steering.hh>

class QuadOmni: public ISteering<4> {
public:
    auto calc_speed(
        Steering steering,
        std::complex<float> l,
        std::complex<float> r,
        PIDData *pid_data[4] = nullptr
    ) -> std::array<std::int16_t, 4> const override;
};
