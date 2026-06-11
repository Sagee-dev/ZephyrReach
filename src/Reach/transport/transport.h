#ifndef TRANSPORT_H
#define TRANSPORT_H

#define RX_BUF_MAX 128
#define TX_BUF_MAX 128

class Transport {
public:
  Transport();
  void get_command_transport(void *arg1, void *arg2, void *arg3);
  int send_response_transport();
 
  virtual int get_command(char *oBuf, int *olen) { return 0; }
  virtual int send_response(char *iBuf, int iLen) { return 0; }

private:
  char rxBuf[RX_BUF_MAX];
  char txBuf[TX_BUF_MAX];
  int comandLen = 0;
};
#endif