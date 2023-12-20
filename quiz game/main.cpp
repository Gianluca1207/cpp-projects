#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

    std::string questions[] = {"1.What is the capital city of Australia?", "2.Who wrote the play Romeo and Juliet?",
                                "3.Which element has the chemical symbol Hg?", "4.What is the largest ocean on Earth?"};
    
    std::string options [][4] = {{"A.Sydney", "B.Melbourne", "C.Canberra", "D.Brisbane"},
                                {"A.Charles Dickens", "B.William Shakespeare", "C.Jane Austen", "D.Mark Twain"},
                                {"A.Hydrogen", "B.Helium", "C.Mercury", "D.Magnesium"},
                                {"A.Indian Ocean", "B.Atlantic Ocean", "C.Southern Ocean", "D.Pacific Ocean"}};

    char answers[] = {'c', 'b', 'c', 'd'};      //note that it's an array of chars

    int size = sizeof(questions)/sizeof(std::string);

    char guess;
    int score;

    for (int i=0; i<size ; i++) {        //iteration over the array questions
        cout << questions[i] << endl;            //print the question
        for (int j=0; j<sizeof(options[i])/sizeof(options[i][0]) ; j++) {  //note this! j<sizeof(options[i])/sizeof(options[i][0]) because we want to iterate over
            cout << options[i][j] << endl;                                 //  the whole first array of options (made up of 4 elements)
        }
        cout << "ANSWER: ";      //at each iteration of i, after displaying all the options, I ask the user for the answer to that question
        cin >> guess;

        if (guess == answers[i]) {
            std::cout << "CORRECT" << endl;
            score++;                   //when I got the answer right, I'll increase the score
           }
        else {
            cout << "WRONG\n";
            cout << "The correct answer is " << answers[i] << endl;
           }

    }

std::cout << "RESULTS" << endl;
std::cout << "CORRECT GUESSES: " << score << endl;
std::cout << "# OF QUESTIONS: " << size << endl;
std::cout << "SCORE: " << score/(double)size << endl;


}