#pragma once

#include <array>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <robo/controller.hh>

struct PIDData {
    float kp;
    float ki;
    float kd;
    float prev_e;
    float prev_ie;
    float now_out;
    float t;
};

struct Steering {
    std::int16_t max_speed;
};

template<std::size_t N>
class ISteering {
public:
    virtual ~ISteering() = default;

    virtual auto calc_speed(
        Steering steering,
        std::complex<float> l,
        std::complex<float> r,
        PIDData *pid_data[N] = nullptr
    ) -> std::array<std::int16_t, N> const = 0;

    inline auto
    calc_speed(Steering steering, NormalizedSticks sticks, PIDData *pid_data[N] = nullptr)
        -> std::array<std::int16_t, N> const {
        return calc_speed(
            steering,
            std::complex(sticks.l[0], sticks.l[1]),
            std::complex(sticks.r[0], sticks.r[1]),
            pid_data
        );
    }
};

auto process_pid_data(PIDData *pid_data, float target) -> float;
