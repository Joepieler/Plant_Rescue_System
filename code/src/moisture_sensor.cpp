#include <moisture_sensor.hpp>

namespace r2d2::plant_rescue_system {
    moisture_sensor_c::moisture_sensor_c(hwlib::adc &sensor_pin)
        : sensor_pin(sensor_pin) {
    }

    uint8_t moisture_sensor_c::get_value() {
        // calculation from a adc to a persentage.
        // 0 is dry and 100 is wet.
        uint16_t value = sensor_pin.read() - min_value;
        value = 100 * value / (max_value - min_value);
        value = 100 - value;
        return value;
    }
} // namespace r2d2::plant_rescue_system
