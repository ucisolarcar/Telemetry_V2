#pragma once

#include <cstdint>
#include <string>
#include <iostream>
#include <unordered_map>

enum class CanID : uint32_t {
	MPPT_1_POWER_MEASUREMENTS = 0x200,
	MPPT_1_STATUS = 0x201,
	MPPT_2_POWER_MEASUREMENTS = 0x210,
	MPPT_2_STATUS = 0x211,
	MPPT_3_POWER_MEASUREMENTS = 0x220,
	MPPT_3_STATUS = 0x221,
	MPPT_4_POWER_MEASUREMENTS = 0x230,
	MPPT_4_STATUS = 0x231
};

// enum used as the key in the SIGNALS_INFO mapping
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
	CanID can_id;
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
	std::unordered_map<SignalID, Signal> signals;
public:
	SignalManager();
	~SignalManager();
	const std::unordered_map<SignalID, Signal>& get_signals() const;
	void update_signal(SignalID id, Signal data);
};

extern SignalManager g_signal_manager;