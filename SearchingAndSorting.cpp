#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float sgpa;
    Student() : rollNo(0), name(""), sgpa(0.0f) {}
    Student(int r, string n, float s) : rollNo(r), name(n), sgpa(s) {}
};

// Bubble Sort
void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// Insertion Sort based on Name
void insertionSort(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

// Function to search students by SGPA
void searchBySGPA(Student students[], int n, float sgpa) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].sgpa == sgpa) {
            if (!found) {
                cout << "Students with SGPA " << sgpa << ":\n";
                found = true;
            }
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: "
                 << students[i].sgpa << "\n";
        }
    }
    if (!found) {
        cout << "No student found with SGPA " << sgpa << ".\n";
    }
}

// Linear Search by Name
void linearSearchByName(Student students[], int n, const string &name) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].name == name) {
            if (!found) {
                cout << "Students with Name \"" << name << "\":\n";
                found = true;
            }
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: "
                 << students[i].sgpa << "\n";
        }
    }
    if (!found) {
        cout << "No student found with Name \"" << name << "\".\n";
    }
}

// Binary Search by Name
void binarySearchByName(Student students[], int n, const string &name) {
    insertionSort(students, n);
    int left = 0, right = n - 1;
    bool found = false;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].name == name) {
            // Collect all occurrences
            int temp = mid;
            while (temp >= 0 && students[temp].name == name) {
                if (!found) {
                    cout << "Students with Name \"" << name << "\":\n";
                    found = true;
                }
                cout << "Roll No: " << students[temp].rollNo << ", Name: " << students[temp].name <<
                     ", SGPA: " << students[temp].sgpa << "\n";
                temp--;
            }
            temp = mid + 1;
            while (temp < n && students[temp].name == name) {
                cout << "Roll No: " << students[temp].rollNo << ", Name: " << students[temp].name <<
                     ", SGPA: " << students[temp].sgpa << "\n";
                temp++;
            }
            break;
        } else if (students[mid].name < name) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "No student found with Name \"" << name << "\".\n";
    }
}

int main() {
    const int MAX_STUDENTS = 100; // Maximum number of students
    Student students[MAX_STUDENTS];
    int n;
    
    cout << "Enter number of students: ";
    cin >> n;
    
    if (n > MAX_STUDENTS) {
        cout << "Number of students exceeds the maximum limit of " << MAX_STUDENTS << ".\n";
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        int rollNo;
        string name;
        float sgpa;
        
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> rollNo;
        cin.ignore(); // Clear the newline character from the buffer
        cout << "Name: ";
        getline(cin, name); // Use getline to read names with spaces
        cout << "SGPA: ";
        cin >> sgpa;
        
        students[i] = Student(rollNo, name, sgpa);
    }
    
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display students sorted by Roll Number\n";
        cout << "2. Display students sorted by Name\n";
        cout << "3. Search students by SGPA\n";
        cout << "4. Search student by Name (Linear Search)\n";
        cout << "5. Search student by Name (Binary Search)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the buffer
        
        switch (choice) {
            case 1: {
                bubbleSort(students, n);
                cout << "Students sorted by Roll Number:\n";
                for (int i = 0; i < n; i++) {
                    cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << "\n";
                }
                break;
            }
            case 2: {
                insertionSort(students, n);
                cout << "Students sorted by Name:\n";
                for (int i = 0; i < n; i++) {
                    cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << "\n";
                }
                break;
            }
            case 3: {
                float sgpa;
                cout << "Enter SGPA to search: ";
                cin >> sgpa;
                searchBySGPA(students, n, sgpa);
                break;
            }
            case 4: {
                string name;
                cout << "Enter Name to search: ";
                getline(cin, name);
                linearSearchByName(students, n, name);
                break;
            }
            case 5: {
                string name;
                cout << "Enter Name to search: ";
                getline(cin, name);
                binarySearchByName(students, n, name);
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}