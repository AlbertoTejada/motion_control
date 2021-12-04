#include "SystemModel.h"
#include <math.h>
#include <stdint.h>

SystemModel::SystemModel(float K_i, float tau_i){
	K = K_i;
	tau = tau_i;
	/* wn = wn_i */
	/* dp = dp_i; */
	/* beta = sqrt(1 - pow(dp ,2)); */
	/* teta = 1 / cos(dp); */
	p0 = 0;
}

SystemModel::~SystemModel(){}

int32_t SystemModel::system_response(uint32_t dtime,
																		 int32_t input){
	/* float damping = (-1 / beta) * exp(-dp * wn * dtime); */
	/* float oscillation = sin(wn * beta * dtime + teta); */
	/* float response = 1 + damping * oscillation; */
	p0 = K * input + (p0 - K * input) * exp(-(float)dtime / tau);
	return p0;
}
