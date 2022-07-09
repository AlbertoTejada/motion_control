#include "fake_can_drv.h"
extern "C" {
#include "Mcp2515.h"
}

extern "C" void mcp2515_init(void){
	return FakeCanDrv::_can_drv -> mcp2515_init();
}

extern "C" MCP2515_ERROR reset(void){
	return FakeCanDrv::_can_drv -> reset();
}

extern "C" MCP2515_ERROR setConfigMode(){
	return FakeCanDrv::_can_drv -> setConfigMode();
}

extern "C" MCP2515_ERROR setListenOnlyMode(){
	return FakeCanDrv::_can_drv -> setListenOnlyMode();
}

extern "C" MCP2515_ERROR setSleepMode(){
	return FakeCanDrv::_can_drv -> setSleepMode();
}

extern "C" MCP2515_ERROR setLoopbackMode(){
	return FakeCanDrv::_can_drv -> setLoopbackMode();
}

extern "C" MCP2515_ERROR setNormalMode(){
	return FakeCanDrv::_can_drv -> setNormalMode();
}

extern "C" MCP2515_ERROR setClkOut(const CAN_CLKOUT divisor){
	return FakeCanDrv::_can_drv -> setClkOut(divisor);
}

extern "C" MCP2515_ERROR setBitrate(const CAN_SPEED canSpeed, const CAN_CLOCK canClock){
	return FakeCanDrv::_can_drv -> setBitrate(canSpeed, canClock);
}

extern "C" MCP2515_ERROR setFilterMask(const MCP2515_MASK num, const bool ext, const uint32_t ulData){
	return FakeCanDrv::_can_drv -> setFilterMask(num, ext, ulData);
}

extern "C" MCP2515_ERROR setFilter(const MCP2515_RXF num, const bool ext, const uint32_t ulData){
	return FakeCanDrv::_can_drv -> setFilter(num, ext, ulData);
}

extern "C" MCP2515_ERROR sendMessageToRegister(const MCP2515_TXBn txbn, const struct can_frame* frame){
	return FakeCanDrv::_can_drv -> sendMessageToRegister(txbn, frame);
}

extern "C" MCP2515_ERROR sendMessage(const struct can_frame* frame){
	return FakeCanDrv::_can_drv -> sendMessage(frame);
}

extern "C" MCP2515_ERROR readMessageFromRegister(const MCP2515_RXBn rxbn, struct can_frame* frame){
	return FakeCanDrv::_can_drv -> readMessageFromRegister(rxbn, frame);
}

extern "C" MCP2515_ERROR readMessage(struct can_frame* frame){
	return FakeCanDrv::_can_drv -> readMessage(frame);
}

extern "C" bool checkReceive(void){
	return FakeCanDrv::_can_drv -> checkReceive();
}

extern "C" bool checkError(void){
	return FakeCanDrv::_can_drv -> checkError();
}

extern "C" uint8_t getErrorFlags(void){
	return FakeCanDrv::_can_drv -> getErrorFlags();
}

extern "C" void clearRXnOVRFlags(void){
	return FakeCanDrv::_can_drv -> clearRXnOVRFlags();
}

extern "C" uint8_t getInterrupts(void){
	return FakeCanDrv::_can_drv -> getInterrupts();
}

extern "C" uint8_t getInterruptMask(void){
	return FakeCanDrv::_can_drv -> getInterruptMask();
}

extern "C" void clearInterrupts(void){
	return FakeCanDrv::_can_drv -> clearInterrupts();
}

extern "C" void clearTXInterrupts(void){
	return FakeCanDrv::_can_drv -> clearTXInterrupts();
}

extern "C" uint8_t getStatus(void){
	return FakeCanDrv::_can_drv -> getStatus();
}

extern "C" void clearRXnOVR(void){
	return FakeCanDrv::_can_drv -> clearRXnOVR();
}

extern "C" void clearMERR(){
	return FakeCanDrv::_can_drv -> clearMERR();
}

extern "C" void clearERRIF(){
	return FakeCanDrv::_can_drv -> clearERRIF();
}
