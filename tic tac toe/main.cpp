#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

void Drawboard (char* spaces) {
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "\n";
}

void PlayerMove (char* spaces, char player) {
    int number;     //between 1 and 9, depending on what space the user want to occupy with their marker
    do {
        cout << "Enter a spot to place a marker: ";
        cin >> number;
        number--;        //decrementing the number, so it matches the 0-8 scale
        if (spaces[number] == ' ') {   //if the space at index of number is empty
            spaces[number] = player;
            break;
          }
        else {
            cout << "The space is occupied \n";
        }
    }
    while (number < 0 || number > 8 || spaces[number] != ' ');   //double check this condition! otherwise the program will continue even if the space is occupied !!
}                                        //       ^-------- now it's correct !

void ComputerMove (char* spaces, char computer) {
    int number;
    srand(time(0));

    while (true) {    // do this to do an endless while
        number = rand() % 9;           // generate a random number between 0 and 8
        number--;
        if (spaces[number] == ' ') {     //if the space at index of number is empty
            spaces[number] = computer;         // set spaces at index of number equal to the computer's marker
            break;                      // to break the endless loop
          }
     }
}

bool checkWinner (char* spaces, char player, char computer) {
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {  // if the first space is not equal to an empty space and the first row all has the same characters
        spaces[0] == player ? cout << "YOU WIN \n" : cout << "YOU LOSE \n" ;
        return true;
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        spaces[3] == player ? cout << "YOU WIN \n" : cout << "YOU LOSE \n" ;
        return true;
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        spaces[6] == player ? cout << "YOU WIN \n" : cout << "YOU LOSE \n" ;
        return true;
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        spaces[0] == player ? cout << "YOU WIN \n" : cout << "YOU LOSE \n" ;
        return true;
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
        spaces[1] == player ? cout << "YOU WIN \n" : cout << "YOU LOSE \n" ;
        return true;
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
        spaces[2] == player ? cout << "YOU WIN \n" : cout << "YOU LOSE \n" ;
        return true;
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        spaces[0] == player ? cout << "YOU WIN \n" : cout << "YOU LOSE \n" ;
        return true;
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[2] && spaces[4] == spaces[6]) {
        spaces[0] == player ? cout << "YOU WIN \n" : cout << "YOU LOSE \n" ;
        return true;
    }
    else return false;
}

bool checkTie (char* spaces) {
    for (int i=0 ; i < 9 ; i++) {      // if we hadn't known that the array has a size of 9, we would have had to type i < size and pass size as parameter
        if (spaces[i] == ' ' )       // we only have to check if there are empty spaces
            return false;         //if we find an empty space, we return false
    }
    cout << "IT'S A TIE \n";
    return true;
}

int main() {

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char Player = 'X';
    char Computer = 'O';
    bool running = true;

    Drawboard(spaces);

    while (running) {
        PlayerMove (spaces, Player);
        Drawboard(spaces);

        if (checkWinner(spaces, Player, Computer)) {          // if there is a winner, we'll set the running value to false
            running = false;
            break;                   // and we'll break
        }
        else if (checkTie(spaces)) {                         // if there is a tie, we'll set the running value to false
            running = false;
            break;                   // and we'll break
        }

        ComputerMove(spaces, Computer);
        Drawboard(spaces);

        if (checkWinner(spaces, Player, Computer)) {          // if there is a winner, we'll set the running value to false
            running = false;
            break;                   // and we'll break
        }

        else if (checkTie(spaces)) {                           // if there is a tie, we'll set the running value to false
            running = false;
            break;                   // and we'll break
        }

    }

}