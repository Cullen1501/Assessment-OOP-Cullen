#include "User.h"

// Consturctor implmentation
// Initializes teh username and password with the provided values
User::User(const string& username, const string& password)
	:username(username), password(password)
{
}

// Getter function for the username
// Returns the username of the user
string User::getUsername() const
{
	return username;
}

// Getter function for the password 
// Returns the password of the user
string User::getPasword() const
{
	return password;
}
