#pragma once

#include <iostream>
#include <assert.h>
#include <ctime>
#include <string>

#include "mppt.h"
#include "bms.h"
#include "mcu.h"
#include "sensorFunctions.h"

#include "Signals.h"

#define BUF_SIZE 8

namespace Decoders {
	void mppt_power_measurements(uint8_t buffer[BUF_SIZE]);
	// TODO: write all other decoders
}