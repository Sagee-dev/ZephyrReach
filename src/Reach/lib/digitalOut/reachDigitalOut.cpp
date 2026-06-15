#include"../../reachDigitalOut.h"

ReachDigitalOut::ReachDigitalOut(){}

const char* ReachDigitalOut::get_component_name(int *compNameLen){
    *compNameLen =11;
    return reachComponentName;
}

DigitalOut * ReachDigitalOut::get_component(int index){
    return digitalOutCollection[index];
}

int ReachDigitalOut::add_component(DigitalOut *dpin){
    digitalOutCollection[digitalOutComponantscount++] = dpin;
    return 0;
}

int ReachDigitalOut::get_subcomponent_number(){
    return digitalOutComponantscount;
}