#ifndef REACHDIGITALOUT_H
#define REACHDIGITALOUT_H

#include "digitalOut.h"


class ReachDigitalOut: public ReachComponent{
    public:
        ReachDigitalOut();
        int add_component(DigitalOut *digitalOut);
        DigitalOut *get_component(int index);
        const char * get_component_name(int *compNameLen) override;
        int get_subcomponent_number()override;
    private:
        DigitalOut *digitalOutCollection[32];
        const int reachComponenetId = 1;
        const char *reachComponentName = "Digial Out";
        int digitalOutComponantscount = 0;
};

#endif