# Pedestrian Traffic Light

Arduino-based traffic light system with pedestrian crossing control.


## Overview

This project consists of an Arduino-based traffic light system that simulates a vehicle traffic light and a pedestrian crossing system.

The system uses LEDs to represent the traffic lights and a push button to request a pedestrian crossing sequence.

## Objectives

The main objectives of this project were:

- Learn how to control multiple digital outputs using Arduino
- Learn how to read a push button input
- Implement timed sequences using `millis()`
- Understand and implement a state machine
- Develop basic electronics and debugging skills

## Hardware

- Arduino
- 2x Red LEDs
- 1x Yellow LED
- 2x Green LEDs
- Push button
- Resistors
- Breadboard
- Jumper wires

## Circuit

The LEDs are connected to digital output pins on the Arduino through resistors.

The push button is connected to a digital input and is used to request the pedestrian crossing sequence.

## Pin Configuration

| Component | Arduino Pin |

| Vehicle Red LED | 8 |
| Vehicle Yellow LED | 9 |
| Vehicle Green LED | 10 |
| Pedestrian Red LED | 11 |
| Pedestrian Green LED | 12 |
| Push Button | 2 |

## Control Logic

The traffic light operates using a state-machine approach.

The system has four states:

- Green — Normal vehicle traffic for 10 seconds
- Safety — 1-second safety period only when the pedestrian button is pressed
- Yellow — Vehicle traffic light for 1 second
- Red — Vehicle traffic light for 7 seconds while pedestrians can cross


The normal traffic light cycle consists of:

1. Red
2. Yellow
3. Green
4. Red

The pedestrian traffic light is controlled according to the state of the vehicle traffic light.

When the pedestrian button is pressed, the system modifies the current sequence to allow the pedestrian crossing phase to occur faster.


## Programming

The system was programmed using the Arduino IDE software, and I chose C/C++ as the language.

The project uses:

- Digital inputs and outputs
- `millis()` for non-blocking timing
- State machines
- Button input handling

The complete source code is available in:

`pedestrian-traffic-light.ino`

## Testing

The system was tested under different operating conditions, including normal operation and pedestrian button activation.

During development, the timing and button behaviour were adjusted to ensure that the pedestrian crossing could be requested without unnecessarily waiting for the entire traffic-light cycle.

## What I Learned

This project helped me develop my understanding on basic electronics, Arduino programming and sequential control systems. It also helped me develop my capacity to think about real world problems and a solution to fix them and also to think about the logic behind some everyday systems

I learned how to control multiple digital outputs, read button inputs and implement timed sequences.

I also learned how to structure a control system using a state machine and how to debug both hardware and software problems during development.

## Future Improvements

Possible future improvements include improving the physical construction of the traffic light and expanding the system with additional traffic-control features.

## Challenges and Solutions
During this project I face some problems,mostly while coding because I wasn't being able to put the times coordinated so it was in that point that I made the phase diagram to help me organise my ideas.
