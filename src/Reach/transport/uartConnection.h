#ifndef UARTCONNECTION_H
#define UARTCONNECTION_H

#include "transport.h"
#include <zephyr/drivers/uart.h>
#include <zephyr/device.h>

class UartConnection:public Transport{
    public: UartConnection(const device *iDev);
    int get_command(char *oBuf,int *oLen) override;
    int send_response(char *iBuf,int iLen) override;
    private:
    const device *mDev;

};
#endif