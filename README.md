# Robot
This product will take guidance input from the console and translate those values into positional data for a robotic platform.
Introduction
Product Purpose: this product is being developed as a generalized
robotic guidance platform. This product will take guidance input from
the console and translate those values into positional data for a
robotic platform.

Language: this project will be implemented using the C++ programming
language.

4. System Description
System Context: this will be a self-contained piece of software that
will not rely on external platforms for its basic operation.
User Characteristics: users will be trained robot operators who are
proficient with computer operation. This project will not be
responsible for user training.

6. Functional Requirements
4.1 Startup: when the software starts, it
should ask the user for a number of robots to begin with. It should
also ask the user for a unique identifier for each robot. You can
assume that the user is entering unique names for each robot, you do
not need to check.

4.2 Menu: the user should be shown the menu
of possible commands and should be able to select one command from
the menu. Your program should print an error message if the user
enters a letter that is not in the menu. The following commands are
available in MRG:
• M- move one robot
• D- print the distance each robot has moved
• U- Update robot list
• R- rename one robot
• Q- quit the program

4.3 Move: The user should be prompted to enter
the unique identifier of one robot and a direction. The program
should print an error if the user enters an invalid direction or if
they enter an invalid robot identifier. The following directions are
allowed:
• U- up or positive y
• D- down or negative y
• R- right or positive x
• L- left or negative x
• S- stop or start moving.
The program updates the position of the correct robot by an
amount equal to the robots speed and then
prints the new position. Every robot starts at position 0,0 and can
move infinitely in any direction. The position is printed as X,Y.

4.4 Distance: This menu option should print the
unique identifier of each robot and the distance that it has moved in
neatly formatted columns, sorted with the robot that has moved the
farthest at the top.

4.5 Update: This menu option allows the
user to add or delete robots from the list. The options for updating
the list are:
• A- add a robot
• D- delete a robot
Either option is followed by a robot name. “Add” should add a
robot with the new name to the list of robots. “Delete” should remove
the robot with the matching name from the list, or do nothing if no
robot in the list has a name which matches.

4.6 Rename: The user should enter two names
following this menu option. The first identifies the robot to rename,
the second is its new name. Do nothing if the first name is not in
the list.
4.7 Quit: The program prints a short
parting message when the user selects ‘Q’.

4.8 Errors: The program prints an
appropriate error message and return to the top level menu as soon as it receives unrecognized input.

