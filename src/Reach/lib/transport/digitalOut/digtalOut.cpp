#include "../../../digitalOut.h"
#include <zephyr/drivers/gpio.h>

DigitalOut::DigitalOut(const struct gpio_dt_spec *iPin)
:mPin(iPin){}

int DigitalOut::init(){

    gpio_pin_configure_dt(mPin,GPIO_OUTPUT);
    return 0;
}

int DigitalOut::read(int *oStatus){
    
    *oStatus = gpio_pin_get_dt(mPin);
    return 0;
}

int DigitalOut::write(int *icommand){

    gpio_pin_set_dt(mPin,*icommand);
    return 0;
}

