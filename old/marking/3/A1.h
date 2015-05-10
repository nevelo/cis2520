#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

/* This function is used to move the cursor around in the direction that the user specifies. If the user hits
the space key, they will select the square in which the cursor is currently hovering over. This function returns
void. It takes 4 parameters; a pointer to the player number, the character that the user presses, and the names
of the two users. */
void cursor(char movement, int *player, char player1[], char player2[]);

/* This function is used to draw the empty board for the players to play on by drawing horizontal and vertical
lines in two seperate for loops. It returns void and takes no parameters. */
void drawBoard();

/* This function simply displays a message that is intended to help the user understand the game and the controls.
It is called only if one of the users presses the 'h' key during the game. It takes no parameters and returns void. */
void helpMessage();

/* This function checks to see if the location in which the user is trying to select is valid or not, by checking to
see if it has a character in it other that a blank space. It two integers as parameters and returns true or false/ */ 
int nextChar(int y, int x);

/* This function is used to check if the game is over yet. It does this by getting the total number of spaces that
are occupied, and if it is less than 36 the game continues. If it is 36, the game is over because all 36 spaces have
been filled. It takes no parameters and returns either true or false. */
int gameOver();

/* This function is only called when all spaces have been filled and the game should end. It shuts down ncurses and
exits the program. It takes no parameters and returns void. */
void endGame();
