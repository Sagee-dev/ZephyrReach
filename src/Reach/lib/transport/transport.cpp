#include "../../transport/transport.h"
#include "zephyr/sys/printk.h"
#include <zephyr/kernel.h>


Transport::Transport() {}

void Transport::get_command_transport(void *arg1, void *arg2, void *arg3) {
  printk("transport reciver thread is running \n");
  ARG_UNUSED(arg2);
  ARG_UNUSED(arg3);
  Transport *self = static_cast<Transport *>(arg1);
  while (1) {
    self->get_command(self->rxBuf, &self->comandLen);
    if(self->comandLen > 0){
        printk("%s \n",self->rxBuf);
        self->comandLen = 0;
    }
  }
  k_msleep(10);
}


