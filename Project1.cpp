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
    cout << "|  Alejandro Saenz EUID your@unt.edu email             |\n";   //FIXME add your unt creds pls 
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
            cout << "Please enter a valid name. Enter again.\n";
        }
    } 
    while (!valid);

    // Need to make sure first and last initials are capitalized. This I had to look up, but it doesn't seem to be working
    // We can leave out if need be just to make it less suspicious
    bool makeUpper = true;
    for (int i = 0; i < name.length(); ++i) {
        if (makeUpper && isalpha(name[i])) {
            name[i] = toupper(name[i]);
            makeUpper = false;
        }
        else if (isspace(name[i])) {
            makeUpper = true;
        }
        else {
            name[i] = tolower(name[i]);
        }
    }  

    // Welcome message for user and what to expect 
    cout << "Welcome " << name << ".\n";
    cout << "Two random numbers have been generated for you." << endl;
    
    // Score will be set to 100 and started random seed 
    int score = 100;
    srand(time(0));

    // Generating two random numbers inclusively from 100 to 150
    int rand1, rand2;
    do {
        rand1 = (rand() % 51) + 100;
        rand2 = (rand() % 51) + 100;
    }
    while (rand1 >= rand2);

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
        case 1: {       //ADD
            int guess; 
            cout << "Please enter your guess of the sum of random numbers: ";
            cin >> guess;
            int realSum = rand1 + rand2;
            if (abs(guess - realSum) < 5) {    // Creating if-else statement to accept guesses that are less/more than 5 from realSum or wrong guess 
                score += 5;
                cout << "Congrats. Your guess is close enough. You Win! Your updated score is: " << score << endl;
                cout << "Would you like to restart the game? Y/N: ";  
                char restart;                  // Restart option if user would like to play again
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
        }
        case 2: {    //SUBTRACT                            // FIXME Having issue with complier. Says I jumped cases and is not running correctly. Maybe you can look at it, Edgar 
            int guess;
            cout << "Please enter your guess of the difference of random numbers: ";
            cin >> guess; 
            int realDiff = rand2 - rand1;
            if (abs(guess - realDiff) < 5) {    // Basically the same format as Case 1
                score += 5;
                cout << "Congrats. Your guess is close enough. You Win! Your updated score is: " << score << endl;
                cout << "Would you like to restart the game? Y/N: ";
                char restart;                   
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
        }
        case 3: {   //DISPLAY
            if(!displayOpt) {
                score -= 3;
                displayOpt = true;
                cout << "Your updated score is: " << score << endl;
                cout << "The first random number is " << rand1 << endl;
            }
            else {
                cout << "You have already displayed the first random number.\n";
            }
            break;
        }
                /*FIXME: Whats left is to add case 4 and 5 for GIVEUP and EXIT
                Will also need to display an if statement in case the player runs out of points, i.e. GAMEOVER
                Lastly, display the user's final score and end with a "Goodbye" message
                */

    }

    return 0; 
}
