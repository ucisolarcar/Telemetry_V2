#pragma once

#include <unordered_map>
#include <cstdint>
#include <string>

#include <iostream> // don't use this if we don't need to

#include "Decoders.h"

enum class CanID : uint32_t { // Think about getting rid of this and using an unordered_set instead
	MPPT_1_POWER_MEASUREMENTS = 0X200,
	MPPT_1_STATUS = 0x201,
	MPPT_2_POWER_MEASUREMENTS = 0X210,
	MPPT_2_STATUS = 0x211,
	MPPT_3_POWER_MEASUREMENTS = 0X220,
	MPPT_3_STATUS = 0x221,
	MPPT_4_POWER_MEASUREMENTS = 0X230,
	MPPT_4_STATUS = 0x231
};

using DecoderFn = void(*)(uint8_t buffer[BUF_SIZE]);
extern const std::unordered_map<CanID, DecoderFn> DECODERS;

class Telemetry
{
private:

public:
	Telemetry();
	~Telemetry();
	void app_main();
};