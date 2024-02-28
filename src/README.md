# Project 1: Tokenizer

## Description

Tokenize strings entered by the user. Each string is cut down into tokens and
printed. Each string is stored inside a linked list. User can see the past
history of strings entered. User can exit the program.

## Main

File inputUser.c includes tokenizer.h and history.h. This file contains the
main. It will be executed first. The program loops until user exists the program.

## Tokenizer

File tokenizer.h contains the code to tokenize a string.

## History

File history.h contains the code to build a history. Each string is saved as a
pointer in a linked list. The linked list allows the user to find a certain
string they entered. The entire list is printed at the end.

## Run

Enter 'main all' to compile files.

To run the program use: ./inputUser

To enter a string, write a string and hit enter.

To look up a string that was entered write '!' followed the number of the
string. The first entered string is 1 and so on...

To exit the program enter '~'

Enter 'main clean' to clean files.

## Bugs

Do not hit enter while running the program.
