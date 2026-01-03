#pragma once

#include <unordered_map>
#include <cstdint>
#include <string>

#include <iostream>

#include "Decoders.h"

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