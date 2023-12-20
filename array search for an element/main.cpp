#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int arraySearch (std::string array[], int size, std::string element) {    //when we pass an array to a function, we always need to pass in the array (with square
    for (int i=0; i<size ; i++) {                                         // brackets sets) and its size
        if (array[i] == element)
            return i;
    }
    return -1;    //  return -1 if the element hasn't been found after searching the whole array
}

int main() {
    std::string student_record[6] = {"Mario", "Luigi", "Andrea", "Luca", "Alice", "Beatrice"};
    int size = sizeof(student_record)/sizeof(std::string);
    std::string MyElement;
    int index;

    cout << "Enter the element you want to search for ";
    cin >> MyElement;

    index = arraySearch(student_record, size, MyElement );        //here we don't have to add the square bracket sets to pass the array to our function
    if (index == -1)
        cout << "The element is not in the array" << endl;
    else cout << "The element " << MyElement << " is at index " << index;


}