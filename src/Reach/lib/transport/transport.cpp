#include "../../transport/transport.h"
#include "zephyr/sys/printk.h"
#include <zephyr/kernel.h>

#define TRANSPORT_STACK_SIZE 2048
#define TRANSPORT_THREAD_PRIORITY 5
K_THREAD_STACK_DEFINE(transport_stack, TRANSPORT_STACK_SIZE);
static struct k_thread transport_tid;

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

void Transport::init() {
  k_thread_create(&transport_tid, transport_stack,
                  K_THREAD_STACK_SIZEOF(transport_stack),
                  Transport::get_command_transport, this, NULL, NULL,
                  TRANSPORT_THREAD_PRIORITY, 0, K_NO_WAIT);
}
