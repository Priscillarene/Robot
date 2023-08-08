#include "Robot.h"
#include <iostream>
#include <cctype>

using namespace std;

// Name: Robot
// Parameters: const string& name - The name of the robot.
// Returns: None
// Side Effects: Initializes the member variables of the Robot
// object with the provided name and default values for other attributes.
// Sets the initial state of the Robot object when it is created.

Robot::Robot(const string& name)
    : posX(0), posY(0), lastCommand('S'), 
    currentSpeed(1), distance(0), stopped(false), name(name) {}

int Robot::getPosX() const {
    return posX;
}

int Robot::getPosY() const {
    return posY;
}

char Robot::getLastCommand() const {
    return lastCommand;
}

int Robot::getCurrentSpeed() const {
    return currentSpeed;
}

int Robot::getDistance() const {
    return distance;
}

bool Robot::isStopped() const {
    return stopped;
}

string Robot::getName() const {
    return name;
}

void Robot::setPosX(int posX) {
    this->posX = posX;
}

void Robot::setPosY(int posY) {
    this->posY = posY;
}

void Robot::setLastCommand(char lastCommand) {
    this->lastCommand = lastCommand;
}

void Robot::setCurrentSpeed(int currentSpeed) {
    this->currentSpeed = currentSpeed;
}

void Robot::setDistance(int distance) {
    this->distance = distance;
}

void Robot::setStopped(bool stopped) {
    this->stopped = stopped;
}

void Robot::setName(const string& name) {
    this->name = name;
}

// Name: moveRobot
// Parameters: char d - A character representing the direction of movement.
// Returns: None
// Side Effects: Modifies the position, speed, and distance traveled by the
// robot based on the specified direction of movement. Updates the robot's
// position, speed, and distance variables accordingly. May print error messages
// if the robot is stopped or if an invalid direction is provided.

void Robot::moveRobot(char d) {
    if (stopped) {
        cout << "Error: Robot is stopped. Start the robot before moving.\n";
        return;
    }

    char direction = toupper(d);
    bool sameDirection = (direction == toupper(lastCommand));

    switch (direction) {
        case 'U':
            posY += currentSpeed;
            break;
        case 'D':
            posY -= currentSpeed;
            break;
        case 'R':
            posX += currentSpeed;
            break;
        case 'L':
            posX -= currentSpeed;
            break;
        case 'S':
            currentSpeed = 1;
            stopped = true;
            return;
        default:
            return;
    }

    distance += currentSpeed;

    if (sameDirection) {
        if (currentSpeed < 4) {
            currentSpeed++;
        }
    } else {
        currentSpeed = 1;
        lastCommand = direction;
    }
}