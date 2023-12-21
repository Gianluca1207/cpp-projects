#include <iostream>
#include <vector>
#include <string>

bool isPalindrome (std::string& word) {
    int start = 0;
    int end = word.size() -1;          // I use two indices (start and end) to compare characters from both ends of the word

    while (start < end) {
        if (!std::isalnum(word[start])) {      // std::isalnum is used to ignore non-alphanumeric characters
            start++;
          }

        if (!std::isalnum(word[end])) {        // std::isalnum is used to ignore non-alphanumeric characters
            end--;
          }
        if (std::tolower(word[start]) != std::tolower(word[end])) {
            return false;     // characters don't match, not a palindrome
          }
        start++;      // if the two characters matched, we can continue our while loop
        end--; 
    }
    return true; // if the while loop is finished and all characters matched, it's a palindrome and we can return true
}