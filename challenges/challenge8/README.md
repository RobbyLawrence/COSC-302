Name: Robby Lawrence
NetID: rlawren9
Student ID: 000691931

Usage: The program can be compiled with make, and the executable can be run with ./solution.
Input files should be re-directed into cin using "<". The program builds a Needleman-Wunsch table,
following the instructions in the lab write-up, then returns the bottom right entry.

I've also attached a modified Makefile for the assignment; it tests the memory and output, as well
as running the program with the s1ands2.txt file. This can be run with `make test-everything`.

Example:
    Command run: ./solution < s1ands2.txt
    Output: 965
