#include "Menu.h"
#include "UserGenerator.h"
#include "PingUtility.h"
#include "CaesarCipher.h"
#include <ctime>
#include <cstdio>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator

	Menu menu; // Create a menu object

	// add modules
	menu.addModule(make_shared<UserGenerator>());
	menu.addModule(make_shared<PingUtility>());
	menu.addModule(make_shared<CaesarCipher>());

	// Display the menu and handle user imput
	menu.display(); // Display the manu options

	return 0; // Return 0 indicate successful completion 
}



