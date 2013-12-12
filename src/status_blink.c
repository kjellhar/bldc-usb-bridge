/*
 * status_blink.c
 *
 *  Created on: Dec 12, 2013
 *      Author: kjell
 */

#include "ch.h"
#include "hal.h"
#include "status_blink.h"

/*
 * This is a periodic thread that does absolutely nothing except flashing LEDs.
 */
static WORKING_AREA(waStatusBlink, 128);
static msg_t statusBlink(void *arg) {
  (void)arg;
  chRegSetThreadName("Status Blinker");

  connected = FALSE;

  while (TRUE) {

	  if (connected) {
			palSetPad(GPIOE, GPIOE_LED3_RED);
			chThdSleepMilliseconds(125);
			palClearPad(GPIOE, GPIOE_LED3_RED);
			palSetPad(GPIOE, GPIOE_LED5_ORANGE);
			chThdSleepMilliseconds(125);
			palClearPad(GPIOE, GPIOE_LED5_ORANGE);
			palSetPad(GPIOE, GPIOE_LED7_GREEN);
			chThdSleepMilliseconds(125);
			palClearPad(GPIOE, GPIOE_LED7_GREEN);
			palSetPad(GPIOE, GPIOE_LED9_BLUE);
			chThdSleepMilliseconds(125);
			palClearPad(GPIOE, GPIOE_LED9_BLUE);
			palSetPad(GPIOE, GPIOE_LED10_RED);
			chThdSleepMilliseconds(125);
			palClearPad(GPIOE, GPIOE_LED10_RED);
			palSetPad(GPIOE, GPIOE_LED8_ORANGE);
			chThdSleepMilliseconds(125);
			palClearPad(GPIOE, GPIOE_LED8_ORANGE);
			palSetPad(GPIOE, GPIOE_LED6_GREEN);
			chThdSleepMilliseconds(125);
			palClearPad(GPIOE, GPIOE_LED6_GREEN);
			palSetPad(GPIOE, GPIOE_LED4_BLUE);
			chThdSleepMilliseconds(125);
			palClearPad(GPIOE, GPIOE_LED4_BLUE);
	  }
	  else {
			palClearPad(GPIOE, GPIOE_LED3_RED);
			palClearPad(GPIOE, GPIOE_LED5_ORANGE);
			palClearPad(GPIOE, GPIOE_LED7_GREEN);
			palClearPad(GPIOE, GPIOE_LED9_BLUE);
			palClearPad(GPIOE, GPIOE_LED10_RED);
			palClearPad(GPIOE, GPIOE_LED8_ORANGE);
			palClearPad(GPIOE, GPIOE_LED6_GREEN);
			palClearPad(GPIOE, GPIOE_LED4_BLUE);

			chThdSleepMilliseconds(250);
			palSetPad(GPIOE, GPIOE_LED3_RED);
			palSetPad(GPIOE, GPIOE_LED5_ORANGE);
			palSetPad(GPIOE, GPIOE_LED7_GREEN);
			palSetPad(GPIOE, GPIOE_LED9_BLUE);
			palSetPad(GPIOE, GPIOE_LED10_RED);
			palSetPad(GPIOE, GPIOE_LED8_ORANGE);
			palSetPad(GPIOE, GPIOE_LED6_GREEN);
			palSetPad(GPIOE, GPIOE_LED4_BLUE);
			chThdSleepMilliseconds(250);

	  }
  }
}

void startStatusBlink(void) {
	chThdCreateStatic(waStatusBlink, sizeof(waStatusBlink), NORMALPRIO, statusBlink, NULL);
}
