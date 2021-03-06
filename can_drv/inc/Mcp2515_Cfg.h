#pragma once

#ifndef _MCP2515_CFG_H_
#define _MCP2515_CFG_H_

#include <stdint.h>

/* static const uint8_t CANCTRL_REQOP = 0xE0; */
/* static const uint8_t CANCTRL_ABAT = 0x10; */
/* static const uint8_t CANCTRL_OSM = 0x08; */
/* static const uint8_t CANCTRL_CLKEN = 0x04; */
/* static const uint8_t CANCTRL_CLKPRE = 0x03; */

#define CANCTRL_REQOP   (0xE0)
#define CANCTRL_ABAT    (0x10)
#define CANCTRL_OSM     (0x08)
#define CANCTRL_CLKEN   (0x04)
#define CANCTRL_CLKPRE  (0x03)
typedef enum {
    CANCTRL_REQOP_NORMAL = 0x00,
    CANCTRL_REQOP_SLEEP = 0x20,
    CANCTRL_REQOP_LOOPBACK = 0x40,
    CANCTRL_REQOP_LISTENONLY = 0x60,
    CANCTRL_REQOP_CONFIG = 0x80,
    CANCTRL_REQOP_POWERUP = 0xE0
} CANCTRL_REQOP_MODE;

typedef enum {
    CANINTF_RX0IF = 0x01,
    CANINTF_RX1IF = 0x02,
    CANINTF_TX0IF = 0x04,
    CANINTF_TX1IF = 0x08,
    CANINTF_TX2IF = 0x10,
    CANINTF_ERRIF = 0x20,
    CANINTF_WAKIF = 0x40,
    CANINTF_MERRF = 0x80
} CANINTF;

/* static const uint8_t CANSTAT_OPMOD = 0xE0; */
/* static const uint8_t CANSTAT_ICOD = 0x0E; */

/* static const uint8_t CNF3_SOF = 0x80; */

/* static const uint8_t TXB_EXIDE_MASK = 0x08; */
/* static const uint8_t DLC_MASK = 0x0F; */
/* static const uint8_t RTR_MASK = 0x40; */

/* static const uint8_t RXBnCTRL_RXM_STD = 0x20; */
/* static const uint8_t RXBnCTRL_RXM_EXT = 0x40; */
/* static const uint8_t RXBnCTRL_RXM_STDEXT = 0x00; */
/* static const uint8_t RXBnCTRL_RXM_MASK = 0x60; */
/* static const uint8_t RXBnCTRL_RTR = 0x08; */
/* static const uint8_t RXB0CTRL_BUKT = 0x04; */
/* static const uint8_t RXB0CTRL_FILHIT_MASK = 0x03; */
/* static const uint8_t RXB1CTRL_FILHIT_MASK = 0x07; */
/* static const uint8_t RXB0CTRL_FILHIT = 0x00; */
/* static const uint8_t RXB1CTRL_FILHIT = 0x01; */

/* static const uint8_t MCP_SIDH = 0; */
/* static const uint8_t MCP_SIDL = 1; */
/* static const uint8_t MCP_EID8 = 2; */
/* static const uint8_t MCP_EID0 = 3; */
/* static const uint8_t MCP_DLC = 4; */
/* static const uint8_t MCP_DATA = 5; */

#define CANSTAT_OPMOD (0xE0)
#define CANSTAT_ICOD  (0x0E)

#define CNF3_SOF (0x80)

#define TXB_EXIDE_MASK (0x08)
#define DLC_MASK (0x0F)
#define RTR_MASK (0x40)

#define RXBnCTRL_RXM_STD     (0x20)
#define RXBnCTRL_RXM_EXT     (0x40)
#define RXBnCTRL_RXM_STDEXT  (0x00)
#define RXBnCTRL_RXM_MASK    (0x60)
#define RXBnCTRL_RTR         (0x08)
#define RXB0CTRL_BUKT        (0x04)
#define RXB0CTRL_FILHIT_MASK (0x03)
#define RXB1CTRL_FILHIT_MASK (0x07)
#define RXB0CTRL_FILHIT      (0x00)
#define RXB1CTRL_FILHIT      (0x01)

#define MCP_SIDH (0)
#define MCP_SIDL (1)
#define MCP_EID8 (2)
#define MCP_EID0 (3)
#define MCP_DLC  (4)
#define MCP_DATA (5)
typedef enum {
    STAT_RX0IF = (1 << 0),
    STAT_RX1IF = (1 << 1)
} STAT;

static const uint8_t STAT_RXIF_MASK = STAT_RX0IF | STAT_RX1IF;

typedef enum {
    TXB_ABTF = 0x40,
    TXB_MLOA = 0x20,
    TXB_TXERR = 0x10,
    TXB_TXREQ = 0x08,
    TXB_TXIE = 0x04,
    TXB_TXP = 0x03
} TXBnCTRL;

typedef enum {
    INSTRUCTION_WRITE = 0x02,
    INSTRUCTION_READ = 0x03,
    INSTRUCTION_BITMOD = 0x05,
    INSTRUCTION_LOAD_TX0 = 0x40,
    INSTRUCTION_LOAD_TX1 = 0x42,
    INSTRUCTION_LOAD_TX2 = 0x44,
    INSTRUCTION_RTS_TX0 = 0x81,
    INSTRUCTION_RTS_TX1 = 0x82,
    INSTRUCTION_RTS_TX2 = 0x84,
    INSTRUCTION_RTS_ALL = 0x87,
    INSTRUCTION_READ_RX0 = 0x90,
    INSTRUCTION_READ_RX1 = 0x94,
    INSTRUCTION_READ_STATUS = 0xA0,
    INSTRUCTION_RX_STATUS = 0xB0,
    INSTRUCTION_RESET = 0xC0
} INSTRUCTION;

typedef enum {
    MCP_RXF0SIDH = 0x00,
    MCP_RXF0SIDL = 0x01,
    MCP_RXF0EID8 = 0x02,
    MCP_RXF0EID0 = 0x03,
    MCP_RXF1SIDH = 0x04,
    MCP_RXF1SIDL = 0x05,
    MCP_RXF1EID8 = 0x06,
    MCP_RXF1EID0 = 0x07,
    MCP_RXF2SIDH = 0x08,
    MCP_RXF2SIDL = 0x09,
    MCP_RXF2EID8 = 0x0A,
    MCP_RXF2EID0 = 0x0B,
    MCP_CANSTAT = 0x0E,
    MCP_CANCTRL = 0x0F,
    MCP_RXF3SIDH = 0x10,
    MCP_RXF3SIDL = 0x11,
    MCP_RXF3EID8 = 0x12,
    MCP_RXF3EID0 = 0x13,
    MCP_RXF4SIDH = 0x14,
    MCP_RXF4SIDL = 0x15,
    MCP_RXF4EID8 = 0x16,
    MCP_RXF4EID0 = 0x17,
    MCP_RXF5SIDH = 0x18,
    MCP_RXF5SIDL = 0x19,
    MCP_RXF5EID8 = 0x1A,
    MCP_RXF5EID0 = 0x1B,
    MCP_TEC = 0x1C,
    MCP_REC = 0x1D,
    MCP_RXM0SIDH = 0x20,
    MCP_RXM0SIDL = 0x21,
    MCP_RXM0EID8 = 0x22,
    MCP_RXM0EID0 = 0x23,
    MCP_RXM1SIDH = 0x24,
    MCP_RXM1SIDL = 0x25,
    MCP_RXM1EID8 = 0x26,
    MCP_RXM1EID0 = 0x27,
    MCP_CNF3 = 0x28,
    MCP_CNF2 = 0x29,
    MCP_CNF1 = 0x2A,
    MCP_CANINTE = 0x2B,
    MCP_CANINTF = 0x2C,
    MCP_EFLG = 0x2D,
    MCP_TXB0CTRL = 0x30,
    MCP_TXB0SIDH = 0x31,
    MCP_TXB0SIDL = 0x32,
    MCP_TXB0EID8 = 0x33,
    MCP_TXB0EID0 = 0x34,
    MCP_TXB0DLC = 0x35,
    MCP_TXB0DATA = 0x36,
    MCP_TXB1CTRL = 0x40,
    MCP_TXB1SIDH = 0x41,
    MCP_TXB1SIDL = 0x42,
    MCP_TXB1EID8 = 0x43,
    MCP_TXB1EID0 = 0x44,
    MCP_TXB1DLC = 0x45,
    MCP_TXB1DATA = 0x46,
    MCP_TXB2CTRL = 0x50,
    MCP_TXB2SIDH = 0x51,
    MCP_TXB2SIDL = 0x52,
    MCP_TXB2EID8 = 0x53,
    MCP_TXB2EID0 = 0x54,
    MCP_TXB2DLC = 0x55,
    MCP_TXB2DATA = 0x56,
    MCP_RXB0CTRL = 0x60,
    MCP_RXB0SIDH = 0x61,
    MCP_RXB0SIDL = 0x62,
    MCP_RXB0EID8 = 0x63,
    MCP_RXB0EID0 = 0x64,
    MCP_RXB0DLC = 0x65,
    MCP_RXB0DATA = 0x66,
    MCP_RXB1CTRL = 0x70,
    MCP_RXB1SIDH = 0x71,
    MCP_RXB1SIDL = 0x72,
    MCP_RXB1EID8 = 0x73,
    MCP_RXB1EID0 = 0x74,
    MCP_RXB1DLC = 0x75,
    MCP_RXB1DATA = 0x76
} REGISTER;

#define N_TXBUFFERS 3
#define N_RXBUFFERS 2

typedef struct {
    REGISTER CTRL;
    REGISTER SIDH;
    REGISTER DATA;
} TXBn_REGS;

typedef struct {
    REGISTER CTRL;
    REGISTER SIDH;
    REGISTER DATA;
    CANINTF  CANINTF_RXnIF;
} RXBn_REGS;

typedef enum {
    ERROR_MODE_OK = 0x00,
    ERROR_MODE_FAIL = 0x01
} ERROR_MODE;


#if defined(__cplusplus)
extern "C"
{
#endif
ERROR_MODE setMode(const CANCTRL_REQOP_MODE mode);
uint8_t readRegister(const REGISTER reg);
void readRegisters(const REGISTER reg, uint8_t values[], const uint8_t n);
void setRegister(const REGISTER reg, const uint8_t value);
void setRegisters(const REGISTER reg, const uint8_t values[], const uint8_t n);
void modifyRegister(const REGISTER reg, const uint8_t mask, const uint8_t data);
void prepareId(uint8_t* buffer, const uint8_t ext, const uint32_t id);

#if defined(__cplusplus)
} // Closing brace for extern C
#endif


#endif //_MCP2515_CFG_H_
