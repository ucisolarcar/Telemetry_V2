#include "Decoders.h"

void Decoders::mppt_power_measurements(uint8_t buffer[BUF_SIZE]) {
	std::cout << "Decoding MPPT Power Measurements\n";

	assert(buffer != nullptr);

	MPPT parser;
	powerMeasurements pm;
	pm = parser.parsePowerMeasurements(buffer);

	Signal signal;

	// Update all signals relevant to this CAN Frame
	signal.value = static_cast<double>(pm.inVoltage);
	signal.info = &SIGNAL_INFO.find(SignalID::MPPT_1_InputVoltage)->second;
	SIGNAL_MANAGER.updateSignal(MPPT_1_InputVoltage, signal);

	signal.value = static_cast<double>(pm.inCurrent);
	signal.info = &SIGNAL_INFO.find(SignalID::MPPT_1_InputCurrent)->second;
	SIGNAL_MANAGER.updateSignal(MPPT_1_InputCurrent, signal);

	signal.value = static_cast<double>(pm.outVoltage);
	signal.info = &SIGNAL_INFO.find(SignalID::MPPT_1_OutputVoltage)->second;
	SIGNAL_MANAGER.updateSignal(MPPT_1_OutputVoltage, signal);

	signal.value = static_cast<double>(pm.outCurrent);
	signal.info = &SIGNAL_INFO.find(SignalID::MPPT_1_OutputCurrent)->second;
	SIGNAL_MANAGER.updateSignal(MPPT_1_OutputCurrent, signal);
}