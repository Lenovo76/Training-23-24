# This project involves the answers of different tasks in hardware and software fields
## 1. Hello Gru 
This task is used to just write a C/C++ program that prints the string ‘GRU’ in the
output terminal (console) (Hello World problem) and in asterisks.

## 2.Counting Down
### This task is used to: 
1. Write a C/C++ program that takes the number to start the
countdown from as input and prints the countdown text starting
from that number.
2. Add a 1-second delay between each number in the countdown.

## 3.Task Manager
The task is used to create a C/C++ program that allows users to **add**, **view**, and
**remove** tasks, each task has an id/index and a description. The id
is a positive **unique** integer.
In addition, it is preferable if the user is allowed to
- mark tasks as completed
- view complete and incomplete tasks
- show the data in a table format.
## The Output can be like this:
Minions Task Manager
1. Add Task
2. View Tasks
3. Remove Task
4. Exit

Select an option: 1

Enter task description: Prepare moon launch materials
Task added successfully!

Select an option: 1

Enter task description: Check spaceship fuel levels
Task added successfully!

Select an option: 2

Current Tasks:
Task ID: 1
Description: Prepare moon launch materials
Task ID: 2
Description: Check spaceship fuel levels

Select an option: 3

Enter task ID to remove: 2
Task removed successfully!

Select an option: 2

Current Tasks:
Task ID: 1
Description: Prepare moon launch materials

Select an option: 4
Exiting Minions Task Manager. Have a great day!

## 4.Kalman Missile
Write a C/C++ program that takes two sensor measurements (just
two arrays) and generates only one new array measurement with
any averaging method, such as Kalman Filter.

- The two sensors have two different accuracies one has 79% and
another one has 92%, (You should consider this information in
your output formula).
- IMU sensor outputs the forces in all spatial coordinates x, y, z,
but for the sake of simplicity we only work in one dimension
which is y.
- Assume two sensors have the same sample frequency, (that
means the two arrays have the same number of elements)

## The Output should be:
one single array from the input arrays with the same
number of elements (this one array should be a better description
of the missile projectile).

## 5. Ac to Dc converter 
1. Design a circuit that takes 220V AC as input and the output is 5V
DC and connects LED to the output (Hint: firstly, you need to step
down the AC, then you need to convert AC to DC, and lastly connect the
load).
2. If the input power budget of your power supply is 1440W, and you
use a current limiting resistor with each LED 330 ohm. Estimate
how many LEDs could be put in parallel that is suitable for this
power budget.

## 6.H-bridge
It is used to design a simple H-bridge driver to control the direction of the DC
motor using transistors using proteus.

## 7.Batteries problem
If you have a simple circuit that drive high power 12V LED
with current limiting resistor 3.3ohm and need to drive
them with 80C liPo (lithium Polymer) batteries that have
5200mAh charge, assume that girls stay inside the box of
shame for about 5 hours. How many batteries are
connected in parallel to light up the LED for more than 5
hours
1. Assume all batteries have equal voltage
2. Assume the LED is ideal (deal with it as a short circuit in
forward bias)
3. The current limiting resistor is a high-power resistor.
**In addition**, write summary about BMS (battery management system) with its benefits and applications.

## 8. Led intensity control
This task requires designing a circuit using tinkercad where two push buttons control the intensity of a LED providing the usage of I2C communication protocol.
Push buttons      LED          Serial Monitor
B1=0, B2=0   0% of Maximum     No message
B1=1, B2=0   50% of Maximum    Vector focused
B1=0, B2=1   75% of Maximum    Vector distracted
B1=1, B2=1   100% of Maximum   Glitch
 
## 9. Object localization
You have the cookie bot with four ultrasnoic that
measure the distance each up to 8m positioned as
shown. Specifically, positioned at (0°, 90°, 180°, 270°) from
the Cookie headings.

The Shrink ray champer is (5m x 6m), and we
need to localize the position of the cookie bot on
that champer (localization in this problem
means to get (x,y) of the robot with respect to
the room).

- Assume the cookie bot only moves in forward
or lateral (there is no rotation).
- Assume the origin of the chamber on the left-down corner

**Write a summary about the algorithms needed for object localization using SLAM**

## 10. Battlefield game
The task is to execute a simplified game using python language where two opponents one can choose shield and the other must choose weapon where different types of weapons and shields have different energy values which decreases the opponent energy and a damage value that drop the opponent health where the game ends when either opponent health or energy reaches zero.
In additon to designing a UML schematic explaining the code written.

## 11. Linear Regression Model
1. Create Linear Regression Model, and train
this model on the dataset given in Linear Regression branch:
- The knob of the Gun has a range from [0
MW, 300MW]
- Assume that shrinkage does not depend
on the volume of the target object
- Use Jupyter Notebook for your process
flow
2. If Gru needs to shrink the moon with a percentage 85% where
should he adjust the knob?

3. Plot the dataset as scatter plot and also plot the linear model in the
same chart using matplotlib