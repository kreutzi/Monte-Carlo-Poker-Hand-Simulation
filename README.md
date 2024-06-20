# Monte-Carlo-Poker-Hand-Simulation
C-based simulation of poker hands using the Monte Carlo method
The program generates and analyzes a large number of poker hands to calculate the probabilities of different hand types occurring. This simulation can be used to better understand the statistical properties of poker hands and to aid in poker strategy development.
Features

Deck and Card Structures: Defines a standard deck of 52 cards with suits and pips.\
Shuffling Function: Implements a function to shuffle the deck using a random number generator.\
Hand Evaluation: Contains logic to evaluate different poker hands, including:\
    No Pair\
    One Pair\
    Two Pair\
    Three of a Kind\
    Full House\
    Four of a Kind\
Statistical Analysis: Uses an enum and struct to keep track of the frequency of each type of hand.

Compiling the Program:

    gcc -o MonteCarloPoker MonteCarloPoker.c

Running the Simulation:
    
    ./MonteCarloPoker

