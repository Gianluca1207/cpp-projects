#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void PopulateArray (std::string array[], int size) {
    std::string temp;
    for (int i=0; i<size ; i++) {
        cout << "Enter element #" <<i << " (or q to quit) ";
        std::getline(std::cin, temp);      //storing the user input in the temp veriable so I can check if the user wants to quit
        
        if (temp == "q")
            break;
        else array[i] = temp;    //make sure to type = and not == !!!!!
    }
}

int main() {       //make sure to type int main and not only main !!!!

    std::string array[10];
    int size = sizeof(array)/sizeof(std::string);     //I always have to calculate the size of the array

    PopulateArray (array, size);             //always make sure to pass in the size when passing an array to a function

    for (int i=0; !array[i].empty() ; i++) {          //empty function: instead of writing i < size , we write this to print out the values till they are empty
        cout << "Element #" <<i << " : " << array[i] << endl;
    }

 //   for (std::string element : array) {    // if we write this, all the empty elements will be printed
 //       cout << element << endl;
 //   }
}