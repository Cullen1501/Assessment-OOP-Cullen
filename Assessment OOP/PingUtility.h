#pragma once
#include "Module.h"
#include <string>

using namespace std;

// Class simulating a Ping utility, derived from Module
class PingUtility : public Module
{
public:

	// Constructor itnitalizing the base class with title and description
	PingUtility();

	// Override the run method to rpovide Ping fuctionalites 
	void run() override;

private:

	//Methjod to perfrom the ping operation
	void ping(const string& address);

};
