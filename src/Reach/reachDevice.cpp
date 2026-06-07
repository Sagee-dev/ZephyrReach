#include "reachDevice.h"
#include <zephyr/kernel.h>

#include "transport/transport.h"


reachDevice::reachDevice(Transport &iTransport)
:mTransport(iTransport){
    printk("reach Device created");
    mTransport.init();
}