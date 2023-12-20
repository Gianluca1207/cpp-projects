#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int number[16] = {6,0,1,1,0,0,0,9,9,0,1,3,9,4,2,4} ;        //we declare an array of chars, so we can iterate over it, unlike a string
    int size = sizeof(number)/sizeof(number[0]);
    
    int sum1=0, sum2=0;    //I have to declare sum1 and sum2 here and not in the for loops otherwise I can't add them up because of the scope
                           // and initialize them to 0 !!!
    for (int i=size-1 ; i>=0; i--) {     //iterating backward
        int doubled_num,first_digit, second_digit, sum;
        if (i%2 != 0) {         //we are only concerned with every second digit from right to left
            doubled_num = (number[i])*2;
            if (doubled_num > 9) {         //if the doubled number is 2 digits
                first_digit = doubled_num/10;            //to get the first digit
                second_digit = doubled_num%10;           //to get the second digit
                sum1 += first_digit + second_digit;       //adding up the first and second digit to the sum
              }
            else sum1 += doubled_num;         //else we only add up the doubled number
         }
    }

    for (int i=size-1 ; i>=0; i--) {     //iterating backward
        int sum;
            if (i%2 == 0) {         //we are only concerned with odd numbered digits
                sum2 += number [i];
            }
    }

    cout << sum1 + sum2;
}