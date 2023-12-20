#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int contaParole (std::string &frase) {
    std::stringstream stream(frase);
    std::string parola;
    int i=0;

    while (stream >> parola)
        i++;
    
    return i;
}

using namespace std;

int main()
{
    cout << "Inserire una frase ";
    std::string frase;
    std::getline (std::cin, frase);
    //std::cin >> frase;

    cout << "Il numero di parole nella frase e' " << contaParole(frase);



}