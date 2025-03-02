// Students working on this Project: Jesus Ramirez and Alejandro Saenz


#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime>  
#include <cctype> 
using namespace std; 

int main () {
    // Need to display heading 
    cout << "+------------------------------------------------------+\n";
    cout << "|  Computer Science and Engineering                    |\n";
    cout << "|  CSCE 1030 - Computer Science I                      |\n";
    cout << "|  Jesus Ramirez jor0038 jesusramirez11@my.unt.edu     |\n";
    cout << "+------------------------------------------------------+\n";

    //Now need to ask user for their name, so need to declare variable 
    string name;
    bool valid;
    do {
        cout << "Please enter your name: ";
        getline(cin, name);
        valid = true; 
        for (char c : name) {
            if (!isalpha(c) && !isspace(c)) {
                valid = false;
                break;
            } 
        }
        if (!valid) {
            cout << "Please enter a valid name please. Enter again.\n";
        }
    } 
    while (!valid);
    // Welcome message for user and what to expect
    cout << "Welcome " << name << ".\n";
    cout << "Two random numbers have been generated for you." << endl;
    
    // Score will be set to 100 and started random seed 
    int score = 100;
    srand(time(0));

    // Generating two random numbers
    int rand1, rand2;
    do {
        rand1 = rand() % 100;
        rand2 = rand() % 100;
    }
    while (rand1 >= rand2);

    // FIXME: Need to make sure first and last initials are capitalized 
    
    // Setting Display or Exit values as false
    bool displayOpt = false;
    bool exitOpt = false;

    // Establishing an enumeration for given choices of add, subtract, display, giveup, and exit
    int userChoice;

    enum choice {ADD = 1, SUBTRACT = 2, DISPLAY = 3, GIVEUP = 4, EXIT = 5};

    cout << "\n1. ADD\n2. SUBTRACT\n3. DISPLAY\n4. GIVEUP\n5. EXIT\n";
    cout << "Enter your perferred choice: ";
    cin >> userChoice; 

    switch (userChoice) {
        case 1:
        int guess; 
        cout << "Please enter your guess of the sum of random numbers: ";
        cin >> guess;
        int realSum = rand1 + rand2;
        if (abs(guess - realSum) < 5) {    // Creating if statement to accept guesses that are less than 5 from realSum
            score += 5;
            cout << "Congrats. Your guess is close enough. You Win! Your updated score is: " << score << endl;
            cout << "Would you like to restart the game? Y/N: ";  
            char restart; // Restart option if user would like to play again
            cin >> restart; 
            restart = toupper(restart); 
            if (restart == 'Y') {
                do {
                    rand1 = (rand() % 51) + 100;
                    rand2 = (rand() % 51) + 100;
                }
                while (rand1 >= rand2);
                displayOpt = false;
            }
            else {
                score -= 1;
                cout << "Wrong guess\nYour updated score is now: " << score << endl;
            }
            break;
        }
        case 2: 
        


    }

    return 0; 
}
