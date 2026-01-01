#pragma once

#include <cstdint>
#include <string>
#include <iostream>
#include <unordered_map>

// TODO - this feels unnecessary so think of another way
enum SignalID {
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

// metadata for the signal
struct SignalInfo {
	std::string title;
	std::string unit; // volts, amps, etc
	bool is_fault;
	uint32_t can_id;
};

// stores live data
struct Signal {
	double value; // normalize all data to double types
	const SignalInfo* info; // reference to the signal metadata
};

extern const std::unordered_map<SignalID, SignalInfo> SIGNAL_INFO;

class SignalManager
{
private:

public:
	std::unordered_map<SignalID, Signal> signals;
	SignalManager();
	~SignalManager();
	void updateSignal(SignalID id, Signal data);
};

extern SignalManager SIGNAL_MANAGER; // TODO - change the naems to g_signalManager or something to indicate global