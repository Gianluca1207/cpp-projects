#include <iostream>
#include <vector>
#include <string>

using namespace std;

main() {

    int grade = 2;

    grade == 1 || grade==2 || grade==3 || grade==4 ? cout << "You pass!" <<endl : cout << "You fail" << endl;

    grade%2 == 0 ? cout << "Your grade is an even number!" : cout << "Your grade is an odd number!" << endl;
}