#include "UserGenerator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Constructor implementation 
// Calls the base class constructor to initialize the title and dewscription
UserGenerator::UserGenerator() : Module("User Generator", "Generates users with passwords")
{
}

// Method to generate a random password
// Ensures the password contains at least one uppercase letter and one digit 
string
UserGenerator::generatePassword()
{
	const int length = 10; // Password length
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string password;
	bool hasUpper = false, hasDigit = false;

	// Loop until the generated password contains at least one uppercase letter and one digit 
	while (!hasUpper || !hasDigit)
	{
		password.clear();
		hasUpper = false;
		hasDigit = false;

		for (int i = 0; i < length; ++i)
		{
			char c = charset[rand() % charset.size()];

			if (isdigit(c)) hasDigit = true;
			if (isupper(c)) hasUpper = true;
			password += c;
		}
	}
	return password;
}

// Override run method to generate and display users
void UserGenerator::run()
{
	// List of predefined usernames
	
	vector <string> usernames = { "user1", "user2", "user3" };

	// Generate a User object for each username with a random password 
	for (const auto& username : usernames)
	{
		users.emplace_back(username, generatePassword());
	}

	// Display the generated users
	for (const auto& user : users)
	{
		cout << "Username: " << user.getUsername() << " Password: " << user.getPasword() << endl;
	}
}