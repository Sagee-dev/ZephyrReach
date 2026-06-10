#ifndef REACHDEVICE_H
#define REACHDEVICE_H

#include "transport/transport.h"
#include "reachComponent.h"

class reachDevice{
    public: reachDevice(Transport &iTransport);
        int add_component(ReachComponent *component);
        int process_comand(char *cmd,int comandLen);
        int init();
        void get_command(void *p1, void *p2, void *p3);
    private: 
        Transport &mTransport;
        ReachComponent reachCompotentcollection[32];



};
#endif