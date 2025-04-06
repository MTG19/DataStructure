//
// Created by israa on 3/25/2025.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MaxNameLength = 100;
const int MaxContactLength = 100;
const int MaxDateLength = 11;

const int CUR_YEAR = 2025;
const int CUR_MONTH = 3;
const int CUR_DAY = 25;

void toLowerCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

bool isDateFormatValid(const char* date) {
    if (strlen(date) != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (date[i] < '0' || date[i] > '9') return false;
    }
    int year = atoi(date);
    int month = atoi(date + 5);
    int day = atoi(date + 8);
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    return true;
}

bool isDateNotPast(const char* date) {
    int year = atoi(date);
    int month = atoi(date + 5);
    int day = atoi(date + 8);
    if (year < CUR_YEAR) return false;
    if (year == CUR_YEAR && month < CUR_MONTH) return false;
    if (year == CUR_YEAR && month == CUR_MONTH && day < CUR_DAY) return false;
    return true;
}

class Guest {
private:
    char name[MaxNameLength];
    char contact[MaxContactLength];
    char iftar_date[MaxDateLength];

public:
    Guest(const char* n, const char* c, const char* d) {
        strcpy(name, n);
        toLowerCase(name);
        strcpy(contact, c);
        strcpy(iftar_date, d);
    }

    void display_guest() const {
        cout.width(15);
        cout << left << name << " | ";
        cout.width(25);
        cout << left << contact << " | ";
        cout.width(12);
        cout << left << iftar_date << endl;
    }

    void update_invitation(const char* new_date) {
        strcpy(iftar_date, new_date);
    }

    const char* getName() const {
        return name;
    }
    const char* getIftarDate() const {
        return iftar_date;
    }
};

class IftarManager {
private:
    Guest** guest_list;
    int count;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        Guest** newList = new Guest*[newCapacity];
        for (int i = 0; i < count; i++) {
            newList[i] = guest_list[i];
        }
        delete [] guest_list;
        guest_list = newList;
        capacity = newCapacity;
    }

public:
    IftarManager() {
        capacity = 10;
        count = 0;
        guest_list = new Guest*[capacity];
    }

    ~IftarManager() {
        for (int i = 0; i < count; i++) {
            delete guest_list[i];
        }
        delete [] guest_list;
    }

    void add_guest(Guest* guest) {
        if (count >= capacity) {
            resize();
        }
        guest_list[count++] = guest;
    }

    void display_all_guests() const {
        if (count == 0) {
            cout << "No guests to display.\n";
            return;
        }
        cout << "----------------------------------------------------------\n";
        cout << "                      GUEST LIST\n";
        cout << "----------------------------------------------------------\n";
        cout.width(15);
        cout << left << "Name" << " | ";
        cout.width(25);
        cout << left << "Contact" << " | ";
        cout.width(12);
        cout << left << "Iftar Date" << endl;
        cout << "----------------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            guest_list[i]->display_guest();
        }
        cout << "----------------------------------------------------------\n";
    }

    void update_guest_invitation(const char* searchName, const char* new_date) {
        char lowerName[MaxNameLength];
        strcpy(lowerName, searchName);
        toLowerCase(lowerName);
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (strcmp(guest_list[i]->getName(), lowerName) == 0) {
                cout << "Updating invitation for " << lowerName << "...\n";
                guest_list[i]->update_invitation(new_date);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Guest \"" << searchName << "\" not found!\n";
        }
    }

    void sort_guest_list() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (strcmp(guest_list[j]->getIftarDate(), guest_list[j+1]->getIftarDate()) > 0) {
                    Guest* temp = guest_list[j];
                    guest_list[j] = guest_list[j+1];
                    guest_list[j+1] = temp;
                }
            }
        }
        cout << "Guest list sorted by date.\n";
    }

    void send_reminder(const char* date) const {
        cout << "\nSending reminders for date: " << date << "\n";
        bool anyReminder = false;
        for (int i = 0; i < count; i++) {
            if (strcmp(guest_list[i]->getIftarDate(), date) == 0) {
                cout << "Reminder sent to " << guest_list[i]->getName()
                     << ": Your Iftar invitation is on " << guest_list[i]->getIftarDate() << "!\n";
                anyReminder = true;
            }
        }
        if (!anyReminder) {
            cout << "No guests found with the date " << date << ".\n";
        }
        cout << "May your Iftar gatherings be full of warmth and blessings!\n";
    }
};

int main()
{
    IftarManager manager;
    cout << "                                        Welcome to Iftar Manager!\n";
    int n;
    cout << "Enter number of initial guests: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        char name[MaxNameLength];
        char contact[MaxContactLength];
        char date[MaxDateLength];

        cout << "\nGuest " << (i + 1) << ":\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter contact: ";
        cin >> contact;
        cout << "Enter iftar date (YYYY-MM-DD): ";
        cin >> date;

        if (!isDateFormatValid(date)) {
            cout << "Invalid date format. Skipping this guest.\n";
            continue;
        }
        if (!isDateNotPast(date)) {
            cout << "Date is in the past. Skipping this guest.\n";
            continue;
        }

        Guest* newGuest = new Guest(name, contact, date);
        manager.add_guest(newGuest);
    }

    bool keepRunning = true;
    while (keepRunning)
    {
        int choice;
        do {
            cout << "\n==========================\n";
            cout << "    IFTAR MANAGER MENU    \n";
            cout << "==========================\n";
            cout << "1. Add a new guest\n";
            cout << "2. Display all guests\n";
            cout << "3. Update a guest invitation date\n";
            cout << "4. Sort guests by date\n";
            cout << "5. Send reminders for a specific date\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: {
                        char name[MaxNameLength], contact[MaxContactLength], date[MaxDateLength];
                        cout << "Enter guest name: ";
                        cin >> name;
                        cout << "Enter guest contact: ";
                        cin >> contact;
                        cout << "Enter iftar date (YYYY-MM-DD): ";
                        cin >> date;

                        if (!isDateFormatValid(date)) {
                            cout << "Error: Date format is invalid. Please use YYYY-MM-DD.\n";
                            break;
                        }
                        if (!isDateNotPast(date)) {
                            cout << "Error: The date entered is in the past. Please enter a valid future date.\n";
                            break;
                        }
                        Guest* newGuest = new Guest(name, contact, date);
                        manager.add_guest(newGuest);
                        cout << "Guest added successfully.\n";
                        break;
                }
                case 2: {
                        manager.display_all_guests();
                        break;
                }
                case 3: {
                        char name[MaxNameLength], newDate[MaxDateLength];
                        cout << "Enter the guest's name to update: ";
                        cin >> name;
                        cout << "Enter the new date (YYYY-MM-DD): ";
                        cin >> newDate;
                        if (!isDateFormatValid(newDate)) {
                            cout << "Error: Date format is invalid. Please use YYYY-MM-DD.\n";
                            break;
                        }
                        if (!isDateNotPast(newDate)) {
                            cout << "Error: The new date entered is in the past.\n";
                            break;
                        }
                        manager.update_guest_invitation(name, newDate);
                        break;
                }
                case 4: {
                        manager.sort_guest_list();
                        break;
                }
                case 5: {
                        char date[MaxDateLength];
                        cout << "Enter the date (YYYY-MM-DD) for sending reminders: ";
                        cin >> date;
                        if (!isDateFormatValid(date)) {
                            cout << "Error: Date format is invalid. Please use YYYY-MM-DD.\n";
                            break;
                        }
                        manager.send_reminder(date);
                        break;
                }
                case 6: {
                        cout << "Exiting the program...\n";
                        keepRunning = false;
                        break;
                }
                default: {
                        cout << "Invalid choice. Please try again.\n";
                        break;
                }
            }

            if (keepRunning) {
                char cont;
                cout << "\nDo you want to perform another operation? (y/n): ";
                cin >> cont;
                if (cont == 'n' && cont == 'N' ) {
                    keepRunning = false;
                    cout << "Goodbye!\n";
                }
            }

        } while (false);
    }

    return 0;
}

