#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "fake_spi.h"
#include "fake_gpio.h"

extern "C" {
#include "spi_if.h"
}

using namespace ::testing;
using ::testing::Return;

class SpiIfFixture: public FakeSpi, public FakeGpio{
	public:
		SpiIfFixture(){}
};

TEST_F(SpiIfFixture, spi_init) {
	EXPECT_CALL(*_spi, spi_init())
		.Times(1);
	spi_init();
}

TEST_F(SpiIfFixture, spi_transfer) {
	uint8_t transfer_value = 0xCC;
	uint8_t received_value = 0x55;
	EXPECT_CALL(*_spi, spi_transfer(transfer_value))
		.Times(1)
		.WillOnce(Return(received_value));

	uint8_t result = spi_transfer(transfer_value);
	EXPECT_EQ(result, received_value);
}

TEST_F(SpiIfFixture, spi_start) {
	EXPECT_CALL(*_gpio, can_drv_select())
		.Times(1);
	spi_start();
}

TEST_F(SpiIfFixture, spi_end) {
	EXPECT_CALL(*_gpio, can_drv_deselect())
		.Times(1);
	spi_end();
}
