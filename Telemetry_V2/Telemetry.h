#pragma once

#include <unordered_map>
#include <cstdint>
#include <string>

#include <iostream> // don't use this if we don't need to

#include "Decoders.h"

enum class CanID : uint32_t { // TODO determine if this is even necessary
	MPPT_1_POWER_MEASUREMENTS = 0X200,
	MPPT_1_STATUS = 0x201,
	MPPT_2_POWER_MEASUREMENTS = 0X210,
	MPPT_2_STATUS = 0x211,
	MPPT_3_POWER_MEASUREMENTS = 0X220,
	MPPT_3_STATUS = 0x221,
	MPPT_4_POWER_MEASUREMENTS = 0X230,
	MPPT_4_STATUS = 0x231
};

// TODO determine if this is even necessary
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

// using DecoderFn = void(*)(uint8_t buffer[8]); // TODO: change this to the actual function definition structure
// extern const std::unordered_map<CanID, DecoderFn> DECODERS;
using DecoderFn = void(*)(const char* buffer);
extern const std::unordered_map<uint32_t, DecoderFn> DECODERS;

class Telemetry
{
private:
	std::unordered_map<CanID, Signal> data;

public:
	Telemetry();
	~Telemetry();
};