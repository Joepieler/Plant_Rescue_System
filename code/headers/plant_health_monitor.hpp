#pragma once

#include <base_module.hpp>
#include <hwlib.hpp>
#include <moisture_sensor.hpp>

namespace r2d2::plant_rescue_system {

    /**
     * Class plant_health_monitor_c is Association from moisture sensor.
     * differend sensor can be implemented in this class to get a clear status
     * of the health of a plant.
     */
    class plant_health_monitor_c : public base_module_c {

    private:
        // plant values
        constexpr static uint8_t ideal_moisture_persentage = 35;
        constexpr static uint8_t max_deviation = 10;

        // moisture sensor
        moisture_sensor_c moisture_sensor;

        // leds for ledstatus
        hwlib::pin_out &led_green;
        hwlib::pin_out &led_red;

        // canbus frame
        frame_plant_health_s moisture_percentage;

    public:
        plant_health_monitor_c(base_comm_c &comm,
                               moisture_sensor_c &moisture_sensor,
                               hwlib::pin_out &led_green,
                               hwlib::pin_out &led_red);

        /**
         * @brief
         * This main fucntion of this class.
         */
        void process() override;

        /**
         * This function will call the get_value function of the moisture
         * sensor. it return a value in persentage.
         */
        uint8_t get_value();

        /**
         * updates status leds
         *
         */
        void update_led();
    };
} // namespace r2d2::plant_rescue_system