#ifndef REACHDEVICE_H
#define REACHDEVICE_H

#include "transport/transport.h"
#include "reachComponent.h"

class reachDevice{
    public: reachDevice(Transport &iTransport);
        int add_component(ReachComponent *component);
    private: 
        Transport &mTransport;
        ReachComponent reachCompotentcollection[32];


};
#endif