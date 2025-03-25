#include <robo/steering.hh>

auto process_pid_data(PIDData *pid_data, float target) -> float {
    auto e = target - pid_data->now_out;
    auto de = (e - pid_data->prev_e) / pid_data->t;
    auto ie = pid_data->prev_ie + (e + pid_data->prev_e) * pid_data->t / 2.0f;
    pid_data->prev_e = e;
    pid_data->prev_ie = ie;
    return pid_data->kp * e + pid_data->ki * ie + pid_data->kd * de;
}
