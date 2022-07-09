#pragma once

#ifndef FAKE_CAN_DRV_H
#define FAKE_CAN_DRV_H

#include <memory.h>
#include "gtest/gtest.h"
#include "can_drv_mock.h"

class FakeCanDrv: virtual public ::testing::Test{
public:
	FakeCanDrv(){
		_can_drv.reset(new ::testing::NiceMock<CanDrvMock>());
	}
	~FakeCanDrv(){
		_can_drv.reset();
	}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<CanDrvMock> _can_drv;
};

#endif // FAKE_CAN_DRV_H
