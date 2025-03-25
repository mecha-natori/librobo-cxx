#include <cmath>
#include <cstdint>
#include <robo/controller.hh>
#include <robo/math.hh>

auto normalize_sticks(Sticks sticks) -> NormalizedSticks {
    auto lx = static_cast<float>(sticks.l[0]) / INT16_MAX;
    auto ly = static_cast<float>(sticks.l[1]) / INT16_MAX;
    auto lr = std::hypot(lx, ly);
    if(lr <= sticks.dead_zone / 100.0f) {
        lx = 0.0f;
        ly = 0.0f;
    } else if(1.0f < lr) {
        lx /= lr;
        ly /= lr;
    } else {
        lx *= inverse_lerp(sticks.dead_zone / 100.0f, 1.0f, lr) / lr;
        ly *= inverse_lerp(sticks.dead_zone / 100.0f, 1.0f, lr) / lr;
    }
    auto rx = static_cast<float>(sticks.r[0]) / INT16_MAX;
    auto ry = static_cast<float>(sticks.r[1]) / INT16_MAX;
    auto rr = std::hypot(rx, ry);
    if(rr <= sticks.dead_zone / 100.0f) {
        rx = 0.0f;
        ry = 0.0f;
    } else if(1.0f < rr) {
        rx /= rr;
        ry /= rr;
    } else {
        rx *= inverse_lerp(sticks.dead_zone / 100.0f, 1.0f, rr) / rr;
        ry *= inverse_lerp(sticks.dead_zone / 100.0f, 1.0f, rr) / rr;
    }
    auto normalized = NormalizedSticks {.l = {lx, ly}, .r = {rx, ry}};
    return normalized;
}
