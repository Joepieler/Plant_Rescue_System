#include <moisture_sensor.hpp>

namespace r2d2::plant_rescue_system {
    moisture_sensor_c::moisture_sensor_c(hwlib::adc &sensor_pin)
        : sensor_pin(sensor_pin) {
    }

    uint8_t moisture_sensor_c::get_value() {
        return 100 / max_adc_value * sensor_pin.read();
    }
} // namespace r2d2::plant_rescue_system
