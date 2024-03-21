#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "classes.hpp"

using namespace std;

int main() {
    // Example of using the Student class
    Student student;
    student.setName("John Doe");
    student.setID(123456);
    float grades[3] = {85.5, 90.2, 88.0};
    student.setGrades(grades);

    std::cout << "Student Name: " << student.getName() << std::endl;
    std::cout << "Student ID: " << student.getID() << std::endl;

    float retrievedGrades[3];
    student.getGrades(retrievedGrades);
    std::cout << "Grades: " << retrievedGrades[0] << ", " << retrievedGrades[1] << ", " << retrievedGrades[2] << std::endl;
    std::cout << "Average Grade: " << student.CalculateAverageGrade() << std::endl;

    return 0;
}