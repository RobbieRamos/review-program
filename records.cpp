#include <iostream>
#include <string>

using namespace std;

// Student class
class Student {
public:
    string firstName;
    string lastName;
    string middleName;
    string course;
    int yearLevel;
};

// Records structure
struct Records {
    Student st;
    Records* next;
};

// Linked List class
class LinkedList {
private:
    Records* head;

public:
    LinkedList() : head(nullptr) {}

    void addStudent();
    void searchStudent();
    void removeStudent();
    void showAll();
    void removeAll();
};

// Function prototypes
void LinkedList::addStudent() {
    Records* newNode = new Records();
    cout << "Enter First Name: ";
    cin >> newNode->st.firstName;
    cout << "Enter Last Name: ";
    cin >> newNode->st.lastName;
    cout << "Enter Middle Name: ";
    cin >> newNode->st.middleName;
    cout << "Enter Course: ";
    cin >> newNode->st.course;
    cout << "Enter Year Level: ";
    cin >> newNode->st.yearLevel;

    newNode->next = head;
    head = newNode;

    cout << "Student added successfully." << endl;
}

void LinkedList::searchStudent() {
    string searchName;
    cout << "Enter Last Name to search: ";
    cin >> searchName;

    Records* current = head;
    while (current != nullptr) {
        if (current->st.lastName == searchName) {
            cout << "Student found!" << endl;
            cout << "First Name: " << current->st.firstName << endl;
            cout << "Last Name: " << current->st.lastName << endl;
            cout << "Middle Name: " << current->st.middleName << endl;
            cout << "Course: " << current->st.course << endl;
            cout << "Year Level: " << current->st.yearLevel << endl;
            return;
        }
        current = current->next;
    }

    cout << "Student not found." << endl;
}

void LinkedList::removeStudent() {
    string removeName;
    cout << "Enter Last Name to remove: ";
    cin >> removeName;

    Records* current = head;
    Records* prev = nullptr;
    while (current != nullptr) {
        if (current->st.lastName == removeName) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Student removed successfully." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Student not found." << endl;
}

void LinkedList::showAll() {
    Records* current = head;
    while (current != nullptr) {
        cout << "First Name: " << current->st.firstName << endl;
        cout << "Last Name: " << current->st.lastName << endl;
        cout << "Middle Name: " << current->st.middleName << endl;
        cout << "Course: " << current->st.course << endl;
        cout << "Year Level: " << current->st.yearLevel << endl;
        cout << "----------------------------------------" << endl;
        current = current->next;
    }
}

void LinkedList::removeAll() {
    Records* current = head;
    Records* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    cout << "All students removed." << endl;
}

int main() {
    LinkedList linkedList;
    int choice;

    do {
        cout << "\nMenu\n";
        cout << "1. Add New Student Record\n";
        cout << "2. Search Student Record\n";
        cout << "3. Remove Student Record\n";
        cout << "4. Show All Students\n";
        cout << "5. Remove All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                linkedList.addStudent();
                break;
            case 2:
                linkedList.searchStudent();
                break;
            case 3:
                linkedList.removeStudent();
                break;
            case 4:
                linkedList.showAll();
                break;
            case 5:
                linkedList.removeAll();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
