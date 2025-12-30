#include <iostream>

#include "Telemetry.h"

int main()
{
    std::cout << "Starting Telemetry V2 Software\n";

    //try {
    //    auto info = SIGNAL_INFO.at(SignalID::MPPT_1_InputVoltage);
    //    std::cout << info.title << std::endl;
    //} 
    //catch (std::out_of_range) {
    //    std::cout << "Signal ID does not exist\n";
    //}



    // EXAMPLE OF CALLING THE DECODER -------------------------------------------
    int16_t received_can_id = 0x300;
    const char* buffer = "hellooo"; // pretend like this is the buffer that was received

    // get the decoder function using an iterator on the map
    auto it = DECODERS.find(received_can_id);
    if (it != DECODERS.end()) { // this checks if the CAN ID received is a valid ID
        auto decoder = it->second; // the value associated with the ID in the map is a pointer to the decoder function
        decoder(buffer); // CALL THE DECODER FUNCTION
        // this will decode the buffer, call the correct parsing function from the CAN Library and then update the signals to display the data
    }
}


/* 

TODO for complete demo: 
- simulate data stream input
- write "app" layer
- message decoder
- put the CAN library in the repo

*/