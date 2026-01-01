#include <iostream>
#include <cstdint>
#include <assert.h>

#include "can.h"
#include "mppt.h"
#include "Telemetry.h"

#include "Client.h"

#define BUF_SIZE 8

namespace Simulation {
	void split_int16(int16_t value, uint8_t* high_byte, uint8_t* low_byte) {
		*high_byte = (uint8_t)((value >> 8) & 0xFF); // Extract high 8 bits
		*low_byte = (uint8_t)(value & 0xFF);         // Extract low 8 bits
	}

	void get_mppt_test_buffer(uint8_t buffer[BUF_SIZE]) {
        assert(sizeof(buffer) == BUF_SIZE);

        int16_t inputVoltage = -22 / voltageScaleFactor;
        int16_t inputCurrent = -8 / currentScaleFactor;
        int16_t outputVoltage = -24 / voltageScaleFactor;
        int16_t outputCurrent = -10 / currentScaleFactor;

        split_int16(inputVoltage, &buffer[0], &buffer[1]);
        split_int16(inputCurrent, &buffer[2], &buffer[3]);
        split_int16(outputVoltage, &buffer[4], &buffer[5]);
        split_int16(outputCurrent, &buffer[6], &buffer[7]);

        //std::cout << "Displaying MPPT Test Buffer\n";
        //for (int i = 0; i <= 7; i++)
        //    std::cout << "Data [" << i << "]: " << std::hex << (int)buffer[i] << "\n";
        //std::cout << "\n";
	}

    void test_main() {
        // EXAMPLE OF CALLING THE DECODER -------------------------------------------
        uint32_t received_can_id = 0x200;
        uint8_t buffer[BUF_SIZE];
        get_mppt_test_buffer(buffer);

        // get the decoder function using an iterator on the map
        auto it = DECODERS.find(static_cast<CanID>(received_can_id));
        if (it != DECODERS.end()) { // this checks if the CAN ID received is a valid ID
            auto decoder = it->second; // the value associated with the ID in the map is a pointer to the decoder function
            decoder(buffer); // CALL THE DECODER FUNCTION
            // this will decode the buffer, call the correct parsing function from the CAN Library and then update the signals to display the data
        }

        Client::printData();
    }
}