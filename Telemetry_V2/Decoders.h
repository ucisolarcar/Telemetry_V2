#pragma once

#include <iostream>
#include <assert.h>

#include "mppt.h"
#include "bms.h"
#include "mcu.h"
#include "sensorFunctions.h"

#include "Signals.h"

#define BUF_SIZE 8

namespace Decoders {
	void mppt_power_measurements(uint8_t buffer[BUF_SIZE]);
}



/*
TODO - define decoders for every possible CAN ID frame


think about what errors I should be checking and if there should be any exception handling
*/