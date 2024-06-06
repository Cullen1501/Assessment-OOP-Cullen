#pragma once
#include "Module.h"
#include<string>

using namespace std;

// Class simulating a caesar cipher utility, derived from Module
class CaesarCipher : public Module
{
public:
	
	// Constructor initializing the base class with title and description
	CaesarCipher();

	// Override teh run method to provide Caesar Cipher functionalites
	void run() override;

private:

	// Method to encrypt the given text with the spevified shift 
	string encrypt(const string& text, int shift);

	// Method to decrypt the given text with the specified shift 
	string decrypt(const string& text, int shift);

};

