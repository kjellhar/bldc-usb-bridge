

#include "ch.h"
#include "hal.h"
#include "usbdevice.h"
#include "bridge_cmd.h"
#include "status_blink.h"

#define USB_TIMEOUT		100
#define POLLING_TIMEOUT	5000

static Mailbox* usbTXMailbox;
static Mailbox* usbRXMailbox;

static VirtualTimer polling_vt;

void disconnect() {
	connected = FALSE;
}


int main(void) {

  //Start System
  halInit();
  chSysInit();

  startUsbControl();
  usbGetMailboxes (&usbRXMailbox, &usbTXMailbox);

  startStatusBlink();

  connected = TRUE;

  msg_t msg;
  usbPacket* usbBufp;
  uint8_t cmd;
  uint32_t retVal;


  while (TRUE) {
    retVal = chMBFetch (usbRXMailbox, &msg, USB_TIMEOUT);

    if (retVal == RDY_OK) {

		usbBufp=(usbPacket*)msg;
		cmd = usbBufp->packet[0];

		switch (cmd) {
		case BR_STATUS:
			connected = TRUE;
			chSysLockFromIsr();
			if (chVTIsArmedI(&polling_vt)) chVTResetI(&polling_vt);

			chVTSetI(&polling_vt, MS2ST(POLLING_TIMEOUT), disconnect, NULL);
			chSysUnlockFromIsr();
			break;

		case BR_USART_TX:
			break;

		default:
			break;
		}
    }
  }
}
