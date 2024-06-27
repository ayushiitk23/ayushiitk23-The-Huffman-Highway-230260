#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure for student records
struct Student {
    string name;
    int rollNumber;
    string course;
    float totalMarks;
};

// Function prototypes
void createRecord(vector<Student>& students);
void deleteRecord(vector<Student>& students, int rollNumber);
void showRecords(const vector<Student>& students);
void searchRecord(const vector<Student>& students, int rollNumber);

int main() {
    vector<Student> students;
    int choice;
    int rollNumber;

    while (true) {
        cout << "\nStudent Record Management System\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Delete Student Record\n";
        cout << "3. Show All Student Records\n";
        cout << "4. Search Student Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createRecord(students);
                break;
            case 2:
                cout << "Enter Roll Number of Student to Delete: ";
                cin >> rollNumber;
                deleteRecord(students, rollNumber);
                break;
            case 3:
                showRecords(students);
                break;
            case 4:
                cout << "Enter Roll Number of Student to Search: ";
                cin >> rollNumber;
                searchRecord(students, rollNumber);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

// Function to create a new student record
void createRecord(vector<Student>& students) {
    Student student;
    cout << "Enter Name: ";
    cin.ignore();  // Ignore leftover newline character
    getline(cin, student.name);
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Course: ";
    cin.ignore();
    getline(cin, student.course);
    cout << "Enter Total Marks: ";
    cin >> student.totalMarks;

    students.push_back(student);
    cout << "Record added successfully!\n";
}

// Function to delete a student record by roll number
void deleteRecord(vector<Student>& students, int rollNumber) {
    auto it = find_if(students.begin(), students.end(), [rollNumber](const Student& student) {
        return student.rollNumber == rollNumber;
    });

    if (it != students.end()) {
        students.erase(it);
        cout << "Record deleted successfully!\n";
    } else {
        cout << "Record not found!\n";
    }
}

// Function to show all student records
void showRecords(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No records found!\n";
        return;
    }

    for (const auto& student : students) {
        cout << "Name: " << student.name << "\n";
        cout << "Roll Number: " << student.rollNumber << "\n";
        cout << "Course: " << student.course << "\n";
        cout << "Total Marks: " << student.totalMarks << "\n";
        cout << "--------------------------\n";
    }
}

// Function to search for a student record by roll number
void searchRecord(const vector<Student>& students, int rollNumber) {
    auto it = find_if(students.begin(), students.end(), [rollNumber](const Student& student) {
        return student.rollNumber == rollNumber;
    });

    if (it != students.end()) {
        cout << "Name: " << it->name << "\n";
        cout << "Roll Number: " << it->rollNumber << "\n";
        cout << "Course: " << it->course << "\n";
        cout << "Total Marks: " << it->totalMarks << "\n";
    } else {
        cout << "Record not found!\n";
    }
}
