#ifndef ROBOT_H
#define ROBOT_H

#include <string>

using namespace std;

// Name: Robot
// Parameters: const string& name - The name of the robot.
// Returns: None
// Side Effects: Represents a robot with attributes such as position,
// last command, current speed, distance traveled, and name. 
// Provides member functions to move the robot, access its attributes,
// and modify its name. The constructor initializes the robot's
// attributes with the provided name.

class Robot {
private:
    int posX;
    int posY;
    char lastCommand;
    int currentSpeed;
    int distance;
    bool stopped;
    string name;

public:
    Robot(const string& name);

    int getPosX() const;
    int getPosY() const;
    char getLastCommand() const;
    int getCurrentSpeed() const;
    int getDistance() const;
    bool isStopped() const;
    string getName() const;

    void setPosX(int posX);
    void setPosY(int posY);
    void setLastCommand(char lastCommand);
    void setCurrentSpeed(int currentSpeed);
    void setDistance(int distance);
    void setStopped(bool stopped);
    void setName(const string& name);

    void moveRobot(char d);
};

#endif  // ROBOT_H