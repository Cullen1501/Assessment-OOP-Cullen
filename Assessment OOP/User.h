#pragma once
#include <string>

using namespace std;

// Class representing a user with a username and password
class User
{
private:
	string username; // Username of the user
	string password; // Password of the user

public:
	// Constructor to initialize the username and password
	User(const string& username, const string& password);

		// Getter for the username
		string getUsername() const;

		// Getter for the password
		string getPasword() const;

};

