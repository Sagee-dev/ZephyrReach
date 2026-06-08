#ifndef REACHCOMPONENT_H
#define REACHCOMPONENT_H
#include <stdint.h>
#include <zephyr/device.h>

class ReachComponent{
    public: 
    virtual int init(){return 0;}
    virtual int read(int *oStatus){return 0;}
    virtual int write(int *iCommand){return 0;}
    virtual int process_comand(uint32_t command){return 0;}
};
#endif