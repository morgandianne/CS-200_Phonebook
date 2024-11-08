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

// Main function! This will fill the phonebook with 5 base contacts, and 
// house the switch case menu calling the other functions based off user choice.
int main() {
    // 5 initial contacts populated into the phonebook
    std::vector<Contact> contacts = {
        {"Dr.Charles Conner", "cdconner@captechu.edu"},
        {"Andrew Mehri", "aamehri@captehu.edu"},
        {"Mohamed 'Ghazy' Shehata", "mshehata@captechu.edu"},
        {"Dr.Richard Hansen", "rhhansen@captechu.edu"},
        {"President Kyra Milbourne", "kmilbourne@captechu.edu"},
        {"Dr.Christopher Gorham", "clgorham@captechu.edu"}
    };

    // Declares the choice variable used to store the user choice of menu options
    int choice;

    // Do while loop, this ensures that the menu is presented to the user 
    // repeatedly until they chose to leave (when the value is NOT 5)
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
        clearInput(); // Clears the input buffer

        // Switch block is used to call the function that corresponds 
        // with the required menu function
        switch (choice) {
            case 1: // Add contact case calls the addContact function
                addContact(contacts);
                break;
            case 2: // Remove contact case calls the removeContact function
                removeContact(contacts);
                break;
            case 3: // View phonebook case calls the viewPhonebook function
                viewPhonebook(contacts);
                break;
            case 4: // Edit contact case calls the editContact function
                editContact(contacts);
                break;
            case 5: // Case to break the do-while loop, exit case
                std::cout << "\nClosing the phonebook.\n";
                break;
            default:
                std::cout << "\nNot a valid option. Please enter a valid option.\n";
        }
    } while (choice != 5); //Do while loop to allow repition until exit

    return 0;
}


// Function to add a new contact
void addContact(std::vector<Contact>& contacts) {
    Contact newContact;                         // create new contact object
    std::cout << "Enter new contact name: ";    
    std::getline(std::cin, newContact.name);    // Accepts name from user
    std::cout << "Enter new contact email: ";   
    std::getline(std::cin, newContact.email);   // Accepts email from user
    contacts.push_back(newContact);
    // push back is used to add the new contact information to the end of the vector
    std::cout << "\nContact has been added to the phonebook.\n\n";
}

// Function to remove an existing contact
void removeContact(std::vector<Contact>& contacts) {
    // Begin by ensuring the list is not empty, if it is alert the user
    if (contacts.empty()) {
        std::cout << "\nYour phonebook is currently empty, no contacts to remove.\n\n";
        return;
    }
    // Present the user with all of the phonebook contacts
    viewPhonebook(contacts);

    // Ask the user which number from the context list they'd like removed 
    // This is the index value
    int index;
    std::cout << "Enter the contact number to remove: ";
    std::cin >> index;
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

// Function to view the phonebook
void viewPhonebook(const std::vector<Contact>& contacts) {
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
                  << std::setw(nameWidth) << contacts[i].name
                  << std::setw(emailWidth) << contacts[i].email << "\n";
    }
}

// Function to edit an existing contact
void editContact(std::vector<Contact>& contacts) {
    // Begin by making sure that the phonebook is not empty
    // If it is alert the user and return
    if (contacts.empty()) {
        std::cout << "\nNo contacts to edit.\n\n";
        return;
    }

    // Present the user with all of the phonebook contacts
    viewPhonebook(contacts);

    // Ask the user which index they would like to edit
    int index;
    std::cout << "Enter the contact number to edit: ";
    std::cin >> index;
    clearInput(); // Clear input buffer

    // Ensure that the index is within range
    if (index > 0 && index <= contacts.size()) {
        std::cout << "Editing contact " << index << "\n";
        // If valid request new name from the user
        std::cout << "Enter new name or press enter to leave unchanged: ";
        std::string newName;
        std::getline(std::cin, newName);
        // If no new name is given keep the old name
        if (!newName.empty()) {
            contacts[index - 1].name = newName;
        }
        // If valid request new email from the user
        std::cout << "Enter new email or press enter to leave unchanged: ";
        std::string newEmail;
        std::getline(std::cin, newEmail);
        // If no new email is given keep the old email
        if (!newEmail.empty()) {
            contacts[index - 1].email = newEmail;
        }
        std::cout << "\nContact updated successfully.\n\n";
    // If the index if not in range alert the user 
    } else {
        std::cout << "\nInvalid contact number.\n\n";
    }
}

// Helper function to clear input buffer
void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
