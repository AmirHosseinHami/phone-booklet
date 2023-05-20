#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include<algorithm>
using namespace std;

struct CellNumber {
    string number;
    string type;
};

struct Contact {
    string name;
    vector<CellNumber> cellNumbers;
};

bool compareBase(Contact c1, Contact c2) {
    return c1.name.compare(c2.name) < 0;
}

void showCellNumbers(const Contact& contact) {
    cout << "Cell numbers for " << contact.name << ":" << endl;
    for (const auto& cellNumber : contact.cellNumbers) {
        cout << "  " << cellNumber.type << ": " << cellNumber.number << endl;
    }
}


int main() {
    vector<Contact> contacts;
    set<Contact*> favoriteContacts;

    while (1) {

        cout << "1. Adding a contact" << endl;
        cout << "2. Editing a contact" << endl;
        cout << "3. Deleting a contact" << endl;
        cout << "4. Searching for a contact" << endl;
        cout << "5. Adding a  cellnumber" << endl;
        cout << "6. Editing a cellnumber" << endl;
        cout << "7. Deleting a cellnumber" << endl;
        cout << "8. Adding a contact to favorite ones" << endl;
        cout << "9. Removing a contact from favorite ones" << endl;
        cout << "10. Changing the order of favorite contacts" << endl;
        cout << "11. Showing all contacts" << endl;
        cout << "12. Showing all  cellnumbers for a contact" << endl;
        cout << "13. Showing all favorite contacts" << endl;
        cout << "14. Exit" << endl;
        cout << "enter your desired option:";

        int input1;
        cin >> input1;
        getchar();

        switch (input1) {

        case 1: {

            string name;
            Contact contact;
            cout << "name of the contact: ";
            getline(cin, name);
            contact.name = name;
            contacts.push_back(contact);
            cout << "contact is added." << endl;
            break;

        }

        case 2: {

            cout << "name of the contact to edit: ";
            string name;
            getline(cin, name);
            bool ifFounded = false;
            for (auto& contact : contacts) {
                if (contact.name == name) {
                    cout << "new name of the contact: ";
                    getline(cin, contact.name);
                    cout << "Contact is edited." << endl;
                    ifFounded = true;
                    break;
                }
            }
            if (!ifFounded) {
                cout << "contact is not founded." << endl;
            }
            break;

        }

        case 3: {

            cout << "name of the contact to delete: ";
            string name;
            getline(cin, name);
            bool ifFounded = false;
            for (auto it = contacts.begin(); it != contacts.end(); it++) {
                if (it->name == name) {
                    contacts.erase(it);
                    cout << "contact is deleted." << endl;
                    ifFounded = true;
                    break;
                }
            }
            if (!ifFounded) {
                cout << "contact is not founded." << endl;
            }
            break;

        }