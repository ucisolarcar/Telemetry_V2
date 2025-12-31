#pragma once

#include <cstdint>
#include <string>
#include <iostream>
#include <unordered_map>

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

// stores live data
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

class SignalManager
{
private:
	// std::unordered_map<CanID, Signal> data;

public:
	SignalManager();
	~SignalManager();
	void updateSignal(SignalID id, Signal data);
};
