#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    float grade1, grade2;
    float arithmeticAverage;
};

bool compareByName(const Student& s1, const Student& s2) {
    return s1.name < s2.name;
}

void selectionSort(std::vector<Student>& students) {
    for (int i = 0; i < students.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < students.size(); j++) {
            if (compareByName(students[j], students[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(students[i], students[minIndex]);
        }
    }
}

int main() {
    std::vector<Student> students = {
        {"Amanda", 80.0, 90.0, 0.0},
        {"Alice", 90.0, 85.0, 0.0},
        {"Bob", 70.0, 75.0, 0.0}
    };

    selectionSort(students);

    for (const auto& student : students) {
        std::cout << student.name << " (" << student.grade1 << ", " << student.grade2 << ")" << std::endl;
    }

    return 0;
}
