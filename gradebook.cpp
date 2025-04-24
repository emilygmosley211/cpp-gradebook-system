#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

void sortGrades(string names[], int grades[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (grades[i] > grades[j]) {
                swap(grades[i], grades[j]);
                swap(names[i], names[j]);
            }
        }
    }
}

int searchStudent(string names[], int grades[], int count, string target) {
    for (int i = 0; i < count; ++i) {
        if (names[i] == target) {
            return i;
        }
    }
    return -1;
}

void calculateStatistics(int grades[], int count, double &average, int &highest, int &lowest) {
    int sum = 0;
    highest = grades[0];
    lowest = grades[0];
    for (int i = 0; i < count; ++i) {
        sum += grades[i];
        if (grades[i] > highest) highest = grades[i];
        if (grades[i] < lowest) lowest = grades[i];
    }
    average = static_cast<double>(sum) / count;
}

int main() {
    int numStudents;
    string studentNames[MAX_STUDENTS];
    int studentGrades[MAX_STUDENTS];

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter student name: ";
        cin >> ws;
        getline(cin, studentNames[i]);
        cout << "Enter " << studentNames[i] << "'s grade: ";
        cin >> studentGrades[i];
    }

    sortGrades(studentNames, studentGrades, numStudents);

    cout << "\nSorted Grades:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << studentNames[i] << ": " << studentGrades[i] << endl;
    }

    string searchName;
    cout << "\nEnter student name to search: ";
    cin >> ws;
    getline(cin, searchName);
    int index = searchStudent(studentNames, studentGrades, numStudents, searchName);
    if (index != -1) {
        cout << searchName << "'s grade: " << studentGrades[index] << endl;
    } else {
        cout << "Student not found." << endl;
    }

    double average;
    int highest, lowest;
    calculateStatistics(studentGrades, numStudents, average, highest, lowest);

    cout << "\nClass Statistics:\n";
    cout << "Average Grade: " << average << endl;
    cout << "Highest Grade: " << highest << endl;
    cout << "Lowest Grade: " << lowest << endl;

    return 0;
}
