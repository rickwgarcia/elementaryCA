# elementaryCA

## Description
The `elementaryCA` project implements an elementary, one-dimensional cellular automaton where each cell can exist in one of two states: 0 or 1. The automaton rules are determined by the binary representation of a number ranging from 0 to 255. For instance, the number 110 is represented in binary as 01101110. This binary sequence defines the ruleset for cell transformation as shown below:

| State Before | 111 | 110 | 101 | 100 | 011 | 010 | 001 | 000 |
|--------------|-----|-----|-----|-----|-----|-----|-----|-----|
| State After  |  0  |  1  |  1  |  0  |  1  |  1  |  1  |  0  |

For more information about elementary cellular automata, visit [Wikipedia](https://en.wikipedia.org/wiki/Elementary_cellular_automaton).

## Objectives
- **Objective 1:** Accept an integer (0-255) to define the ruleset, an initial state string of 0s and 1s, and the number of steps as arguments. Example: Inputting `110 000000000010000000000 11` sets up rule 110 with the initial center cell state as 0, running for 11 steps.
- **Objective 2:** Print the resulting automaton progression to the terminal, showing the state of the automaton after each step.

## Key Algorithms/Data Structures
- **Data Storage:** The rules are converted from an integer to a binary string and stored in a mapping structure.
- **Data Representation:** The evolving states of the automaton are stored and manipulated using a two-dimensional vector, allowing for efficient state transitions and easy display.
