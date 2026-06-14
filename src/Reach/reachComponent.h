#ifndef REACHCOMPONENT_H
#define REACHCOMPONENT_H
#include <stdint.h>
#include <zephyr/device.h>

class ReachComponent{
    public:
        virtual const char * get_component_name(int *comNameLen) 
        {   
            *comNameLen = 2;
            return static_cast<const char *>("NA");
        }
};
#endif