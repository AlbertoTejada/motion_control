#pragma once

#ifndef CAN_DRV_MOCK_H
#define CAN_DRV_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"
#include "Mcp2515.h"

class CanDrvMock{
public:
	virtual ~CanDrvMock(){}

	//Mock methods
	MOCK_METHOD(void, mcp2515_init, ());

	MOCK_METHOD(MCP2515_ERROR, reset, ());

	MOCK_METHOD(MCP2515_ERROR, setConfigMode, ());

	MOCK_METHOD(MCP2515_ERROR, setListenOnlyMode, ());

	MOCK_METHOD(MCP2515_ERROR, setSleepMode, ());

	MOCK_METHOD(MCP2515_ERROR, setLoopbackMode, ());

	MOCK_METHOD(MCP2515_ERROR, setNormalMode, ());

	MOCK_METHOD(MCP2515_ERROR, setClkOut, (const CAN_CLKOUT divisor));

	MOCK_METHOD(MCP2515_ERROR, setBitrate, (const CAN_SPEED canSpeed, const CAN_CLOCK canClock));

	MOCK_METHOD(MCP2515_ERROR, setFilterMask, (const MCP2515_MASK num, const bool ext, const uint32_t ulData));

	MOCK_METHOD(MCP2515_ERROR, setFilter, (const MCP2515_RXF num, const bool ext, const uint32_t ulData));

	MOCK_METHOD(MCP2515_ERROR, sendMessageToRegister, (const MCP2515_TXBn txbn, const struct can_frame* frame));

	MOCK_METHOD(MCP2515_ERROR, sendMessage, (const struct can_frame* frame));

	MOCK_METHOD(MCP2515_ERROR, readMessageFromRegister, (const MCP2515_RXBn rxbn, struct can_frame* frame));

	MOCK_METHOD(MCP2515_ERROR, readMessage, (struct can_frame* frame));

	MOCK_METHOD(bool, checkReceive, ());

	MOCK_METHOD(bool, checkError, ());

	MOCK_METHOD(uint8_t, getErrorFlags, ());

	MOCK_METHOD(void, clearRXnOVRFlags, ());

	MOCK_METHOD(uint8_t, getInterrupts, ());

	MOCK_METHOD(uint8_t, getInterruptMask, ());

	MOCK_METHOD(void, clearInterrupts, ());

	MOCK_METHOD(void, clearTXInterrupts, ());

	MOCK_METHOD(uint8_t, getStatus, ());

	MOCK_METHOD(void, clearRXnOVR, ());

	MOCK_METHOD(void, clearMERR, ());

	MOCK_METHOD(void, clearERRIF, ());
};

#endif // CAN_DRV_MOCK_H
