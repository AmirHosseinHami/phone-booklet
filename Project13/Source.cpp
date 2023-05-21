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

        case 4: {

            cout << "name of the contact to be searched for: ";
            char name;
            cin >> name;
            getchar();
            bool ifFounded = false;
            for (const auto& contact : contacts) {
                if (contact.name[0] == name) {
                    showCellNumbers(contact);
                    ifFounded = true;
                }
            }
            if (!ifFounded) {
                cout << "contact is not founded." << endl;
            }
            break;

        }

        case 5: {

            cout << "name of the contact to add a cellnumber to: ";
            string name;
            getline(cin, name);
            bool ifFounded = false;
            for (auto& contact : contacts) {
                if (contact.name == name) {
                    CellNumber cellNumber;
                    cout << "type of the cellnumber (e.g. WORK, HOME): ";
                    getline(cin, cellNumber.type);
                    cout << "cellnumber: ";
                    getline(cin, cellNumber.number);
                    contact.cellNumbers.push_back(cellNumber);
                    cout << "cellnumber is added." << endl;
                    ifFounded = true;
                    break;
                }
            }
            if (!ifFounded) {
                cout << "contact is not founded." << endl;
            }
            break;

        }

        case 6: {

            cout << "name of the contact to edit a cellnumber for: ";
            string name;
            getline(cin, name);
            bool ifFounded = false;
            for (auto& contact : contacts) {
                if (contact.name == name) {
                    cout << "type of the cellnumber to edit: ";
                    string type;
                    getline(cin, type);
                    for (auto& cellNumber : contact.cellNumbers) {
                        if (cellNumber.type == type) {
                            cout << "new cellnumber: ";
                            cin >> cellNumber.number;
                            cout << "cellnumber is edited." << endl;
                            ifFounded = true;
                            break;
                        }
                    }
                    break;
                }
            }
            if (!ifFounded) {
                cout << "Contact is not founded." << endl;
            }
            break;

        }

        case 7: {

            cout << "name of the contact to delete a  cellnumber for: ";
            string name;
            getline(cin, name);
            bool ifFounded = false;
            for (auto& contact : contacts) {
                if (contact.name == name) {
                    cout << "type of the phone number to delete: ";
                    string type;
                    getline(cin, type);
                    for (auto it = contact.cellNumbers.begin(); it != contact.cellNumbers.end(); it++) {
                        if (it->type == type) {
                            contact.cellNumbers.erase(it);
                            cout << "cellnumber is deleted." << endl;
                            ifFounded = true;
                            break;
                        }
                    }
                    break;
                }
            }
            if (!ifFounded) {
                cout << "contact is not founded." << endl;
            }
            break;

        }

        case 8: {

            cout << "name of the contact to add to favorite ones: ";
            string name;
            getline(cin, name);
            bool ifFounded = false;
            for (auto& contact : contacts) {
                if (contact.name == name) {
                    favoriteContacts.insert(&contact);
                    cout << "contact is added to favorite ones." << endl;
                    ifFounded = true;
                    break;
                }
            }
            if (!ifFounded) {
                cout << "contact is not founded." << endl;
            }
            break;

        }

        case 9: {

            cout << "name of the contact to remove from favorite ones: ";
            string name;
            getline(cin, name);
            bool ifFounded = false;
            for (auto it = favoriteContacts.begin(); it != favoriteContacts.end(); it++) {
                if ((*it)->name == name) {
                    favoriteContacts.erase(it);
                    cout << "contact is removed from favorite ones." << endl;
                    ifFounded = true;
                    break;
                }
            }
            if (!ifFounded) {
                cout << "contact is not founded." << endl;
            }
            break;

        }


        case 10: {

            cout << "name of the contact to be moved: ";
            string name;
            getline(cin, name);
            auto it = favoriteContacts.begin();
            while (it != favoriteContacts.end() && (*it)->name != name) {
                it++;
            }
            if (it != favoriteContacts.end()) {
                favoriteContacts.erase(it);
                favoriteContacts.insert(*it);
                cout << "contact is moved." << endl;
            }
            else {
                cout << "contact is not founded in favorite ones." << endl;
            }
            break;

        }

        case 11: {

            cout << "All contacts:" << endl;
            sort(contacts.begin(), contacts.end(), compareBase);
            for (const auto& contact : contacts) {
                cout << "  " << contact.name << endl;
            }
            break;

        }