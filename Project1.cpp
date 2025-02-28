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
    } while (!valid);
