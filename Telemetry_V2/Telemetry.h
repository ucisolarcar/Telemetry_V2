#pragma once

#include <unordered_map>
#include <cstdint>
#include <string>

#include <iostream> // don't use this if we don't need to

enum class CanID : uint32_t { // change the naming convention
	MPPT_1_POWER_MEASUREMENTS = 0X200,
	MPPT_1_STATUS = 0x201,
	MPPT_2_POWER_MEASUREMENTS = 0X210,
	MPPT_2_STATUS = 0x211,
	MPPT_3_POWER_MEASUREMENTS = 0X220,
	MPPT_3_STATUS = 0x221,
	MPPT_4_POWER_MEASUREMENTS = 0X230,
	MPPT_4_STATUS = 0x231
};

enum SignalID { // regular enum so that it will work as indexes to hashed data structures
	MPPT_1_InputVoltage,
	MPPT_1_OutputVoltage,
	MPPT_1_InputCurrent,
	MPPT_1_OutputCurrent,
	MPPT_2_InputVoltage,
	MPPT_2_OutputVoltage,
	MPPT_2_InputCurrent,
	MPPT_2_OutputCurrent,
	MPPT_3_InputVoltage,
	MPPT_3_OutputVoltage,
	MPPT_3_InputCurrent,
	MPPT_3_OutputCurrent,
	MPPT_4_InputVoltage,
	MPPT_4_OutputVoltage,
	MPPT_4_InputCurrent,
	MPPT_4_OutputCurrent,
};

// used stores live data
struct Signal {
	double value; // normalize all data to double types
	int64_t timestamp; // update this every time
};

// metadata for the signal
struct SignalInfo {
	std::string title;
	std::string unit; // volts, amps, etc
	bool is_fault;
};

extern const std::unordered_map<SignalID, SignalInfo> SIGNAL_INFO;

// using DecoderFn = should be some standardized return type
// extern const std::unordered_map<CanID, DecoderFn

class Telemetry
{
private:
	std::unordered_map<CanID, Signal> data;

public:
	Telemetry();
	~Telemetry();
};