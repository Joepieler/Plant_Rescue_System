#include <plant_health_monitor.hpp>

namespace r2d2::plant_rescue_system {
    plant_heath_monitor_c::plant_heath_monitor_c(
        base_comm_c &comm, moisture_sensor_c &moisture_sensor)
        : base_module_c(comm), moisture_sensor(moisture_sensor) {
    }

} // namespace r2d2::plant_rescue_system
