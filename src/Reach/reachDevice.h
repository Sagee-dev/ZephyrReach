#ifndef REACHDEVICE_H
#define REACHDEVICE_H

#include "transport/transport.h"

class reachDevice{
    public: reachDevice(Transport &iTransport);
    private: 
        Transport &mTransport;

};
#endif