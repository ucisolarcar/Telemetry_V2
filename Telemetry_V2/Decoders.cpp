#include "Decoders.h"

void Decoders::mppt_power_measurements(uint8_t buffer[BUF_SIZE]) {
	// We might need 4 of these functions for each MPPT
	// or at least have a helper function that just calls this function once it decides what MPPT we are working with

	std::cout << "Decoding MPPT Power Measurements\n";

	assert(buffer != nullptr);

	MPPT parser;
	powerMeasurements pm;

	pm = parser.parsePowerMeasurements(buffer);
	std::cout << "Input voltage: " << pm.inVoltage << " V" << std::endl;
	std::cout << "Input current: " << pm.inCurrent << " A" << std::endl;
	std::cout << "Output voltage: " << pm.outVoltage << " V" << std::endl;
	std::cout << "Output current: " << pm.outCurrent << " A" << std::endl;
	// instead of printing these, write them to the signals data structure
}