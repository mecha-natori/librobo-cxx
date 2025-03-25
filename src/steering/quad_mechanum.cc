#include <cmath>
#include <numbers>
#include <robo/math.hh>
#include <robo/steering.hh>
#include <robo/steering/quad_mechanum.hh>

auto QuadMechanum::calc_speed(
    Steering steering,
    std::complex<float> l,
    std::complex<float> r,
    PIDData *pid_data[4]
) -> std::array<std::int16_t, 4> const {
    auto l_polar = cartesian_to_polar<float>(l);
    auto r_polar = cartesian_to_polar<float>(r);
    auto fr = static_cast<float>(steering.max_speed) * r_polar.r
        * std::cos(std::numbers::pi_v<float> / 4.0f + r_polar.theta);
    auto fl = static_cast<float>(steering.max_speed) * l_polar.r
        * std::cos(std::numbers::pi_v<float> / 4.0f - l_polar.theta);
    auto rl = static_cast<float>(steering.max_speed) * l_polar.r
        * std::cos(3.0f * std::numbers::pi_v<float> / 4.0f - l_polar.theta);
    auto rr = static_cast<float>(steering.max_speed) * r_polar.r
        * std::cos(3.0f * std::numbers::pi_v<float> / 4.0f + r_polar.theta);
    if(pid_data != nullptr) {
        fr = process_pid_data(pid_data[0], fr);
        fl = process_pid_data(pid_data[1], fl);
        rl = process_pid_data(pid_data[2], rl);
        rr = process_pid_data(pid_data[3], rr);
        auto result = std::array<std::int16_t, 4> {
            static_cast<std::int16_t>(fr),
            static_cast<std::int16_t>(fl),
            static_cast<std::int16_t>(rl),
            static_cast<std::int16_t>(rr)
        };
        return result;
    }
    auto result = std::array<std::int16_t, 4> {
        static_cast<std::int16_t>(fr),
        static_cast<std::int16_t>(fl),
        static_cast<std::int16_t>(rl),
        static_cast<std::int16_t>(rr)
    };
    return result;
}
