#include "reachDevice.h"
#include <zephyr/kernel.h>

#include "transport/transport.h"
#include "reachDigitalOut.h"

#define RX_BUF_MAX 256
#define TX_BUF_MAX 256

#define TRANSPORT_STACK_SIZE 2048
#define TRANSPORT_THREAD_PRIORITY 5
K_THREAD_STACK_DEFINE(transport_stack, TRANSPORT_STACK_SIZE);
static struct k_thread transport_tid;

char rxBuf[RX_BUF_MAX];
char txBuf[TX_BUF_MAX];

int rxComandLen = 0;

reachDevice::reachDevice(Transport &iTransport)
:mTransport(iTransport){
    printk("reach Device created \n");
}

int reachDevice::reachDeviceList(){
    int compNameLen = 0;
    for(int i =0; i<numReachComponent; i++){
        memcpy(txBuf,reachCompotentcollection[i]->get_component_name(&compNameLen),compNameLen);
        txBuf[compNameLen] = '\n';
        send_response(txBuf,compNameLen);
        for(int j = 0; j<reachCompotentcollection[i]->get_subcomponent_number(); j++){
            ReachDigitalOut *rDO = static_cast<ReachDigitalOut *>(reachCompotentcollection[i]);
            DigitalOut *dOut = rDO->get_component(j);
            int comnamelen = 0;
            memcpy(txBuf, dOut->get_pin_name(&comnamelen), comnamelen);
            txBuf[comnamelen] = '\n';
            send_response(txBuf, comnamelen);
            comnamelen = 0;
        }
    }
    return 0;
}

int reachDevice::process_comand(char *cmd,int comandLen){
    printk("Command is %s \n",cmd);
    if((strcmp(cmd,"LIST") == 0 || strcmp(cmd,"list") ==0)){
        //printk("LIST list comand recived\n");
        reachDeviceList();
    }
    return 0;
}
int reachDevice::add_component(ReachComponent *component){
    reachCompotentcollection[numReachComponent++] = component;
    return 0;
}

void reachDevice::get_command(void *p1, void *p2, void *p3){
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);
      reachDevice *self = static_cast<reachDevice *>(p1);
    while(1){
        self->mTransport.get_command(rxBuf,&rxComandLen);
        if(rxComandLen>0){
            self->process_comand(rxBuf,rxComandLen);
        }
    }
    
}

int reachDevice::send_response(char *txBuf, int txLen){
    mTransport.send_response(txBuf,txLen);
    return 0;
}

int reachDevice::send_welcome_prompt(){
    snprintf(txBuf, sizeof(txBuf), "Welocme to Reach Device \n \
    \rcontrol your peripherl over uart \n \
    \rUse Comand LIST to see available periperlas \n\r");
    send_response(txBuf,sizeof(txBuf));
    return 0;
}

int reachDevice::init() {
    
  k_thread_create(&transport_tid, transport_stack,
                  K_THREAD_STACK_SIZEOF(transport_stack),
                  get_command, this, NULL, NULL,
                  TRANSPORT_THREAD_PRIORITY, 0, K_NO_WAIT);
 send_welcome_prompt();   
                  return 0;
}