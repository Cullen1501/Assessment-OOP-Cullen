#include "PingUtility.h"
#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <stdexcept>
#include <cstdio>


using namespace std;

// Constructor implementation
// Calls the base class constructor to initialize the title and description
PingUtility::PingUtility() : Module("Ping Utility", "Pings a server")
{
}
// Function to execute a system command and capoture its output
string xec(const char* cmd)
{
	array<char, 128> buffer; // create a character array buffer
	string result; // creat a string to store the result
	unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);

	// open a pipe to execute the command 

	if (!pipe) 
	{
		throw runtime_error("_popen() failed!"); // Throw an exception if opening the pipe fails 
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
	{
		result += buffer.data(); // Append the command output to the result string
	}
	return result; // return the result string
}

// Override run method to ping the given address 
void PingUtility::run()
{
	// Declare a string to store the address 
	string address;
	cout << "Enter IP Address: ";// Propmt the user for imput
	cin >> address;
	// Read the imput address

	// Construct the ping command for windows 

#ifdef _WIN32 
	string command = "ping -n 1 " + address; // For windows
#endif

	try
	{
		string command = "ping -n 1 " + address;
		string output = xec(command.c_str());

		//find and print the ping time from the output 
		istringstream stream(output); // create a string stream for parsing

		string line;

		//declare a string to store each line of an output

		while (getline(stream, line))
		{
			// Check if the line contains "lost ="
			size_t lostPos = line.find("Lost =");
			if (lostPos != string::npos)
			{
				// Extract the number of lost packets 
				string lostPackets = line.substr(lostPos + 6, line.find("", lostPos) - lostPos - 6);
				cout << "Packets Lost: " << lostPackets << endl;
			}

			// Check if the line contains "minimum ="
			size_t minPos = line.find("Minimum =");
			if (minPos != string::npos)
			{
				// If "Minimum =" is found the ping was successful
				cout << "Ping to " << address << " was successful!" << endl;
				break;
			}
		}
	}
	catch (const exception& e) // Catch any exceptions thrown during execption
	{
		cerr << "Error exectuing ping command: " << e.what() << endl; // Print error message 
	}
}