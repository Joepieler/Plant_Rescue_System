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

    // create led pins pin 2 and 3.
    auto led_green = hwlib::target::pin_out(hwlib::target::pins::d2);
    auto led_red = hwlib::target::pin_out(hwlib::target::pins::d3);
    auto pump = hwlib::target::pin_out(hwlib::target::pins::d4);

    auto plant = r2d2::plant_rescue_system::plant_health_monitor_c(
        comm, moisture_sensor, led_green, led_red, pump);

    for (;;) {
        plant.process();
        plant.update_led();
        plant.pump_water();
        hwlib::wait_ms(1000);
        hwlib::cout << plant.get_value() << '\n';
    }
}