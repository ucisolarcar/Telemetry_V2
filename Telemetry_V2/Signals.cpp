#include "Signals.h"

SignalManager g_signal_manager; // Global signal manager instantiation

// This will be a static data structure that can be referenced when pushing data to the database
// TODO: add the CAN ID to this signal map
const std::unordered_map<SignalID, SignalInfo> SIGNAL_INFO {
	{ SignalID::MPPT_1_InputVoltage,   { "MPPT 1 Input Voltage",   "V", false, CanID::MPPT_1_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_1_OutputVoltage,  { "MPPT 1 Output Voltage",  "V", false, CanID::MPPT_1_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_1_InputCurrent,   { "MPPT 1 Input Current",   "A", false, CanID::MPPT_1_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_1_OutputCurrent,  { "MPPT 1 Output Current",  "A", false, CanID::MPPT_1_POWER_MEASUREMENTS } },

	{ SignalID::MPPT_2_InputVoltage,   { "MPPT 2 Input Voltage",   "V", false, CanID::MPPT_2_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_2_OutputVoltage,  { "MPPT 2 Output Voltage",  "V", false, CanID::MPPT_2_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_2_InputCurrent,   { "MPPT 2 Input Current",   "A", false, CanID::MPPT_2_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_2_OutputCurrent,  { "MPPT 2 Output Current",  "A", false, CanID::MPPT_2_POWER_MEASUREMENTS } },

	{ SignalID::MPPT_3_InputVoltage,   { "MPPT 3 Input Voltage",   "V", false, CanID::MPPT_3_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_3_OutputVoltage,  { "MPPT 3 Output Voltage",  "V", false, CanID::MPPT_3_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_3_InputCurrent,   { "MPPT 3 Input Current",   "A", false, CanID::MPPT_3_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_3_OutputCurrent,  { "MPPT 3 Output Current",  "A", false, CanID::MPPT_3_POWER_MEASUREMENTS } },

	{ SignalID::MPPT_4_InputVoltage,   { "MPPT 4 Input Voltage",   "V", false, CanID::MPPT_4_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_4_OutputVoltage,  { "MPPT 4 Output Voltage",  "V", false, CanID::MPPT_4_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_4_InputCurrent,   { "MPPT 4 Input Current",   "A", false, CanID::MPPT_4_POWER_MEASUREMENTS } },
	{ SignalID::MPPT_4_OutputCurrent,  { "MPPT 4 Output Current",  "A", false, CanID::MPPT_4_POWER_MEASUREMENTS } },
};

SignalManager::SignalManager() {}
SignalManager::~SignalManager() {}
const std::unordered_map<SignalID, Signal>& SignalManager::get_signals() const {
	return signals;
}
void SignalManager::update_signal(SignalID id, Signal data) {
	auto it = signals.find(id);
	if (it != signals.end()) {
		it->second = data;
	}
	else {
		signals.insert({ id, data });
		std::cout << "Inserted a new entry: " << data.info->title << std::endl;
	}

	std::cout << "Signal " << data.info->title << " successfully updated!" << std::endl;
}