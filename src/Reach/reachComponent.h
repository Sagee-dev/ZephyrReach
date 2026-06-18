#ifndef REACHCOMPONENT_H
#define REACHCOMPONENT_H
#include <stdint.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>

class ReachComponent{
    public:
        virtual const char * get_component_name(int *comNameLen) 
        {   
            *comNameLen = 2;
            return static_cast<const char *>("NA");
        }

        virtual int get_subcomponent_number(){
            return 0;
        }

        virtual int list_subcomponents(char *subComponentList){
            snprintf(subComponentList,2, static_cast<const char*>("NA"));
            return 2;
        }
        
        virtual int get_instruction(char *instructionBuf){
            snprintf(instructionBuf, 40, "%s \n\r", "use \"component_id write value \"\n\r \
                EX 01 write 1");
            return 40;
        }

        virtual int process_comand(uint8_t subComponent,uint8_t command,uint8_t value){
            return 0;
        }
        inline int getNumOfSubComponents(){
            return numOfSubComponents;
        }
    private:
        int numOfSubComponents = 0;
};
#endif