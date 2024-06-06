#include "Module.h"

// Consturctor implmentation
Module::Module(const string& title, const string& description)
	:title(title), description(description)
{
}

// Getter for the title
string Module::getTitle() const
{
	return title;
}

// Getter for the description
string Module::getDescription() const
{
	return description;
}
