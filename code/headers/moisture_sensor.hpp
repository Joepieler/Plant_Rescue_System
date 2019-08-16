#pragma once

#include <base_module.hpp>
#include <hwlib.hpp>

namespace r2d2::plant_rescue_system {

    /**
     * Class
     */
    class moisture_sensor_c {
        hwlib::adc &sensor_pin;
        constexpr static uint16_t max_value = 3504;
        constexpr static uint16_t min_value = 1791;

    public:
        moisture_sensor_c(hwlib::adc &sensor_pin);

        uint8_t get_value();
    };
} // namespace r2d2::plant_rescue_system