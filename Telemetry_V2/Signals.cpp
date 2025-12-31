#include "Signals.h"

const std::unordered_map<SignalID, SignalInfo> SIGNAL_INFO{
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


SignalManager::SignalManager() {}
SignalManager::~SignalManager() {}
void SignalManager::updateSignal(SignalID id, Signal data) {


}