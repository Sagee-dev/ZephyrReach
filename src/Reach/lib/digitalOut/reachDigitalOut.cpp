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

int ReachDigitalOut::list_subcomponents(char *subComponentList){
    char list[256];
    int subComponentNameLen = 0;
    int subComponentListLen = 0;
    for(int i=0; i<get_subcomponent_number(); i++){
        const char *subComponentName = digitalOutCollection[i]->get_pin_name(&subComponentNameLen);
        subComponentNameLen += 3;
        snprintf(list+subComponentListLen, 100, "%s \n\r",subComponentName);
        subComponentListLen += subComponentNameLen;
    }
    strcpy(subComponentList, list);
    return subComponentListLen;
}

int ReachDigitalOut::process_comand(uint8_t subComponent,uint8_t command,uint8_t value){
    return 0;
}

int ReachDigitalOut::get_instruction(char *instructionBuf){
    snprintf(instructionBuf, 55, "%s \n\r", "use \"component_id write value \"\n\r \
    EX 01 write 1");
    return 54;
    }