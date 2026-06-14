#include"../../reachDigitalOut.h"

ReachDigitalOut::ReachDigitalOut(){}

const char* ReachDigitalOut::get_component_name(int *compNameLen){
    *compNameLen =11;
    return static_cast<const char *>("DIGITAL OUT");
}

int ReachDigitalOut::add_component(DigitalOut *dpin){
    return 0;
}