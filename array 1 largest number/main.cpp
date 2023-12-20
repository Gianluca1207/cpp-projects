#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

main() {
    int array_length, larg_num=0;
    cout << "Enter array length: ";
    cin >> array_length;

    int arr[array_length] ;

    cout << "Enter array elements" << endl;

    for (int i=0; i<array_length; i++) {
        int el; 
        cout << "Enter element at index " << i <<" : ";
        cin >> el;
        arr[i] = el;
        if (el>larg_num)
            larg_num=el;
    }

    cout << "Elements of the array: ";

    for (int i=0; i<array_length; i++) {       //if we use sizeof(arr), it will return the total size of the array in bytes, 
        cout << arr[i] << "  " ;               //not the number of elements. We instead have to write: sizeof(arr)/sizeof(int) to do this!!!
    }

    cout << "\nThe largest number in the array is " << larg_num <<endl;
}