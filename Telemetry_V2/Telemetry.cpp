#include "Telemetry.h"

const std::unordered_map<CanID, DecoderFn> DECODERS {
	{ CanID::MPPT_1_POWER_MEASUREMENTS, Decoders::mppt_power_measurements },
	{ CanID::MPPT_2_POWER_MEASUREMENTS, Decoders::mppt_power_measurements }, // this is a problem because the function needs to know what signals to update
};

Telemetry::Telemetry() {}
Telemetry::~Telemetry() {}
void Telemetry::app_main() {
	// put the main loop and stuff in here
}