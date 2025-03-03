#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

int main() {
    // Displaying heading
    cout << "+--------------------------------------------------------------+\n";
    cout << "|  Computer Science and Engineering                            |\n";
    cout << "|  CSCE 1030 - Computer Science I                              |\n";
    cout << "|  Jesus Ramirez jor0038 jesusramirez11@my.unt.edu             |\n";
    cout << "|  Edgar Saenz Wong eas0446 AlejandroSaenzWong@my.unt.edu      |\n";
    cout << "+--------------------------------------------------------------+\n";

    // Declare variable for user name
    string name;
    bool valid;

    do {
        cout << "Please enter your name: ";
        getline(cin, name);
        valid = true;

        // Check if name contains only letters and spaces
        for (int i = 0; i < name.length(); ++i) {
        if (!isalpha(name[i]) && !isspace(name[i])) {
        valid = false;
        break;
    }
}

        if (!valid) {
            cout << "Please enter a valid name (only letters and spaces). Enter again.\n";
        }
    } while (!valid);

    // Capitalize first and last initials of the name
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

    // Welcome message
    cout << "Welcome " << name << ".\n";
    cout << "Two random numbers have been generated for you." << endl;

    // Set initial score and random seed
    int score = 100;
    srand(time(0));

    // Generate two random numbers between 100 and 150
    int rand1, rand2;
    do {
        rand1 = (rand() % 51) + 100;
        rand2 = (rand() % 51) + 100;
    } while (rand1 >= rand2);

    // Game loop variables
    bool displayOpt = false;
    bool exitOpt = false;
    enum choice {ADD = 1, SUBTRACT = 2, DISPLAY = 3, GIVEUP = 4, EXIT = 5};

    // Game loop
    while (score > 0 && !exitOpt) {
        cout << "\n1. ADD\n2. SUBTRACT\n3. DISPLAY\n4. GIVEUP\n5. EXIT\n";
        cout << "Enter your preferred choice: ";
        int userChoice;
        cin >> userChoice;

        switch (userChoice) {
            case ADD: { // ADD
                int guess;
                cout << "Please enter your guess of the sum of random numbers: ";
                cin >> guess;
                int realSum = rand1 + rand2;
                if (abs(guess - realSum) < 5) {
                    score += 5;
                    cout << "Congrats. Your guess is close enough. You Win! Your updated score is: " << score << endl;
                } else {
                    score -= 1;
                    cout << "Wrong guess. Your updated score is now: " << score << endl;
                }
                break;
            }

            case SUBTRACT: { // SUBTRACT
                int guess;
                cout << "Please enter your guess of the difference of random numbers: ";
                cin >> guess;
                int realDiff = rand2 - rand1;
                if (abs(guess - realDiff) < 5) {
                    score += 5;
                    cout << "Congrats. Your guess is close enough. You Win! Your updated score is: " << score << endl;
                } else {
                    score -= 1;
                    cout << "Wrong guess. Your updated score is now: " << score << endl;
                }
                break;
            }

            case DISPLAY: { // DISPLAY
                if (!displayOpt) {
                    score -= 3;
                    displayOpt = true;
                    cout << "Your updated score is: " << score << endl;
                    cout << "The first random number is " << rand1 << endl;
                } else {
                    cout << "You have already displayed the first random number.\n";
                }
                break;
            }

            case GIVEUP: { // GIVEUP
                score -= 10;
                cout << "You have given up. Your updated score is: " << score << endl;
                break;
            }

            case EXIT: { // EXIT
                exitOpt = true;
                break;
            }

            default: {
                cout << "Invalid choice. Please enter a valid choice.\n";
                break;
            }
        }

        // Check if score reached 0
        if (score <= 0) {
            cout << "Game Over! You ran out of points.\n";
            break;
        }

        // Ask if user wants to continue or restart
        if (!exitOpt && score > 0) {
            cout << "Would you like to continue or restart? (Y/N): ";
            char restart;
            cin >> restart;
            restart = toupper(restart);
            if (restart == 'N') {
                exitOpt = true;
            }
        }
    }

    // Final message
    cout << "Thank you for playing! Your final score is: " << score << endl;
    cout << "Goodbye!" << endl;

    return 0;
}