#include "Client.h"

void Client::print_data() {
	// Print all values in the map

	std::cout << "Displaying all signals:\n";

	for (const auto& sig : g_signal_manager.get_signals()) {
		auto info = sig.second.info;
		auto value = sig.second.value;
		std::cout << info->title << ": " << value << " " << info->unit
			<< " (0x" << std::hex << static_cast<uint32_t>(info->can_id) << ")\n";
	}
}