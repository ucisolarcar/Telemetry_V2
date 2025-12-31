#include <iostream>

#include "Simulation.hpp"

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

    Simulation::test_main();
}


/* 

TODO for complete demo: 
- simulate data stream input (just copy from the CAN tests)
- write message decoders

*/