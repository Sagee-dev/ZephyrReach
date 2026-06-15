#ifndef DIGITALOUT_H
#define DIGITALOUT_H
#include "reachComponent.h"
#include "zephyr/drivers/gpio.h"
#include <zephyr/device.h>

class DigitalOut{
    public:
        DigitalOut(const struct gpio_dt_spec *iPin,const char * iPinName);
        int init();
        int read(int *oStatus) ;
        int write(int *icommand);
        const char *get_pin_name(int *icompNamelen);
    private:
        const struct gpio_dt_spec *mPin;
        const char *mPinName;
        int mPinNameLen =0;
        

};
#endif