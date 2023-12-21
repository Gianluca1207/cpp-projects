#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool checkLength (std::string& password) {
    if (password.length() >= 8)
        return true;
    else return false;
}

bool hasUpperCase (std::string& password) {
    for (int i=0 ; i< password.size() ; i++) {
        if (std::isupper(password[i])) {
            return true;
        }
    }
    return false;
}

bool hasLowerCase (std::string& password) {
    for (int i=0 ; i< password.size() ; i++) {
        if (std::islower(password[i])) {
            return true;
        }
    }
    return false;
}

bool hasDigit(const std::string& password) {
    for (int i=0 ; i< password.size() ; i++) {
        if (std::isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

bool hasSpecialChar(const std::string& password) {
    for (int i=0 ; i< password.size() ; i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$') {
            return true;
        }
    }
    return false;
}


int main() {

    std::string password;
    
    do {
        std::cout << "Enter a password: ";
        std::cin >> password;
        if (checkLength(password) == false) {        // or also if (!checkLength(password))
            std::cout << "Your password is too short. Please try again \n";
        }
        else if (hasUpperCase(password) && hasLowerCase(password) && !hasDigit(password) && !hasSpecialChar(password)) {  //make sure to add !hasDigit(password) and !hasSpecialChar(password)
            std::cout << "Your password is weak \n";                                          // otherwise, even id the password is  medium or strong, it'll always 
        }                                                                                     //be classified as weak !!
        else if (hasUpperCase(password) && hasLowerCase(password) && hasDigit(password) && !hasSpecialChar(password)) {
            std::cout << "Your password is medium \n";
        }
        else if (hasUpperCase(password) && hasLowerCase(password) && hasDigit(password) && hasSpecialChar(password)) {
            std::cout << "Your password is strong \n";
        }
    }
    while (!checkLength(password));
}