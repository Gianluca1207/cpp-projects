#include <iostream>
#include <string>
#include <vector>

using namespace std;

int VowelCounter (std::string& phrase) {
    int count = 0;
    for (int i=0; i<phrase.length(); i++) {     
            if (phrase[i] == 'a' || phrase[i] == 'A' ||
                phrase[i] == 'e' || phrase[i] == 'E' ||
                phrase[i] == 'i' || phrase[i] == 'I' ||
                phrase[i] == 'o' || phrase[i] == 'O' ||
                phrase[i] == 'u' || phrase[i] == 'U')
            count++;
    }
    return count;
}

int main() {
    std::string sentence;
    cout << "Enter sentence ";
    std::getline (std::cin, sentence);

    cout << endl << "The number of vowels in your sentence is " << VowelCounter(sentence) << endl;
}