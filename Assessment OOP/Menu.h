#pragma once
#include "Module.h"
#include <vector>
#include <memory>

using namespace std;

class Menu
{
private:
	vector<shared_ptr<Module>> modules; // Vector to store shared pointers to Module objects

public:
	// Method to add a module to the menu
	void addModule(const shared_ptr<Module>& module);

	// Method to display the menu and handle user input
	void display();

};