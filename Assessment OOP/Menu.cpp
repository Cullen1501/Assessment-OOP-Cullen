#include "Menu.h"
#include <iostream>
#include <limits> // For std::numeric_limits

using namespace std;

void Menu::addModule(const shared_ptr<Module>& module)
{
    modules.push_back(module); // Add the shared pointer to the modules vector
}

void Menu::display()
{
    int choice; // Variable to store user's choice 
    do
    {
        // Display the menu options
        cout << "menu:\n";
        for (size_t i = 0; i < modules.size(); ++i)
        {
            // Display each module's title and description
            cout << i + 1 << ". " << modules[i]->getTitle() << ": " << modules[i]->getDescription() << endl;
        }

        // Display the quit option
        cout << modules.size() + 1 << ". Quit" << endl;
        cout << "Enter choice: ";

        // Read user input
        cin >> choice;

        // Check if the input is invalid (e.g., a letter was entered)
        if (cin.fail())
        {
            // Clear the error state of the stream
            cin.clear();

            // Ignore the rest of the line to discard the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Inform the user about the invalid input
            cout << "Invalid input. Please enter a number." << endl;
        }
        else
        {
            // Check if the choice is within the valid range of modules
            if (choice > 0 && choice <= modules.size())
            {
                // Display the title of the selected module 
                cout << "You Selected: " << modules[choice - 1]->getTitle() << endl;

                // Run the selected module 
                modules[choice - 1]->run();
            }
            // Check if the user has chosen to quit
            else if (choice != modules.size() + 1)
            {
                // Inform the user about the invalid choice
                cout << "Invalid Choice. Please try again." << endl;
            }
        }
    } while (choice != modules.size() + 1); // Repeat until the user chooses to quit 
}
