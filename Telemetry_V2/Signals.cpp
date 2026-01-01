#include "Signals.h"

SignalManager SIGNAL_MANAGER; // Instantiate the global signal manager

// This will be a static data structure that can be referenced when pushing data to the database
const std::unordered_map<SignalID, SignalInfo> SIGNAL_INFO {
	{ SignalID::MPPT_1_InputVoltage, { "Input Voltage", "V", false} },
	{ SignalID::MPPT_1_OutputVoltage, { "Output Voltage", "V", false} },
	{ SignalID::MPPT_1_InputCurrent, { "Input Current", "A", false} },
	{ SignalID::MPPT_1_OutputCurrent, { "Output Current", "A", false} },

	{ SignalID::MPPT_2_InputVoltage, { "Input Voltage", "V", false} },
	{ SignalID::MPPT_2_OutputVoltage, { "Output Voltage", "V", false} },
	{ SignalID::MPPT_2_InputCurrent, { "Input Current", "A", false} },
	{ SignalID::MPPT_2_OutputCurrent, { "Output Current", "A", false} },

	{ SignalID::MPPT_3_InputVoltage, { "Input Voltage", "V", false} },
	{ SignalID::MPPT_3_OutputVoltage, { "Output Voltage", "V", false} },
	{ SignalID::MPPT_3_InputCurrent, { "Input Current", "A", false} },
	{ SignalID::MPPT_3_OutputCurrent, { "Output Current", "A", false} },

	{ SignalID::MPPT_4_InputVoltage, { "Input Voltage", "V", false} },
	{ SignalID::MPPT_4_OutputVoltage, { "Output Voltage", "V", false} },
	{ SignalID::MPPT_4_InputCurrent, { "Input Current", "A", false} },
	{ SignalID::MPPT_4_OutputCurrent, { "Output Current", "A", false} },
};

SignalManager::SignalManager() {
	// TODO we need to initialize the Signals list

}
SignalManager::~SignalManager() {}
void SignalManager::updateSignal(SignalID id, Signal data) {
	auto it = signals.find(id);
	if (it != signals.end()) {
		it->second = data;
	}
	else {
		signals.insert({ id, data });
		std::cout << "Inserted a new ID (TODO - FIND ANOTHER SOLUTION FOR THIS)" << std::endl;
	}

	std::cout << "Signal " << id << " successfully updated!" << std::endl;
}