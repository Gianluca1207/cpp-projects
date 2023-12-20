#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    std::string sentence;

    cout << "Enter your name ";
    std::getline(cin, sentence);

    if (sentence.empty())
        cout << "It's emtpty! " << endl ;

    cout << "The length of your name is " << sentence.length() << endl;

    cout << "The character at index 7 is " << sentence.at(7) << endl;;    //another useful string method: name.at()

    sentence.append("@gmail.com");      //method append, the string sentence gets overwritten

    cout << "Your email is " << sentence << endl;     //so here we just write sentence 

    sentence.insert(4, "gi");      //method insert, it's intended to insert a character at a given position, the string gets overwritten

    cout << "Your new email is " << sentence <<endl;

    cout << "The character a can be found at position " << sentence.find('a') << endl;   //method find, it will give the position of the first character a

    sentence.erase(2,5);    //method erase to erase a portion of a string

    cout << "After the method erase, the string has become: " << sentence << endl;

}