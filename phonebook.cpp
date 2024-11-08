#include <iostream> // Allow for output and inputs
#include <string>   // Allow strings
#include <vector>   // Allow vectors
#include <limits>   // Used to clear the input
#include <iomanip>  // Include for std::setw to ensure output is viewable

// Creates the Contact struct which stores the information for the phonebook entries
struct Contact {
    std::string name;   // Name of the contact
    std::string email;  // Email for the contact
};

// Function declarations
// All functions are passed a reference to the contact struct
// Function to add a contact
void addContact(std::vector<Contact>& contacts); 
// Function to remove a contact           
void removeContact(std::vector<Contact>& contacts);
// Function to view the phonebook    
void viewPhonebook(const std::vector<Contact>& contacts); 
// Function to edit a contact
void editContact(std::vector<Contact>& contacts);
// Function to clear the input buffer
void clearInput();

int main() {
    std::vector<Contact> contacts = {
        {"Dr.Charles Conner", "cdconner@captechu.edu"},
        {"Andrew Mehri", "aamehri@captehu.edu"},
        {"Mohamed 'Ghazy' Shehata", "mshehata@captechu.edu"},
        {"Dr.Richard Hansen", "rhhansen@captechu.edu"},
        {"President Kyra Milbourne", "kmilbourne@captechu.edu"},
        {"Dr.Christopher Gorham", "clgorham@captechu.edu"}
    };

    int choice;

    do {
        // Display menu
        std::cout << "\nPhonebook Application\n";
        std::cout << "\t1. Add Contact to Phonebook\n";
        std::cout << "\t2. Remove Contact from Phonebook\n";
        std::cout << "\t3. View Phonebook\n";
        std::cout << "\t4. Edit Contact\n";
        std::cout << "\t5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearInput(); // Clear input buffer

        // Switch block to handle each menu option
        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                removeContact(contacts);
                break;
            case 3:
                viewPhonebook(contacts);
                break;
            case 4:
                editContact(contacts);
                break;
            case 5:
                std::cout << "\nClosing the phonebook.\n";
                break;
            default:
                std::cout << "\nNot a valid option. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}


// Function to add a new contact
void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Enter new contact name: ";
    std::getline(std::cin, newContact.name);
    std::cout << "Enter new contact email: ";
    std::getline(std::cin, newContact.email);
    contacts.push_back(newContact);
    std::cout << "\nContact has been added to the phonebook.\n\n";
}

// Function to remove an existing contact
void removeContact(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "\nYour phonebook is currently empty, no contacts to remove.\n\n";
        return;
    }
    viewPhonebook(contacts);
    int index;
    std::cout << "Enter the contact number to remove: ";
    std::cin >> index;
    clearInput(); // Clear input buffer
    if (index > 0 && index <= contacts.size()) {
        contacts.erase(contacts.begin() + (index - 1));
        std::cout << "\nContact has been removed from your phonebook.\n\n";
    } else {
        std::cout << "\n" << index << " is an invalid contact number.\n\n";
    }
}

// Function to view all contacts
void viewPhonebook(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "\nNo contacts available.\n\n";
        return;
    }

    // Set fixed column widths
    const int nameWidth = 30;
    const int emailWidth = 30;

    std::cout << "\nContact List:\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << std::left << std::setw(3) << i + 1
                  << std::setw(nameWidth) << contacts[i].name
                  << std::setw(emailWidth) << contacts[i].email << "\n";
    }
}

// Function to edit an existing contact
void editContact(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "\nNo contacts to edit.\n\n";
        return;
    }
    viewPhonebook(contacts);
    int index;
    std::cout << "Enter the contact number to edit: ";
    std::cin >> index;
    clearInput(); // Clear input buffer
    if (index > 0 && index <= contacts.size()) {
        std::cout << "Editing contact " << index << "\n";
        std::cout << "Enter new name or press enter to leave unchanged: ";
        std::string newName;
        std::getline(std::cin, newName);
        if (!newName.empty()) {
            contacts[index - 1].name = newName;
        }
        std::cout << "Enter new email or press enter to leave unchanged: ";
        std::string newEmail;
        std::getline(std::cin, newEmail);
        if (!newEmail.empty()) {
            contacts[index - 1].email = newEmail;
        }
        std::cout << "\nContact updated successfully.\n\n";
    } else {
        std::cout << "\nInvalid contact number.\n\n";
    }
}

// Helper function to clear input buffer
void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
