#include <robo/servo.hh>

auto calc_servo_duty(Servo servo, std::uint16_t max_duty, std::int16_t deg) -> std::uint16_t {
    return static_cast<std::uint16_t>((deg - servo.min_deg) / (servo.max_deg - servo.min_deg))
        * (servo.max_ms - servo.min_ms)
        + servo.min_ms;
}
