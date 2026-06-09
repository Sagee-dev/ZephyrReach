#ifndef DIGITALOUT_H
#define DIGITALOUT_H
#include "reachComponent.h"
#include "zephyr/drivers/gpio.h"
#include <zephyr/device.h>

class DigitalOut{
    public:
        DigitalOut(const struct gpio_dt_spec *iPin);
        int init();
        int read(int *oStatus) ;
        int write(int *icommand);
    private:
        const struct gpio_dt_spec *mPin;
        

};
#endif