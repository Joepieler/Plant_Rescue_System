#include <plant_health_monitor.hpp>

namespace r2d2::plant_rescue_system {
    plant_heath_monitor_c::plant_heath_monitor_c(
        base_comm_c &comm, moisture_sensor_c &moisture_sensor)
        : base_module_c(comm), moisture_sensor(moisture_sensor) {
    }

    void plant_heath_monitor_c::process() {
        comm.send(get_value());
        hwlib::wait_ms(1000);
    }

    uint8_t plant_heath_monitor_c::get_value() {
        return moisture_sensor.get_value();
    }

} // namespace r2d2::plant_rescue_system
