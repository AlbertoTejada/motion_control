#pragma once

#ifndef CNT_MOCK_H
#define CNT_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class CntMock{
public:
	virtual ~CntMock(){}

	//Mock methods
	MOCK_METHOD(void, cnt_init, ());
	
	MOCK_METHOD(uint8_t, read_cnt, ());
};

#endif // CNT_MOCK_H
