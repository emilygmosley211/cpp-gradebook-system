#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_STUDENTS = 100;

// Function prototypes
void inputStudentData(string names[], int grades[], int& n);
void sortGrades(string names[], int grades[], int n);
int searchStudent(const string names[], const int grades[], int n, string target);
void calculateStatistics(const int grades[], int n, double& avg, int& minGrade, int& maxGrade);

int main() {
    string names[MAX_STUDENTS];
    int grades[MAX_STUDENTS];
    int n;
    // Step 1: Get input from the teacher
    inputStudentData(names, grades, n);

    // Step 2: Sort the grades and corresponding names
    sortGrades(names, grades, n);

    // Step 3: Display sorted grades
    cout << "\nSorted Grades:\n";
    for (int i = 0; i < n; ++i) {
        cout << names[i] << ": " << grades[i] << endl;
    }

    // Step 4: Search for a student's grade
    string searchName;
    cout << "\nEnter student name to search: ";
    cin.ignore(); // Clear newline from previous input
    getline(cin, searchName);
    int index = searchStudent(names, grades, n, searchName);
    if (index != -1) {
        cout << names[index] << "'s grade: " << grades[index] << endl;
    } else {
        cout << "Student not found.\n";
    }

    // Step 5: Calculate and display class statistics
    double avg;
    int minGrade, maxGrade;
    calculateStatistics(grades, n, avg, minGrade, maxGrade);
    cout << "\nClass Statistics:\n";
    cout << "Average Grade: " << avg << endl;
    cout << "Highest Grade: " << maxGrade << endl;
    cout << "Lowest Grade: " << minGrade << endl;

    return 0;
}

// Input function
void inputStudentData(string names[], int grades[], int& n) {
    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter student name: ";
        cin.ignore(); // Clear newline before getline
        getline(cin, names[i]);
        cout << "Enter " << names[i] << "'s grade: ";
        cin >> grades[i];
    }
}

// Sorting function (by grade, ascending)
void sortGrades(string names[], int grades[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (grades[i] > grades[j]) {
                // Swap grades
                int tempGrade = grades[i];
                grades[i] = grades[j];
                grades[j] = tempGrade;

                // Swap corresponding names
                string tempName = names[i];
                names[i] = names[j];
                names[j] = tempName;
            }
        }
    }
}

// Searching function (linear search by name)
int searchStudent(const string names[], const int grades[], int n, string target) {
    for (int i = 0; i < n; ++i) {
        if (names[i] == target) {
            return i;
        }
    }
    return -1;
}

// Statistics function
void calculateStatistics(const int grades[], int n, double& avg, int& minGrade, int& maxGrade) {
    int sum = 0;
    minGrade = grades[0];
    maxGrade = grades[0];

    for (int i = 0; i < n; ++i) {
        sum += grades[i];
        if (grades[i] < minGrade) minGrade = grades[i];
        if (grades[i] > maxGrade) maxGrade = grades[i];
    }

    avg = static_cast<double>(sum) / n;
}
