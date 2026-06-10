#include "reachDevice.h"
#include <zephyr/kernel.h>

#include "transport/transport.h"

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
    printk("reach Device created");
}

int reachDevice::process_comand(char *cmd,int comandLen){
    printk("Command iss %s \n",cmd);
    return 0;
}
int reachDevice::add_component(ReachComponent *component){
    return 0;
}

void reachDevice::get_command(void *p1, void *p2, void *p3){
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);
    while(1){
        mTransport.get_command(rxBuf,&rxComandLen );
        if(rxComandLen>0){
            process_comand(rxBuf,rxComandLen);
        }
    }
    
}

int reachDevice::init() {
  k_thread_create(&transport_tid, transport_stack,
                  K_THREAD_STACK_SIZEOF(transport_stack),
                  Transport::get_command_transport, this, NULL, NULL,
                  TRANSPORT_THREAD_PRIORITY, 0, K_NO_WAIT);
    return 0;
}