#include "CaesarCipher.h"
#include <iostream>

using namespace std;

// shift = the nubmer of times a letter move up or down

// Constructor implementation 
// Calls the base class constructor to initilize the title and description
CaesarCipher::CaesarCipher() : Module("Caesar Cipher", "Encrypts and decrypts text using Caesar Cipher")
{
}
	// Override the run method to provide Caesar Cipher funcitonalites 
	void CaesarCipher::run() 
	{
		int choice;

		// Display the Caesat Cipher menu
		cout << "Caesar Cipher Menu:\n";
		cout << "1. Encrypt\n";
		cout << "2. Decrypt\n";
		cout << "Enter Choice: ";
		cin >> choice;

		// Input text to be encrypted or decrypted

		string text;
		int shift;
		cout << "Enter Text: ";
		cin.ignore(); // Ignore the newline character left in the buffer
		getline(cin, text);
		cout << "Enter shift value: ";
		cin >> shift;

		// Process based on user's choice 

		if (choice == 1)
		{
			// Encrypt the text
			string encryptedText = encrypt(text, shift);
			cout << "Encyrpted text: " << encryptedText << endl;
		}
		else if (choice == 2)
		{
			// Decyrpt the text
			string decryptedText = decrypt(text, shift);
			cout << "Decrypted text: " << decryptedText << endl;
		}
		else
		{
			// Handle invalid choice
			cout << "Invalid choice. " << endl;
		}

	}

	// Method to encrypt the given text with the specified shift
	string CaesarCipher::encrypt(const string& text, int shift)
	{
		string result = "";
		shift = shift % 26; // Ensure the shift is within the range of the alphabet 

		// Process each character in the text 
		for (char c : text)
		{
			if (isalpha(c))
			{
				// Determin the base character ('a' for lowercase, 'A' for uppercase

				char base = islower(c) ? 'a' : 'A';

				// Calcualate the new character after applying the shift

				result += (c - base + shift) % 26 + base;
			}
			else
			{
				result += c; // Non-alphabetic characters are not changed
			}
		}
		return result;
	}

	// Method to decvrypt the given text with the specified shift 
	string CaesarCipher::decrypt(const string& text, int shift)
	{
		return encrypt(text, 26 - (shift % 26)); // Decryption is the same as encryption with (26 -shift)
	}
