#include "RobotList.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector> 

using namespace std;

RobotList::RobotList() : head(nullptr) {}

// Name: RobotList::~RobotList
// Parameters: None
// Returns: None
// Side Effects: The destructor deallocates the memory
// for each Robot object in the linked list. 
RobotList::~RobotList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->val;
        delete current;
        current = next;
    }
}

// Name: addRobot
// Parameters: Robot* robot 
// Pointer to the Robot object to be added to the list.
// Returns: None
// Side Effects: Adds the provided Robot object to the
// linked list by creating a new node and adjusting the
// pointers. Modifies the linked list structure by
// updating the head pointer to the newly added node.

void RobotList::addRobot(Robot* robot) {
    Node* newNode = new Node;
    newNode->val = robot;
    newNode->next = head;
    head = newNode;
}
// Name: deleteRobot
// Parameters: const string& name 
// The name of the robot to be deleted.
// Returns: None
// Side Effects: Removes the specified robot
// from the linked list by updating the pointers
// of the neighboring nodes and freeing the associated memory.

void RobotList::deleteRobot(const string& name) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->val->getName() != name) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            head = current->next;
        }
        delete current->val;
        delete current;
    }
}

// Name: renameRobot
// Parameters: None
// Returns: None
// Side Effects: Renames a robot in the linked list
// by updating the name of the specified robot.
// Displays a success message if the robot is found and renamed.
// If the robot is not found, displays a message indicating
// that the robot was not found.

void RobotList::renameRobot() {
    string oldName, newName;
    cout << "Enter the name of the robot to rename: ";
    cin >> oldName;
    cout << "Enter the new name: ";
    cin >> newName;

    Node* current = head;
    while (current != nullptr) {
        if (current->val->getName() == oldName) {
            current->val->setName(newName);
            cout << "Robot has been renamed successfully.\n";
            return;
        }
        current = current->next;
    }

    cout << "Robot not found.\n";
}

// Name: printDistances
// Parameters: None
// Returns: None
// Side Effects: Prints the names and distances
// traveled by each robot in the linked list in a formatted table.

void RobotList::printDistances() const {
    struct RobotDistance {
        string name;
        int distance;
    };

    Node* current = head;
    vector<RobotDistance> robotDistances;

    while (current != nullptr) {
        RobotDistance rd;
        rd.name = current->val->getName();
        rd.distance = current->val->getDistance();
        robotDistances.push_back(rd);
        current = current->next;
    }

    sort(robotDistances.begin(), robotDistances.end(),
         [](const RobotDistance& rd1, const RobotDistance& rd2) {
             return rd1.distance > rd2.distance;
         });

    cout << left << setw(10) << "Name" << "Distance\n";
    for (const auto& rd : robotDistances) {
        cout << left << setw(10) << rd.name << rd.distance << endl;
    }
}
// Name: updateRobotList
//Parameters: None
// Returns: None
// Side Effects: Adds a new robot to the list or deletes an existing
// robot from the list based on user input. Displays appropriate 
// messages to indicate the success or failure of the operation.

void RobotList::updateRobotList() {
    char choice;
    cout << "Add or delete a robot (A/D): ";
    cin >> choice;

    choice = toupper(choice);

    if (choice == 'A') {
        string robotName;
        cout << "Enter the name of the robot to add: ";
        cin >> robotName;

        if (findRobot(robotName) != nullptr) {
            cout << "Robot already exists.\n";
            return;
        }

        Robot* newRobot = new Robot(robotName);
        addRobot(newRobot);
        cout << "Robot has been added successfully.\n";
    } else if (choice == 'D') {
        string robotName;
        cout << "Enter the name of the robot to delete: ";
        cin >> robotName;

        deleteRobot(robotName);
        cout << "Robot has been deleted successfully.\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

// Name: findRobot
// Parameters: const string& identifier 
// The unique identifier (name) of the robot to be found.
// Returns: Pointer to the robot with the matching identifier, or nullptr if not found.
// Side Effects: Searches the linked list for a robot with the specified identifier.
// Returns a pointer to the matching robot if found, or nullptr if not found.
// Does not modify the list or any other variables.

Robot* RobotList::findRobot(const string& identifier) const {
    Node* current = head;

    while (current != nullptr) {
        if (current->val->getName() == identifier) {
            return current->val;
        }
        current = current->next;
    }

    return nullptr;
}