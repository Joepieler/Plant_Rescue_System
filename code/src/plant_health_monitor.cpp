#include <plant_health_monitor.hpp>

namespace r2d2::plant_rescue_system {
    plant_health_monitor_c::plant_health_monitor_c(
        base_comm_c &comm, moisture_sensor_c &moisture_sensor,
        hwlib::pin_out &led_green, hwlib::pin_out &led_red)
        : base_module_c(comm),
          moisture_sensor(moisture_sensor),
          led_green(led_green),
          led_red(led_red) {
    }

    void plant_health_monitor_c::process() {
        comm.send(get_value());
        hwlib::wait_ms(1000);
    }

    uint8_t plant_health_monitor_c::get_value() {
        return moisture_sensor.get_value();
    }

    void plant_health_monitor_c::update_led() {
        uint8_t value = get_value();
        if ((ideal_moisture_persentage + max_deviation) >= value &&
            (ideal_moisture_persentage - max_deviation) <= value) {
            led_green.write(1);
            led_red.write(0);
        } else {
            led_green.write(0);
            led_red.write(1);
        }
    }

} // namespace r2d2::plant_rescue_system
