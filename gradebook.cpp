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