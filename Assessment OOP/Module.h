#pragma once
#include <string>

using namespace std;

// Abstract base class representing a generic module in the seecurity tool
class Module
{
protected:
	string title; // Title of the module 
	string description; // Description of the module 

public:
	// Constructor to initialize the title and description of the module
	Module(const string& title, const string& description);

	// Pure virtul function to be implemented by derived classes
	virtual void run() = 0;

	// Getter for the modules title
	string getTitle() const;

	// Getter for modules description
	string getDescription() const;

};


