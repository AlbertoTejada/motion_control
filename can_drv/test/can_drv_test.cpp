#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Fixture.h"

extern "C" {
#include "Mcp2515.h"
#include "Mcp2515_Cfg.h"
}

using namespace ::testing;
using ::testing::Return;


class SpiTest: public Fixture{
public:
  SpiTest(){}
};

TEST_F(SpiTest, InitDriver)
{
  uint8_t number = 5;
  EXPECT_CALL(*_spi, spi_init(number))
    .Times(1);
  mcp2515_init(number);
}

TEST_F(SpiTest, reset)
{
  // Required parameters:;
  static const uint8_t MCP_CANINTE_value = (01U | 02U | 32U | 128U);
  static const uint8_t MCP_RXB0CTRL_mask = (96U | 04U | 03U);
  static const uint8_t MCP_RXB0CTRL_val  = (00U | 04U | 00U);
  static const uint8_t MCP_RXB1CTRL_mask = (96U | 07U);
  static const uint8_t MCP_RXB1CTRL_val  = (00U | 01U);


  MCP2515_ERROR _error;
  MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;
  uint8_t filters[] = { MCP_RXF0SIDH,
              MCP_RXF1SIDH,
              MCP_RXF2SIDH,
              MCP_RXF3SIDH,
              MCP_RXF4SIDH,
              MCP_RXF5SIDH };

  uint8_t masks[] = { MCP_RXM0SIDH, MCP_RXM1SIDH };

  using ::testing::InSequence;
  using ::testing::Return;
  InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
  /* reset() */
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_RESET)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  EXPECT_CALL(*_timer, os_wait_ms(10)).Times(1);

  // setRegisters(MCP_TXB0CTRL, zeros, 14)
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_TXB0CTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(0U)).Times(14); // n = 14 harcoded
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  // setRegisters(MCP_TXB1CTRL, zeros, 14)
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_TXB1CTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(0U)).Times(14); // n = 14 harcoded
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  // setRegisters(MCP_TXB2CTRL, zeros, 14)
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_TXB2CTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(0U)).Times(14); // n = 14 harcoded
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  // setRegister(MCP_RXB0CTRL, 0)
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_RXB0CTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(0U)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  // setRegister(MCP_RXB1CTRL, 0)
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_RXB1CTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(0U)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  //setRegister(MCP_CANINTE, CANINTF_RX0IF | CANINTF_RX1IF | CANINTF_ERRIF | CANINTF_MERRF);
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_CANINTE)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_CANINTE_value)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  //modifyRegister(MCP_RXB0CTRL,
  //  RXBnCTRL_RXM_MASK | RXB0CTRL_BUKT | RXB0CTRL_FILHIT_MASK,
  //  RXBnCTRL_RXM_STDEXT | RXB0CTRL_BUKT | RXB0CTRL_FILHIT);
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_RXB0CTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_RXB0CTRL_mask)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_RXB0CTRL_val)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  //modifyRegister(MCP_RXB1CTRL,
  //  RXBnCTRL_RXM_MASK | RXB1CTRL_FILHIT_MASK,
  //  RXBnCTRL_RXM_STDEXT | RXB1CTRL_FILHIT);
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_RXB1CTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_RXB1CTRL_mask)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_RXB1CTRL_val)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  for (int i = 0; i < 6; i++)
  {
    uint8_t reg = filters[i];
    // setFilter(filters[i], ext, 0);
    // setConfigMode()
    // setMode(CANCTRL_REQOP_CONFIG)
    // modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode);
    EXPECT_CALL(*_spi, spi_start()).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_CONFIG)).Times(1);
    EXPECT_CALL(*_spi, spi_end()).Times(1);

    // os_timer_ms()
    EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
      .WillOnce(Return(0))
      .WillOnce(Return(5));

    // readRegister(MCP_CANSTAT);
    EXPECT_CALL(*_spi, spi_start()).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_CONFIG));
    EXPECT_CALL(*_spi, spi_end()).Times(1);
    // setRegisters(reg, tbufdata, 4)
    EXPECT_CALL(*_spi, spi_start()).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(reg)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(_)).Times(4); // set four registers, hard coded
    EXPECT_CALL(*_spi, spi_end()).Times(1);
  }

  for (int i = 0; i < 2; i++)
  {
    uint8_t reg = masks[i];
    // setFilterMask(masks[i], true, 0);
    // setConfigMode()
    // setMode(CANCTRL_REQOP_CONFIG)
    // modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode);
    EXPECT_CALL(*_spi, spi_start()).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_CONFIG)).Times(1);
    EXPECT_CALL(*_spi, spi_end()).Times(1);

    // os_timer_ms()
    EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
      .WillOnce(Return(0))
      .WillOnce(Return(5));

    // readRegister(MCP_CANSTAT);
    EXPECT_CALL(*_spi, spi_start()).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_CONFIG));
    EXPECT_CALL(*_spi, spi_end()).Times(1);

    // setRegisters(reg, tbufdata, 4)
    EXPECT_CALL(*_spi, spi_start()).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(reg)).Times(1);
    EXPECT_CALL(*_spi, spi_transfer(_)).Times(4); // set four registers, hard coded
    EXPECT_CALL(*_spi, spi_end()).Times(1);
  }

  //MCP2515 mcp2515(_CS);
  mcp2515_init(_CS);
  // _error = mcp2515.reset();
  _error = reset();

  EXPECT_EQ(_error, expected_error);
}

TEST_F(SpiTest, setConfigMode)
{ 
  MCP2515_ERROR _error;
  MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;
  
  using ::testing::InSequence;
  using ::testing::Return;
  InSequence s;
  
  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
  // setMode(CANCTRL_REQOP_CONFIG)
  // modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode)
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_CONFIG)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);
  
  EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
    .WillOnce(Return(0))
    .WillOnce(Return(5));
  // readRegister(MCP_CANSTAT);
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_CONFIG));
  EXPECT_CALL(*_spi, spi_end()).Times(1);
  
  mcp2515_init(_CS);
  _error = setConfigMode();
  
  EXPECT_EQ(_error, expected_error);
}

TEST_F(SpiTest, setListenOnlyMode)
{
  MCP2515_ERROR _error;
  MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;

  using ::testing::InSequence;
  using ::testing::Return;
  InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
  /* setConfigMode */
  // setMode(CANCTRL_REQOP_LISTENONLY)
  // modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode)
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_LISTENONLY)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
    .WillOnce(Return(0))
    .WillOnce(Return(5));
  // readRegister(MCP_CANSTAT);
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_LISTENONLY));
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  mcp2515_init(_CS);
  _error = setListenOnlyMode();

  EXPECT_EQ(_error, expected_error);
}

TEST_F(SpiTest, setSleepMode)
{
  MCP2515_ERROR _error;
  MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;

  using ::testing::InSequence;
  using ::testing::Return;
  InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
  /* setConfigMode */
  // setMode(CANCTRL_REQOP_SLEEP)
  // modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode)
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_SLEEP)).Times(1);
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
    .WillOnce(Return(0))
    .WillOnce(Return(5));
  // readRegister(MCP_CANSTAT);
  EXPECT_CALL(*_spi, spi_start()).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
  EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_SLEEP));
  EXPECT_CALL(*_spi, spi_end()).Times(1);

  mcp2515_init(_CS);
  _error = setSleepMode();

  EXPECT_EQ(_error, expected_error);
}

TEST_F(SpiTest, setLoopbackMode)
{
	MCP2515_ERROR _error;
	MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;

	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* setConfigMode */
	// setMode(CANCTRL_REQOP_LOOPBACK)
	// modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_LOOPBACK)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
		.WillOnce(Return(0))
		.WillOnce(Return(5));
	// readRegister(MCP_CANSTAT);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_LOOPBACK));
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	mcp2515_init(_CS);
	_error = setLoopbackMode();
	EXPECT_EQ(_error, expected_error);
}

TEST_F(SpiTest, setNormalMode)
{
	MCP2515_ERROR _error;
	MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;

	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* setConfigMode */
	// setMode(CANCTRL_REQOP_NORMAL)
		// modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_NORMAL)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
		.WillOnce(Return(0))
		.WillOnce(Return(5));
	// readRegister(MCP_CANSTAT);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_NORMAL));
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	//MCP2515 mcp2515(_CS);
	mcp2515_init(_CS);
	//_error = mcp2515.setNormalMode();
	_error = setNormalMode();

	EXPECT_EQ(_error, expected_error);
}

TEST_F(SpiTest, setClkOut)
{
	MCP2515_ERROR _error;
	MCP2515_ERROR expected_error = ERROR_OK;
	CAN_CLKOUT clock_divisor;
  uint8_t _CS = 8;

	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* setClkOut CLKOUT_DISABLE */
	clock_divisor = CAN_CLKOUT(CLKOUT_DISABLE);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKEN, 0x00)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CNF3, CNF3_SOF, CNF3_SOF);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CNF3)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CNF3_SOF)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CNF3_SOF)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	//MCP2515 mcp2515(_CS);
	mcp2515_init(_CS);
	//_error = mcp2515.setClkOut(clock_divisor);
	_error = setClkOut(clock_divisor);
	EXPECT_EQ(_error, expected_error);
	/* setClkOut CLKOUT_DIV1 */
	clock_divisor = CAN_CLKOUT(CLKOUT_DIV1);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKPRE, divisor)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKPRE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(clock_divisor)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKEN, CANCTRL_CLKEN)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CNF3, CNF3_SOF, 0x00)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CNF3)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CNF3_SOF)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	_error = setClkOut(clock_divisor);
	/* setClkOut CLKOUT_DIV2 */
	clock_divisor = CAN_CLKOUT(CLKOUT_DIV2);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKPRE, divisor)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKPRE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(clock_divisor)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKEN, CANCTRL_CLKEN)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CNF3, CNF3_SOF, 0x00)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CNF3)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CNF3_SOF)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	//_error = mcp2515.setClkOut(clock_divisor);
	_error = setClkOut(clock_divisor);
	/* setClkOut CLKOUT_DIV4 */
	clock_divisor = CAN_CLKOUT(CLKOUT_DIV4);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKPRE, divisor)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKPRE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(clock_divisor)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKEN, CANCTRL_CLKEN)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CNF3, CNF3_SOF, 0x00)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CNF3)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CNF3_SOF)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	//_error = mcp2515.setClkOut(clock_divisor);
	_error = setClkOut(clock_divisor);
	/* setClkOut CLKOUT_DIV8 */
	clock_divisor = CAN_CLKOUT(CLKOUT_DIV8);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKPRE, divisor)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKPRE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(clock_divisor)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CANCTRL, CANCTRL_CLKEN, CANCTRL_CLKEN)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_CLKEN)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CNF3, CNF3_SOF, 0x00)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CNF3)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CNF3_SOF)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	//_error = mcp2515.setClkOut(clock_divisor);
	_error = setClkOut(clock_divisor);
}

TEST_F(SpiTest, setBitrate)
{
	MCP2515_ERROR _error;
	MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;
	//CAN_CLKOUT clock_divisor;

	uint8_t cfg1 = MCP_8MHz_5kBPS_CFG1;
	uint8_t cfg2 = MCP_8MHz_5kBPS_CFG2;
	uint8_t cfg3 = MCP_8MHz_5kBPS_CFG3;

	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* setBitrate */
	// setConfigMode()
	// setMode(CANCTRL_REQOP_CONFIG)
	// modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_CONFIG)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
		.WillOnce(Return(0))
		.WillOnce(Return(5));
	// readRegister(MCP_CANSTAT);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_CONFIG));
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// setRegister(MCP_CNF1, cfg1)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CNF1)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(cfg1)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// setRegister(MCP_CNF2, cfg2)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CNF2)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(cfg2)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// setRegister(MCP_CNF3, cfg3)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CNF3)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(cfg3)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	//MCP2515 mcp2515(_CS);
	mcp2515_init(_CS);
	//_error = mcp2515.setBitrate(CAN_5KBPS, MCP_8MHZ);
	_error = setBitrate(CAN_5KBPS, MCP_8MHZ);

	EXPECT_EQ(_error, expected_error);
}

TEST_F(SpiTest, setFilterMask)
{
	MCP2515_ERROR _error;
	MCP2515_ERROR expected_error = ERROR_OK;
	MCP2515_MASK mask;
  uint8_t _CS = 8;
	const uint32_t ulData = 0x11223344;

	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* setFilterMask  MASK0*/
	mask = MASK0;
	// setConfigMode()
	// setMode(CANCTRL_REQOP_CONFIG)
	// modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_CONFIG)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
		.WillOnce(Return(0))
		.WillOnce(Return(5));
	// readRegister(MCP_CANSTAT);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_CONFIG));
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// setRegisters(reg, tbufdata, 4)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_RXM0SIDH)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(_)).Times(4); // set four registers, hard coded
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	//MCP2515 mcp2515(_CS);
	mcp2515_init(_CS);
	//_error = mcp2515.setFilterMask(mask, true, ulData);
	_error = setFilterMask(mask, true, ulData);
	/* setFilterMask  MASK0*/
	mask = MASK1;
	// setConfigMode()
	// setMode(CANCTRL_REQOP_CONFIG)
	// modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_CONFIG)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
		.WillOnce(Return(0))
		.WillOnce(Return(5));
	// readRegister(MCP_CANSTAT);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_CONFIG));
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// setRegisters(reg, tbufdata, 4)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_RXM1SIDH)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(_)).Times(4); // set four registers, hard coded
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	//_error = mcp2515.setFilterMask(mask, true, ulData);
	_error = setFilterMask(mask, true, ulData);

	EXPECT_EQ(_error, expected_error);
}

TEST_F(SpiTest, setFilter)
{
	MCP2515_ERROR _error;
	MCP2515_ERROR expected_error = ERROR_OK;
	MCP2515_RXF rxf[] = {	RXF0,
							RXF1,
							RXF2,
							RXF3,
							RXF4,
							RXF5};
	uint8_t filters[] = { MCP_RXF0SIDH,
							MCP_RXF1SIDH,
							MCP_RXF2SIDH,
							MCP_RXF3SIDH,
							MCP_RXF4SIDH,
							MCP_RXF5SIDH };
  uint8_t _CS = 8;
	bool ext = true;
	const uint32_t ulData = 0x11223344;

	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* setFilter(RXF0, true, 0) */
	MCP2515_RXF _rxf = rxf[0];
	uint8_t reg = filters[0];
	// setConfigMode()
	// setMode(CANCTRL_REQOP_CONFIG)
	// modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_CONFIG)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
		.WillOnce(Return(0))
		.WillOnce(Return(5));
	// readRegister(MCP_CANSTAT);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_CONFIG));
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// setRegisters(reg, tbufdata, 4)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(reg)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(_)).Times(4); // set four registers, hard coded
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	//MCP2515 mcp2515(_CS);
	mcp2515_init(_CS);
	//_error = mcp2515.setFilter(_rxf, ext, ulData);
	_error = setFilter(_rxf, ext, ulData);
	EXPECT_EQ(_error, expected_error);

	for (int i = 1; i < 6; i++)
	{
		uint8_t reg = filters[i];
		MCP2515_RXF _rxf = rxf[i];
		// setFilter(filters[i], ext, 0);
		// setConfigMode()
		// setMode(CANCTRL_REQOP_CONFIG)
		// modifyRegister(MCP_CANCTRL, CANCTRL_REQOP, mode);
		EXPECT_CALL(*_spi, spi_start()).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(MCP_CANCTRL)).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP)).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(CANCTRL_REQOP_CONFIG)).Times(1);
		EXPECT_CALL(*_spi, spi_end()).Times(1);
		EXPECT_CALL(*_timer, os_timer_ms()).Times(2)
			.WillOnce(Return(0))
			.WillOnce(Return(5));
		// readRegister(MCP_CANSTAT);
		EXPECT_CALL(*_spi, spi_start()).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(MCP_CANSTAT)).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(CANCTRL_REQOP_CONFIG));
		EXPECT_CALL(*_spi, spi_end()).Times(1);
		// setRegisters(reg, tbufdata, 4)
		EXPECT_CALL(*_spi, spi_start()).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(reg)).Times(1);
		EXPECT_CALL(*_spi, spi_transfer(_)).Times(4); // set four registers, hard coded
		EXPECT_CALL(*_spi, spi_end()).Times(1);
		//_error = mcp2515.setFilter(_rxf, ext, ulData);
		_error = setFilter(_rxf, ext, ulData);
		EXPECT_EQ(_error, expected_error);
	}
}

TEST_F(SpiTest, sendMessage)
{
	MCP2515_ERROR _error;
	MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;

	MCP2515_TXBn txbn;

	const struct can_frame frame =
	{
		0x12345678,
		8,
		{0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88}
	};
	const struct can_frame* frame_prt = &frame;

	static const struct TXBn_REGS {
		uint8_t CTRL;
		uint8_t SIDH;
		uint8_t DATA;
	} TXB[3] = {
		{MCP_TXB0CTRL, MCP_TXB0SIDH, MCP_TXB0DATA},
		{MCP_TXB1CTRL, MCP_TXB1SIDH, MCP_TXB1DATA},
		{MCP_TXB2CTRL, MCP_TXB2SIDH, MCP_TXB2DATA}
	};

	txbn = TXB0;
	const struct TXBn_REGS* txbuf = &TXB[txbn];

	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* SEND MESSAGE */
	// setRegisters(txbuf->SIDH, data, 5 + frame->can_dlc)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_WRITE)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(txbuf->SIDH)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(_)).Times(5 + frame_prt->can_dlc);
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	// modifyRegister(txbuf->CTRL, TXB_TXREQ, TXB_TXREQ);;
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(txbuf->CTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(TXB_TXREQ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(TXB_TXREQ)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// uint8_t ctrl = readRegister(txbuf->CTRL)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(txbuf->CTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return((uint8_t)0));
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	//MCP2515 mcp2515(_CS);
	mcp2515_init(_CS);
	_error = sendMessageToRegister(txbn, frame_prt);
	EXPECT_EQ(_error, expected_error);
	// TODO: completar este test para comprobar todos los campos del mensaje
}

TEST_F(SpiTest, readMessage)
{
	MCP2515_ERROR _error;
	MCP2515_ERROR expected_error = ERROR_OK;
  uint8_t _CS = 8;
	struct can_frame frame =
	{
		0x12345678,
		8,
		{0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88}
	};
	struct can_frame* frame_prt = &frame;
	static const struct RXBn_REGS {
		uint8_t CTRL;
		uint8_t SIDH;
		uint8_t DATA;
		uint8_t  CANINTF_RXnIF;
	} RXB[2] = {
		{MCP_RXB0CTRL, MCP_RXB0SIDH, MCP_RXB0DATA, CANINTF_RX0IF},
		{MCP_RXB1CTRL, MCP_RXB1SIDH, MCP_RXB1DATA, CANINTF_RX1IF}
	};

	MCP2515_RXBn rxbn = RXB0;
	const struct RXBn_REGS* rxb = &RXB[rxbn];

	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* read MESSAGE */
	// readRegisters(rxb->SIDH, tbufdata, 5);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(rxb->SIDH)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(5).WillOnce(Return(0x11))
		.WillOnce(Return(0x22))
		.WillOnce(Return(0x33))
		.WillOnce(Return(0x44))
		.WillOnce(Return(0x08)); //dlc = 8
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// uint8_t ctrl = readRegister(rxb->CTRL)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(rxb->CTRL)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(0x00));
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// readRegisters(rxb->DATA, frame->data, dlc)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(rxb->DATA)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(8).WillOnce(Return(0x11))
		.WillOnce(Return(0x22))
		.WillOnce(Return(0x33))
		.WillOnce(Return(0x44))
		.WillOnce(Return(0x55))
		.WillOnce(Return(0x66))
		.WillOnce(Return(0x77))
		.WillOnce(Return(0x88));
	EXPECT_CALL(*_spi, spi_end()).Times(1);
	// modifyRegister(MCP_CANINTF, rxb->CANINTF_RXnIF, 0)
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_BITMOD)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_CANINTF)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(rxb->CANINTF_RXnIF)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0)).Times(1);
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	mcp2515_init(_CS);
	//_error = mcp2515.readMessage(rxbn, frame_prt);
	_error = readMessageFromRegister(rxbn, frame_prt);
	EXPECT_EQ(_error, expected_error);
	EXPECT_EQ(frame.can_dlc, 0x08);
	// TODO: completar este test para comprobar todos los campos del mensaje
}

TEST_F(SpiTest, getStatus)
{
	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;
  uint8_t _CS = 8;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* getStatus() */
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ_STATUS)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(0xCC));
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	//MCP2515 mcp2515(_CS);
	mcp2515_init(_CS);
	//uint8_t return_value = mcp2515.getStatus();
	uint8_t return_value = getStatus();
	EXPECT_EQ(return_value, 0xCC);
}

TEST_F(SpiTest, checkReceive)
{
	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;
  uint8_t _CS = 8;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* getStatus() */
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ_STATUS)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(0x03));
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	mcp2515_init(_CS);
	//uint8_t return_value = mcp2515.checkReceive();
	uint8_t return_value = checkReceive();
	EXPECT_EQ(return_value, 1);

	/* getStatus() */
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ_STATUS)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(0x04));
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	//return_value = mcp2515.checkReceive();
	return_value = checkReceive();
	EXPECT_EQ(return_value, 0);
}

TEST_F(SpiTest, getErrorFlags)
{
	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;
  uint8_t _CS = 8;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* getErrorFlags() */
	// readRegister(MCP_EFLG);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_EFLG)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(0xCC));
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	mcp2515_init(_CS);
	//uint8_t return_value = mcp2515.getErrorFlags();
	uint8_t return_value = getErrorFlags();
	EXPECT_EQ(return_value, 0xCC);
}

TEST_F(SpiTest, checkError)
{
	using ::testing::InSequence;
	using ::testing::Return;
	InSequence s;
  uint8_t _CS = 8;

  EXPECT_CALL(*_spi, spi_init(_CS)).Times(1);
	/* checkError() */
	// getErrorFlags()
  // readRegister(MCP_EFLG);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_EFLG)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(0x01));
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	//MCP2515 mcp2515(_CS);
	mcp2515_init(_CS);
	//uint8_t return_value = mcp2515.checkError();
	uint8_t return_value = checkError();
	EXPECT_EQ(return_value, 0x00);

	// readRegister(MCP_EFLG);
	EXPECT_CALL(*_spi, spi_start()).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(INSTRUCTION_READ)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(MCP_EFLG)).Times(1);
	EXPECT_CALL(*_spi, spi_transfer(0x00)).Times(1).WillOnce(Return(0x08));
	EXPECT_CALL(*_spi, spi_end()).Times(1);

	//return_value = mcp2515.checkError();
	return_value = checkError();
	EXPECT_EQ(return_value, 0x01);
}
