#include <plant_health_monitor.hpp>

namespace r2d2::plant_rescue_system {
    plant_health_monitor_c::plant_health_monitor_c(
        base_comm_c &comm, moisture_sensor_c &moisture_sensor,
        hwlib::pin_out &led_green, hwlib::pin_out &led_red,
        hwlib::pin_out &pump)
        : base_module_c(comm),
          moisture_sensor(moisture_sensor),
          led_green(led_green),
          led_red(led_red),
          pump(pump) {
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

    void plant_health_monitor_c::pump_water() {
        if ((ideal_moisture_persentage - max_deviation) > get_value()) {
            // * 1000 is liters to mililiters and 2 to go from minimum diviation
            // max divation
            uint32_t water_to_pump_in_mililiters =
                size_pot_in_liters * 1000 * (max_deviation * 2) / 100;
            // * 1000 is second to miliseconds
            uint32_t pump_duration =
                (water_to_pump_in_mililiters / pump_mililiter_per_second) *
                1000;
            // pump on for duration
            pump.write(1);
            hwlib::wait_ms(pump_duration);
            pump.write(0);
        }
    }

} // namespace r2d2::plant_rescue_system
