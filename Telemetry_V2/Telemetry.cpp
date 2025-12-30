#include "Telemetry.h"

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

const std::unordered_map<uint32_t, DecoderFn> DECODERS {
	{ 0x300, testFunction },
};

Telemetry::Telemetry() {}
Telemetry::~Telemetry() {}
