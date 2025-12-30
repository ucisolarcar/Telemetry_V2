#include <iostream>

#include "Telemetry.h"

int main()
{
    std::cout << "Starting Telemetry V2 Software\n";

    try {
        auto info = SIGNAL_INFO.at(SignalID::MPPT_1_InputVoltage);
        std::cout << info.title << std::endl;
    } 
    catch (std::out_of_range) {
        std::cout << "Signal ID does not exist\n";
    }
}


/* 

TODO for complete demo: 
- simulate data stream input
- write "app" layer
- message decoder
- put the CAN library in the repo

*/