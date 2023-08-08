//Priscilla Velasquez prv6
//6-30-23
//Collaborated with Freddy Martinez and referenced from
//chatGPT and zybooks
#include "Robot.h"
#include "RobotList.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// Name: displayMenu
// Parameters: None
// Returns: None
// Side Effects: None

void displayMenu() {
    cout << "Welcome to MultiRobo Guider.\n";
    cout << "Please select:\n";
    cout << "M- Move\n";
    cout << "D- Distance\n";
    cout << "U- Update robot list\n";
    cout << "R- Rename one robot\n";
    cout << "Q- Quit\n";
}

int main() {
    RobotList robotList;

    cout << "Start program\n";

    int numOfRobots;
    cout << "Enter the number of robots: ";
    cin >> numOfRobots;

    for (int i = 0; i < numOfRobots; i++) {
        string robotName;
        cout << "Enter the name of robot " << i + 1 << ": ";
        cin >> robotName;

        Robot* newRobot = new Robot(robotName);
        robotList.addRobot(newRobot);
    }

    char choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        choice = toupper(choice);

        switch (choice) {
            case 'M': {
                string robotName;
                char direction;
                cout << "Enter the name of the robot: ";
                cin >> robotName;
                cout << "Enter the direction (U/D/R/L/S): ";
                cin >> direction;
                robotList.findRobot(robotName)->moveRobot(direction);
                cout << robotList.findRobot(robotName)->getName() << "'s position is ("
                     << robotList.findRobot(robotName)->getPosX() << ","
                     << robotList.findRobot(robotName)->getPosY() << ")" << endl;
                break;
            }
            case 'D':
                robotList.printDistances();
                break;
            case 'U':
                robotList.updateRobotList();
                break;
            case 'R':
                robotList.renameRobot();
                break;
            case 'Q':
                cout << "Goodbye\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 'Q');

    return 0;
}