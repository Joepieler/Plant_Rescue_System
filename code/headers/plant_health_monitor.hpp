#pragma once

#include <base_module.hpp>
#include <hwlib.hpp>
#include <moisture_sensor.hpp>

namespace r2d2::plant_rescue_system {

    /**
     * Class plant_health_monitor_c is Association from moisture sensor.
     * different sensor can be implemented in this class to get a clear status
     * of the health of a plant.
     */
    class plant_health_monitor_c : public base_module_c {

    private:
        // plant values
        constexpr static uint8_t ideal_moisture_persentage = 35;
        constexpr static uint8_t max_deviation = 10;
        constexpr static uint8_t size_pot_in_liters = 4;
        constexpr static uint8_t pump_mililiter_per_second = 16;

        // moisture sensor
        moisture_sensor_c moisture_sensor;

        // leds for ledstatus
        hwlib::pin_out &led_green;
        hwlib::pin_out &led_red;
        hwlib::pin_out &pump;

        // canbus frame
        frame_plant_health_s moisture_percentage;

    public:
        plant_health_monitor_c(base_comm_c &comm,
                               moisture_sensor_c &moisture_sensor,
                               hwlib::pin_out &led_green,
                               hwlib::pin_out &led_red, hwlib::pin_out &pump);

        /**
         * @brief
         * This main function of this class.
         */
        void process() override;

        /**
         * This function will call the get_value function of the moisture
         * sensor. it returns a value in percentage.
         */
        uint8_t get_value();

        /**
         * updates status leds
         * green led the plant has enough water
         * red led the plant had to les or too much water
         *
         */
        void update_led();

        /**
         * pumps water to the plant
         * the target is to go from ideal_moisture_persentage -
         * max_max_deviation to ideal_moisture_persentage + max_deviation
         */
        void pump_water();
    };
} // namespace r2d2::plant_rescue_system