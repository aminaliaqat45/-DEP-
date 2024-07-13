#include <iostream>
#include <vector>
#include <string>

class Contact {
public:
    std::string name;
    std::string phoneNumber;

    Contact(std::string n, std::string p) : name(n), phoneNumber(p) {}
};

void addContactToPhonebook(std::vector<Contact> &phonebook) {
    std::string name, phoneNumber;
    std::cout << "Enter the contact's name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter the contact's phone number: ";
    std::getline(std::cin, phoneNumber);
    phonebook.push_back(Contact(name, phoneNumber));
    std::cout << "Contact added successfully! You can now view or manage your contacts.\n\n";
}

void viewContactsInPhonebook(const std::vector<Contact> &phonebook) {
    if (phonebook.empty()) {
        std::cout << "You don't have any contacts yet. Please add some!\n\n";
        return;
    }
    std::cout << "Here are your contacts:\n";
    for (size_t i = 0; i < phonebook.size(); ++i) {
        std::cout << i + 1 << ". Name: " << phonebook[i].name
                  << ", Phone Number: " << phonebook[i].phoneNumber << '\n';
    }
    std::cout << '\n';
}

void deleteContactFromPhonebook(std::vector<Contact> &phonebook) {
    int contactNumber;
    viewContactsInPhonebook(phonebook);
    std::cout << "Enter the number of the contact you'd like to delete: ";
    std::cin >> contactNumber;
    if (contactNumber < 1 || contactNumber > phonebook.size()) {
        std::cout << "Sorry, that's not a valid contact number.\n\n";
        return;
    }
    phonebook.erase(phonebook.begin() + contactNumber - 1);
    std::cout << "Contact deleted successfully! You can now view or manage your remaining contacts.\n\n";
}

void showMainMenu() {
    std::cout << "Welcome to the Contact Management System!\n";
    std::cout << "What would you like to do?\n";
    std::cout << "1. Add a new contact\n";
    std::cout << "2. View all contacts\n";
    std::cout << "3. Delete a contact\n";
    std::cout << "4. Exit the system\n";
    std::cout << "Please enter your choice: ";
}

int main() {
    std::vector<Contact> phonebook;
    int choice;

    while (true) {
        showMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContactToPhonebook(phonebook);
                break;
            case 2:
                viewContactsInPhonebook(phonebook);
                break;
            case 3:
                deleteContactFromPhonebook(phonebook);
                break;
            case 4:
                std::cout << "Thank you for using the Contact Management System! Goodbye.\n";
                return 0;
            default:
                std::cout << "Sorry, that's not a valid choice. Please try again.\n\n";
        }
    }
    return 0;
}
