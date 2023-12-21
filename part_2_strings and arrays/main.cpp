/* Write a C++ program that takes a string as input and prints it in reverse order.

Create a program that finds and displays the length of a given string without using the built-in strlen function.

Implement a C++ program that checks if a given word is a palindrome. */

#include <iostream>
#include <vector>
#include <string>
#include "functions.h"


int main() {

    std::string s, reversed_s;

    std::cout << "Enter a string ";
    std::getline(std::cin, s);

    if (isPalindrome(s))
        std::cout << "The word is palindrome \n";
    else std::cout << "The word is not palindrome \n";
    

    for (int i=s.size()-1; i>=0 ; i--) {      // the valid indices for a string range from 0 to s.size() - 1 . I can use the size() method because s is a std::string
        reversed_s.push_back(s[i]);      
    }

    std::cout << "\nThe reversed string is " << reversed_s << "\n";


    int counter = 0;   //initializing a variable counter for the next function (calculating the string length)

    for (int i=0; i<s.size(); i++) {     // You don't need a separate loop to calculate the length; you can use the same loop that you used to reverse the string
        counter++;
    }

    std::cout << "The length of the string is " << counter << "\n" ;
}