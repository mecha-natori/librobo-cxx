#include "robo/steering.hh"
#include <robo/steering/crawler.hh>

auto Crawler::calc_speed(
    Steering steering,
    std::complex<float> l,
    std::complex<float> r,
    PIDData *pid_data[2]
) -> std::array<std::int16_t, 2> const {
    auto ry = static_cast<float>(steering.max_speed) * -r.imag();
    auto ly = static_cast<float>(steering.max_speed) * l.imag();
    if(pid_data != nullptr) {
        ry = process_pid_data(pid_data[0], ry);
        ly = process_pid_data(pid_data[1], ly);
        auto result = std::array<std::int16_t, 2> {
            static_cast<std::int16_t>(ry),
            static_cast<std::int16_t>(ly)
        };
        return result;
    }
    auto result =
        std::array<std::int16_t, 2> {static_cast<std::int16_t>(ry), static_cast<std::int16_t>(ly)};
    return result;
}
