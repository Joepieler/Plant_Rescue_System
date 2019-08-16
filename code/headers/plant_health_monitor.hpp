#pragma once

#include <base_module.hpp>
#include <hwlib.hpp>
#include <moisture_sensor.hpp>

namespace r2d2::plant_rescue_system {

    /**
     * Class
     */
    class plant_heath_monitor_c : public base_module_c {

    private:
        moisture_sensor_c &moisture_sensor;
        uint8_t moisture_percentage;

    public:
        plant_heath_monitor_c(base_comm_c &comm,
                              moisture_sensor_c &moisture_sensor);
    };
} // namespace r2d2::plant_rescue_system