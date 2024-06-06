#pragma once

#include "module.h"
#include"User.h"
#include <vector>
#include <string>


class UserGenerator : public Module 
{
private:

	// Vector to store generated users
	vector <User> users;

	// Private method to generate a random password
	string generatePassword();

public:
	
	// Constructor initializing the base class with title and description
	UserGenerator();

	//Override the run method to generate and display users
	void run() override;

};

