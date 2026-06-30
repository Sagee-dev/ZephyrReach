#include "../../digitalOut.h"
#include <zephyr/drivers/gpio.h>

DigitalOut::DigitalOut(const struct gpio_dt_spec *iPin,const char *iPinName)
:mPin(iPin),
mPinName(iPinName){
}

int DigitalOut::init(){

    gpio_pin_configure_dt(mPin,GPIO_OUTPUT);
    while(*mPinName != '\0'){
        mPinName++;
        mPinNameLen++;
    }
    mPinName -= mPinNameLen;
    
    return 0;
}

int DigitalOut::read(int *oStatus){
    
    *oStatus = gpio_pin_get_dt(mPin);
    return 0;
}

int DigitalOut::write(int *icommand){
  
    int ret = gpio_pin_set_dt(mPin,*icommand);
    return ret;
}

const char * DigitalOut::get_pin_name(int *iComNameLen){
    *iComNameLen = mPinNameLen;
    return mPinName;
}


