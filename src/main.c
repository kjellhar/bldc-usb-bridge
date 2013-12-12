

#include "ch.h"
#include "hal.h"
#include "usbdevice.h"
#include "bridge_cmd.h"

static Mailbox* usbTXMailbox;
static Mailbox* usbRXMailbox;


int main(void) {

  //Start System
  halInit();
  chSysInit();

  startUsbControl();
  usbGetMailboxes (&usbRXMailbox, &usbTXMailbox);

  msg_t msg;
  usbPacket* usbBufp;
  uint8_t cmd;
  uint32_t retVal;


  while (TRUE) {
    retVal = chMBFetch (usbRXMailbox, &msg, TIME_INFINITE);

    usbBufp=(usbPacket*)msg;
    cmd = usbBufp->packet[0];

    switch (cmd) {
    case BR_STATUS:
    	break;

    case BR_USART_TX:
    	break;

    default:
    	break;
    }
  }
}
