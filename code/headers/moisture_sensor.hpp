#pragma once

#include <base_module.hpp>
#include <hwlib.hpp>

namespace r2d2::plant_rescue_system {

    /**
     * Class for the moisture sensor
     * https://nl.aliexpress.com/item/32886868425.html.
     */
    class moisture_sensor_c {
        // Aanlog pin for the sensor
        hwlib::adc &sensor_pin;
        // The max value that the sensor can return in water.  The values are
        // checked with a 10 bit adc of the arduino due.
        constexpr static uint16_t max_value = 3504;
        // The lowest value the sensor can return when it is dry.  The values
        // are checked with a 10 bit adc of the arduino due.
        constexpr static uint16_t min_value = 1791;

    public:
        moisture_sensor_c(hwlib::adc &sensor_pin);

        /**
         * This function will return a value of the moisture percentage in the
         *soil. 0 is dry and 100 is wet.
         *
         **/
        uint8_t get_value();
    };
} // namespace r2d2::plant_rescue_system