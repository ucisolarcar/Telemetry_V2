#include "Telemetry.h"

const std::unordered_map<uint32_t, DecoderFn> DECODERS {
	{ 0x200, Decoders::mppt_power_measurements },
	{ 0x210, Decoders::mppt_power_measurements }, // this is a problem because the function needs to know what signals to update
};

Telemetry::Telemetry() {}
Telemetry::~Telemetry() {}
