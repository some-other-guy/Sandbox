Readme.txt by Jim Maroulis

Source Files:
- main.cpp 
  - main entry point for the program to handle setting up the needed classes and handling commandline arguments
- Deck.h
  - Header for the Deck class containing the definitions of needed structs and classes to represent a deck of cards
- Deck.cpp
  - Implementation of the Deck class containg the methods needed to shuffle the Deck.
- makefile
  - A simple make file to build the executable
  - Includes an all: and clean: target
- shuffle
  - Executable built.
- shuffle.sh
  - A linux bash script that takes one argument for the highest number of cards in a Deck, and loops through running
    the shuffle executable passing in deck sizes from 1 to the argument value dumping the output to out.txt.
  - This file was used for testing purposes
- out.txt
  - Output text file of the stdout from the program created by shuffle.sh.  Used for testing.
  
Tools Used:
- CentOS 6.0
- Kernel 2.6.32-71
- GCC 4.4.4
- GNU Make 3.81

Original Exercise Description:
This module solves a coding problem that involves shuffling a deck of cards.  The problem
description is as follows:

You are given a deck containing n cards.  While holding the deck:

1. Take the top card off of the deck and create a new deck on the table, putting the cards on top of this new deck.
2. Take the next card off the top and put it on the bottom of the deck in your hand.
3. Continue steps 1 and 2 until all cards are on the table.  This is a round.
4. Pick up the deck from the table and repeat steps 1-3 until the deck is in the original order.

Write a program to determine how many rounds it will take to put a deck back into the original
order.  This will involve creating a data structure to represent the order of the cards.  This
program should be written in C++.  Do not use STL.  It should take a number of cards in the
deck as a command line argument and write the result to stdout.