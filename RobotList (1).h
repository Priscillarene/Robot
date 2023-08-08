#ifndef ROBOTLIST_H
#define ROBOTLIST_H

#include "Robot.h"

using namespace std;

// Name: RobotList
// Parameters: None
// Returns: None
// Side Effects: Manages a linked list of robots by providing
// member functions to add, delete, rename, print distances,
// update the robot list, and find a robot. Modifies the linked
// list structure as needed to perform these operations.

class RobotList {
private:
    struct Node {
        Robot* val;
        Node* next;
    };

    Node* head;

public:
    RobotList();
    ~RobotList();

    void addRobot(Robot* robot);
    void deleteRobot(const string& name);
    void renameRobot();
    void printDistances() const;
    void updateRobotList();
    Robot* findRobot(const string& identifier) const;
};

#endif  // ROBOTLIST_H







