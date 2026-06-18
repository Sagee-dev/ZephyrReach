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
        int list_subcomponents(char *subComponentList)override;
        int get_instruction(char *instructionBuf)override;
        int process_comand(uint8_t subComponent,uint8_t command,uint8_t value)override;
    private:
        DigitalOut *digitalOutCollection[32];
        const int reachComponenetId = 1;
        const char *reachComponentName = "Digial Out";
        int digitalOutComponantscount = 0;
};

#endif