#pragma once

#include <base_module.hpp>
#include <hwlib.hpp>

namespace r2d2::plant_rescue_system {

    /**
     * Class
     */
    class moisture_sensor_c {
        hwlib::adc &sensor_pin;
        constexpr static uint8_t adc_voltage = 3;
        constexpr static uint16_t max_adc_value = 4096 / 5 * adc_voltage;

    public:
        moisture_sensor_c(hwlib::adc &sensor_pin);

        uint8_t get_value();
    };
} // namespace r2d2::plant_rescue_system