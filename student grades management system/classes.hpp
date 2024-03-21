#include <iostream>
#include <vector>
#include <string>

class Student {
    std::string name;
    int ID;
    float grades[3];     //array to store the grades for 3 subjects

    public:
        Student () : ID(0), grades{0.0f, 0.0f, 0.0f} {} ;     // this is a declaration of constructor (not a definition !)

        // setter methods
        void setName (std::string newName) {
            this->name = newName;
        }

        void setID (int newID) {
            this->ID = newID;
        }

        void setGrades (const float newGrades[3]) {
            for (int i=0; i<3; i++) {
                grades [i] = newGrades[i] ;
            }
        }

        //getter methods
        std::string getName () const {     // Adding const to getter methods indicates that these methods do not modify the state of the object
            return name;
        }

        int getID () const {
            return ID;
        }

        void getGrades (float outGrades[3]) const {
            for (int i=0; i<3; i++) {
                outGrades[i] = grades[i];
            }
        }

        // Function to calculate the average grade
        float CalculateAverageGrade () {
            float sum = 0.0f;    // 0.0f explicitly indicates a floating-point literal of type float. The f suffix specifies that the literal is a float
            for (int i=0; i<3; i++) {
                sum += grades [i];
              }
            return sum/3;
        }




};