
/*Implement a program that utilizes a do-while loop to prompt the user to enter a number until they enter a negative number. 
Display the sum of all positive numbers entered. */

#include <iostream>
#include <vector>
#include <string>

int main() {

    int n, sum=0;       //Other than n, I also have to initialize sum=0 here otherwise it resets to 0 at every iteration

    do {
        
        std::cout << "Enter a number ";
        std::cin >> n;
        if (n >= 0)       // checks if the number is positive
            sum += n ;
        std::cout << "The sum of all numbers entered is " << sum << "\n";
    }
    while(n >= 0 );     // until the number is negative
}