#include <comm.hpp>
#include <hwlib.hpp>
#include <plant_health_monitor.hpp>

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    auto pin_adc = hwlib::target::pin_adc(hwlib::target::ad_pins::a0);

    // create internal commmunication
    r2d2::comm_c comm;

    auto moisture_sensor =
        r2d2::plant_rescue_system::moisture_sensor_c(pin_adc);

    auto plant =
        r2d2::plant_rescue_system::plant_heath_monitor_c(comm, moisture_sensor);

    for (;;) {
        plant.process();
    }
}