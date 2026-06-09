#ifndef REACHDIGITALOUT_H
#define REACHDIGITALOUT_H

#include "digitalOut.h"
#include "reachDigitalOut.h"

class ReachDigitalOut: public ReachComponent{
    public:
        ReachDigitalOut();
        int add_component(DigitalOut *digitalOut);
    private:
        DigitalOut digitalOutCollection[32];
        const int reachComponenetId = 1;
        const char *reachComponentName = "Digial Output";
};

#endif