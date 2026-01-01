#include "Client.h"

void Client::printData() {
	// Print all values in the map

	std::cout << "Displaying all signals:\n";

	for (const auto& sig : SIGNAL_MANAGER.signals) {
		auto info = sig.second.info;
		auto value = sig.second.value;
		std::cout << info->title << ": " << value << " " << info->unit << "\n";
	}

}
