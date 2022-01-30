#pragma once

#ifndef CNT_H
#define CNT_H

#include <stdint.h>

#define CNT_NORMAL_MODE 0 
#define CNT_NO_PRSCLR 1
#define CNT_OVFW_ENBL 1
#define CNT_EXT_CLK 1
#define CNT_ASYC_ENBL 1

void cnt_init(void);

uint8_t read_cnt(void);

#endif // CNT_H
