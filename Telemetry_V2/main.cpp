#include <iostream>

#include "Simulation.hpp"

#include "Telemetry.h"

int main()
{
    std::cout << "Starting Telemetry V2 Software\n";

    // Start database and other resources
    // Then start the app

    //Telemetry t;
    //t.app_main();
    Simulation::test_main();
}