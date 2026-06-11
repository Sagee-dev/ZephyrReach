#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include "Reach/reachDevice.h"
#include "Reach/transport/uartConnection.h"
#include "Reach/reachDigitalOut.h"
#include "zephyr/drivers/gpio.h"

#define LED_NODE DT_ALIAS(led0)

const struct device* uart_device;
int main(){
    uart_device = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
    UartConnection uartCon(uart_device);
     
    reachDevice mainDevice(uartCon);

    int counter = 0;

    ReachDigitalOut digitalOutComponent;

    static const struct gpio_dt_spec ledb = GPIO_DT_SPEC_GET(LED_NODE,gpios);

    DigitalOut led(&ledb);

    digitalOutComponent.add_component(&led);
    mainDevice.add_component(&digitalOutComponent);

    mainDevice.init();

    while(1){
        //printk("system awake %d \n",counter);
        k_msleep(1000);
        counter++;
    }
    return 0;
}