#include <iostream> // Allow for output and inputs
#include <string>   // Allow strings
#include <vector>   // Allow vectors
#include <limits>   // Used to clear the input
#include <iomanip>  // Include for std::setw to ensure output is viewable

// Contact class to store the information for the phonebook entries
class Contact {
public:
    // Constructor to initialize name and email
    Contact(const std::string& name, const std::string& email)
        : name(name), email(email) {}

    // Getters and setters for name and email
    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    std::string getEmail() const { return email; }
    void setEmail(const std::string& newEmail) { email = newEmail; }

private:
    std::string name;   // Name of the contact
    std::string email;  // Email for the contact
};

// Phonebook class to manage the collection of contacts
class Phonebook {
public:
    // Constructor to initialize with 5 base contacts
    Phonebook() {
        contacts.push_back(Contact("Dr.Charles Conner", "cdconner@captechu.edu"));
        contacts.push_back(Contact("Andrew Mehri", "aamehri@captehu.edu"));
        contacts.push_back(Contact("Mohamed 'Ghazy' Shehata", "mshehata@captechu.edu"));
        contacts.push_back(Contact("Dr.Richard Hansen", "rhhansen@captechu.edu"));
        contacts.push_back(Contact("President Kyra Milbourne", "kmilbourne@captechu.edu"));
        contacts.push_back(Contact("Dr.Christopher Gorham", "clgorham@captechu.edu"));
        }

    // Function to add a new contact
    void addContact() {
        std::string name, email;
        std::cout << "Enter new contact name: ";
        std::getline(std::cin, name);  // Accepts name from user
        std::cout << "Enter new contact email: ";
        std::getline(std::cin, email); // Accepts email from user
        contacts.push_back(Contact(name, email));
        std::cout << "\nContact has been added to the phonebook.\n\n";
    }

    // Function to remove an existing contact
    void removeContact() {
        // Begin by ensuring the list is not empty, if it is alert the user
        if (contacts.empty()) {
            std::cout << "\nYour phonebook is currently empty, no contacts to remove.\n\n";
            return;
        }

        // Present the user with all of the phonebook contacts
        viewPhonebook();
        int index;
        std::cout << "Enter the contact number to remove: ";
        std::cin >> index; // Read in contact index they'd like to remove
        clearInput(); // Clear input buffer

        // Ensure that the number is actually within the list size
        // If it is remove that entry from the vector
        if (index > 0 && index <= contacts.size()) {
            contacts.erase(contacts.begin() + (index - 1));
            std::cout << "\nContact has been removed from your phonebook.\n\n";
        // If not then alert the user that the value they entered is non-existent
        } else {
            std::cout << "\n" << index << " is an invalid contact number.\n\n";
        }
    }

    // Function to view all contacts in the phonebook
    void viewPhonebook() const {
        if (contacts.empty()) {
            std::cout << "\nNo contacts available.\n\n";
            return;
        }

        // Define set column widths to ensure readability for the user
        const int nameWidth = 30;
        const int emailWidth = 30;

         // Use a loop to iterate through the contacts list printing each as it is passed
        std::cout << "\nContact List:\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << std::left << std::setw(3) << i + 1
                      << std::setw(nameWidth) << contacts[i].getName()
                      << std::setw(emailWidth) << contacts[i].getEmail() << "\n";
        }
    }

    // Function to edit an existing contact
    void editContact() {
        // Begin by making sure that the phonebook is not empty
        // If it is alert the user and return
        if (contacts.empty()) {
            std::cout << "\nNo contacts to edit.\n\n";
            return;
        }
        viewPhonebook(); // Present the user with all of the phonebook contacts
        int index;
        std::cout << "Enter the contact number to edit: ";
        std::cin >> index;
        clearInput(); // Clear input buffer

        // Ensure that the index is within range
        if (index > 0 && index <= contacts.size()) {
            // If valid request new name from the user
            std::cout << "Editing contact " << index << "\n";
            std::string newName, newEmail;

            // Request new name
            std::cout << "Enter new name or press enter to leave unchanged: ";
            std::getline(std::cin, newName);
            // If no new name is given keep the old name
            if (!newName.empty()) {
                contacts[index - 1].setName(newName);
            }

            // Request new email
            std::cout << "Enter new email or press enter to leave unchanged: ";
            std::getline(std::cin, newEmail);
            // If no new email is given keep the old email
            if (!newEmail.empty()) {
                contacts[index - 1].setEmail(newEmail);
            }

            std::cout << "\nContact updated successfully.\n\n";
        // If the index if not in range alert the user 
        } else {
            std::cout << "\nInvalid contact number.\n\n";
        }
    }

    // Helper function to clear input buffer
    void clearInput() const {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

private:
    // Vector to store all contacts
    std::vector<Contact> contacts;
};

// Main function! This will fill the phonebook with 5 base contacts, and 
// house the switch case menu calling the other functions based off user choice.
int main() {
    // Create Phonebook object to manage contacts
    Phonebook phonebook;

    // Declares the choice variable used to store the user choice of menu options
    int choice;

    // Do-while loop to repeatedly show menu until exit
    do {
        // Offers the user a menu of different options that can be selected
        std::cout << "\nPhonebook Application\n";
        std::cout << "\t1. Add Contact to Phonebook\n";
        std::cout << "\t2. Remove Contact from Phonebook\n";
        std::cout << "\t3. View Phonebook\n";
        std::cout << "\t4. Edit Contact\n";
        std::cout << "\t5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        phonebook.clearInput(); // Clears the input buffer

        // Switch block is used to call the function that corresponds 
        // with the required menu function
        switch (choice) {
            case 1:
                phonebook.addContact();
                break;
            case 2:
                phonebook.removeContact();
                break;
            case 3:
                phonebook.viewPhonebook();
                break;
            case 4:
                phonebook.editContact();
                break;
            case 5:
                std::cout << "\nClosing the phonebook.\n";
                break;
            default:
                std::cout << "\nNot a valid option. Please enter a valid option.\n";
        }
    } while (choice != 5);  //Do while loop to allow repition until exit

    return 0;
}
