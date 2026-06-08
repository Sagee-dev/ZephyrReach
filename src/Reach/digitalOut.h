#ifndef DIGITALOUT_H
#define DIGITALOUT_H
#include "reachComponent.h"
#include "zephyr/drivers/gpio.h"
#include <zephyr/device.h>

class DigitalOut : public ReachComponent{
    public:
        DigitalOut(const struct gpio_dt_spec *iPin);
        int init()override;
        int read(int *oStatus) override;
        int write(int *icommand)override;
    private:
        const struct gpio_dt_spec *mPin;

};
#endif