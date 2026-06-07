#include <stdlib.h>
#include <zephyr/kernel.h>
#include "Reach/reachDevice.h"
#include "Reach/transport/uartConnection.h"


const struct device* uart_device;
int main(){
    uart_device = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
    UartConnection uartCon(uart_device);
     
    reachDevice mainDevice(uartCon);

    int counter = 0;
    while(1){
        //printk("system awake %d \n",counter);
        k_msleep(1000);
        counter++;
    }
    return 0;
}