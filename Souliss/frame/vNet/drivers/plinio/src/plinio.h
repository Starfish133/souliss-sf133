#ifndef BFSKMODEM_H
#define BFSKMODEM_H

#include <Print.h>
#include <inttypes.h>

//#define BFSK_MODEM_BAUD_RATE   (126)
//#define BFSK_MODEM_LOW_FREQ    (882)
//#define BFSK_MODEM_HIGH_FREQ   (1764)
//#define BFSK_MODEM_MAX_RX_BUFF (4)

//#define BFSK_MODEM_BAUD_RATE   (100)
//#define BFSK_MODEM_LOW_FREQ    (800)
//#define BFSK_MODEM_HIGH_FREQ   (1600)
//#define BFSK_MODEM_MAX_RX_BUFF (4)

// #define BFSK_MODEM_BAUD_RATE   (315)
// #define BFSK_MODEM_LOW_FREQ    (1575)
// #define BFSK_MODEM_HIGH_FREQ   (3150)
// #define BFSK_MODEM_MAX_RX_BUFF (8)

// #define BFSK_MODEM_BAUD_RATE   (630)
// #define BFSK_MODEM_LOW_FREQ    (3150)
// #define BFSK_MODEM_HIGH_FREQ   (6300)
// #define BFSK_MODEM_MAX_RX_BUFF (16)

//#define BFSK_MODEM_BAUD_RATE   (600)
//#define BFSK_MODEM_LOW_FREQ    (2666)
//#define BFSK_MODEM_HIGH_FREQ   (4000)
//#define BFSK_MODEM_MAX_RX_BUFF (16)

#define BFSK_MODEM_BAUD_RATE   (1225)
#define BFSK_MODEM_LOW_FREQ    (4900)
#define BFSK_MODEM_HIGH_FREQ   (7350)
#define BFSK_MODEM_MAX_RX_BUFF (100)

//#define BFSK_MODEM_BAUD_RATE   (2450)
//#define BFSK_MODEM_LOW_FREQ    (7350)
//#define BFSK_MODEM_HIGH_FREQ   (14700)
//#define BFSK_MODEM_MAX_RX_BUFF (32)

#if F_CPU == 16000000
#if BFSK_MODEM_BAUD_RATE <= 126
  #define TIMER_CLOCK_SELECT       (7)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(1024))
#elif BFSK_MODEM_BAUD_RATE <= 315
  #define TIMER_CLOCK_SELECT       (6)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(256))
#elif BFSK_MODEM_BAUD_RATE <= 630
  #define TIMER_CLOCK_SELECT       (5)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(128))
#elif BFSK_MODEM_BAUD_RATE <= 1225
  #define TIMER_CLOCK_SELECT       (4)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(64))
#else
  #define TIMER_CLOCK_SELECT       (3)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(32))
#endif
#else
#if BFSK_MODEM_BAUD_RATE <= 126
  #define TIMER_CLOCK_SELECT       (6)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(256))
#elif BFSK_MODEM_BAUD_RATE <= 315
  #define TIMER_CLOCK_SELECT       (5)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(128))
#elif BFSK_MODEM_BAUD_RATE <= 630
  #define TIMER_CLOCK_SELECT       (4)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(64))
#else
  #define TIMER_CLOCK_SELECT       (3)
  #define MICROS_PER_TIMER_COUNT   (clockCyclesToMicroseconds(32))
#endif
#endif

#define BFSK_MODEM_BIT_PERIOD      (1000000/BFSK_MODEM_BAUD_RATE)
#define BFSK_MODEM_HIGH_USEC       (1000000/BFSK_MODEM_HIGH_FREQ)
#define BFSK_MODEM_LOW_USEC        (1000000/BFSK_MODEM_LOW_FREQ)

#define BFSK_MODEM_HIGH_CNT        (BFSK_MODEM_BIT_PERIOD/BFSK_MODEM_HIGH_USEC)
#define BFSK_MODEM_LOW_CNT         (BFSK_MODEM_BIT_PERIOD/BFSK_MODEM_LOW_USEC)

#define BFSK_MODEM_HIGH_ADJ        (BFSK_MODEM_BIT_PERIOD%BFSK_MODEM_HIGH_USEC)
#define BFSK_MODEM_LOW_ADJ         (BFSK_MODEM_BIT_PERIOD%BFSK_MODEM_LOW_USEC)

#define BFSK_MODEM_CARRIR_CNT      (20000000/BFSK_MODEM_BIT_PERIOD)

#define TCNT_BIT_PERIOD            (BFSK_MODEM_BIT_PERIOD/MICROS_PER_TIMER_COUNT)
#define TCNT_HIGH_FREQ             (BFSK_MODEM_HIGH_USEC/MICROS_PER_TIMER_COUNT)
#define TCNT_LOW_FREQ              (BFSK_MODEM_LOW_USEC/MICROS_PER_TIMER_COUNT)

#define TCNT_HIGH_TH_L             (TCNT_HIGH_FREQ * 0.80)
#define TCNT_HIGH_TH_H             (TCNT_HIGH_FREQ * 1.15)
#define TCNT_LOW_TH_L              (TCNT_LOW_FREQ * 0.85)
#define TCNT_LOW_TH_H              (TCNT_LOW_FREQ * 1.20)

//  Brief carrier tone before each transmission
//  1 start bit (LOW)
//  8 data bits, LSB first
//  1 stop bit (HIGH)
//  1 push bit (HIGH)

#define BFSK_MODEM_TX_PIN      (3)
#define BFSK_MODEM_RX_PIN1     (6)  // AIN0
#define BFSK_MODEM_RX_PIN2     (7)  // AIN1

/*********** Bus Collision Avoidance ***********/
#define BFSK_CA_RST				0x60
#define BFSK_CA_MIN				0x00
#define BFSK_CA_MAX				0xFF
#define BFSK_CA_INC				0x30
#define	BFSK_CA_DCR				0x05
#define	BFSK_CA_BUSY			0x10

#define	BFSK_CA_TX_RETRY		0x03
#define	BFSK_CA_TX_NO			0x03
#define	BFSK_CA_TX_MAX_COUNT	0x03
#define	BFSK_CA_COLIDX_MAX		0x06
#define	BFSK_CA_MAX_WAIT		200			// milliseconds
#define	BFSK_CA_TX_DELAY		10			// milliseconds

#define plinio_tx_count()				bus_ca_tx++
#define plinio_rx_count()				bus_ca_tx=0
#define	plinio_tx_allowed()				(bus_ca_tx < BFSK_CA_TX_MAX_COUNT)
#define	plinio_setbus(m)				bus_ca = m
#define	plinio_busy()					if(bus_ca < (BFSK_CA_MAX - BFSK_CA_INC)) bus_ca += BFSK_CA_INC
#define	plinio_busval()					bus_ca
#define	plinio_busavailable()			(bus_ca > BFSK_CA_BUSY)
/*************************************************/

#define	BFSK_FAIL				0
#define	BFSK_SUCCESS			1

enum {
	FSK_START_BIT = 0,
	FSK_D0_BIT,
	FSK_D1_BIT,
	FSK_D2_BIT,
	FSK_D3_BIT,
	FSK_D4_BIT,
	FSK_D5_BIT,
	FSK_D6_BIT,
	FSK_D7_BIT,  
	FSK_STOP_BIT
};

uint8_t plinio_available();	
void plinio_init();
void plinio_end();
uint8_t plinio_getbyte(uint8_t byteno);
uint8_t plinio_retrieve(uint8_t *data, uint8_t max_len);
void plinio_remove(uint8_t index, uint8_t len);
uint8_t plinio_send(uint8_t *data, uint8_t len);
void plinio_collisionavoidance();
uint8_t plinio_full();

#endif