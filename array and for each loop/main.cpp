#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

main() {
    std::string student_record[4] = {"Mario", "Luigi", "Andrea", "Luca"};

    for (std::string student : student_record)  //this is an example of a for each loop
        cout << student << endl;
}