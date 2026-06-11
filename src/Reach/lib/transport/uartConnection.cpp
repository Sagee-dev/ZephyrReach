#include "../../transport/uartConnection.h"
#include "zephyr/sys/printk.h"
#include <zephyr/drivers/uart.h>
#include <string.h>
#include <zephyr/kernel.h>



uint8_t uaratRxBuf;
UartConnection::UartConnection(const device *dev)
:mDev(dev){

}

int UartConnection::get_command(char *oBuf, int *oLen){
    int uartComandLen =0;
    while(1){
        if(uart_poll_in(mDev, &uaratRxBuf)==0){
            if (uaratRxBuf == '\r' || uaratRxBuf == '\n'){
                printk("\n");
                break;
            }
            oBuf[uartComandLen++] =uaratRxBuf;
            printk("%c",uaratRxBuf);
        }
    }
    if(uartComandLen>0){
        oBuf[uartComandLen] = '\0';
    }
    *oLen = uartComandLen;
    uartComandLen = 0;
    return 0;
}

int UartConnection::send_response(char *iBuf,int iLen){
    int responseLen = 0;
    while(iLen>responseLen){
        uart_poll_out(mDev,iBuf[responseLen++]);
    }
    responseLen=0;
    return 0;
}