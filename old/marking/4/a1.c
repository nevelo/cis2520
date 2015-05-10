#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

void player1(char *name1, int count1);
void player2(char *name2, int count2);
void cursorMove (char character);
int obstruct (int turnNum);

int main ()

{

    int i, count1, count2, tempX, tempY, validMove, turnNum, score2, score1;
    char name1[750], name2[750], character;

    turnNum = 1;
    count1 = 0;
    count2 = 0;
    score2 = 0;
    score1 = 0;

    initscr();

    printw("Welcome to Obstruction! Please maximize the game window and");
    printw(" press any key to continue after you have done so.\n");
    getch();
    printw("Player 1, please enter your name: \n");

    while ((character = getch()) != '\n')
    {
        name1[count1] = character;
        count1++;
    }

    printw("Welcome, ");

    player1(&name1[0], count1);

    printw(".");
    printw("\nPlayer 2, please enter your name: \n");

    while ((character = getch()) != '\n')
    {
        name2[count2] = character;
        count2++;
    }

    printw("Welcome, ");

    player2(&name2[0], count2);

    printw(". Press any key to continue.");
    getch();
    erase();

    move(0, 0);
    printw("Welcome to Obstruction! ");
    printw("Press i, j, k, or l to move up, left, down, or right respectively. ");
    printw("Press x to select ");
    move(1, 62);
    printw("the cell you wish to obstruct. Press q to quit.");
    move(30,62);
    printw("Hint: try to force your opponent to give you the last move.");
    printw(" Near the end");
    move(31,61);
    printw(" of the game, try to plan your moves so that ");
    printw("you'll have the last move.");

    cbreak ();
    noecho ();

    for (i = 0; i < 7; i++)
    {
        move (1,0+i*10);
        vline('o',30);
    }

    for (i = 0; i < 7; i++)
    {
        move (1+i*5,0);
        hline('o',61);
    }

    move (2,1);

    getyx(stdscr,tempY,tempX);
	move(3,62);

    if (turnNum % 2 == 1)
		player1(&name1[0], count1);
	else
		player2(&name2[0], count2);

	printw(", it is your turn. ");
	move(tempY, tempX);
    character = getch();

    while (character != 'q')
    {
		getyx(stdscr,tempY,tempX);
		move(3,62);

		if (turnNum % 2 == 1)
			player1(&name1[0], count1);
		else
			player2(&name2[0], count2);

		printw(", it is your turn. ");
		move(tempY, tempX);
        cursorMove(character);
        character = getch();
        getyx(stdscr,tempY,tempX);
        move(2,62);
        printw("                                                     ");
        move(4,62);
        printw("                                                     ");
        //move(5,62);
        //printw("                                                     ");
        move(tempY, tempX);

        if (character == 'x')
        {
            validMove = obstruct(turnNum);
            /* Instead of using pointers to return multiple values, I
            just returned validMove to main. If its value is 0 or 1, the
            move is either invalid or valid. If its value is 2 or 3, the
            game is over, and 2 means that player 2 won, and 3 means
            that player 1 won.
            */

            switch (validMove)
            {
				case 0:
					move(4,62);
					printw("This move is invalid. Please choose a different cell.");
					move(tempY, tempX);
					break;

				case 1:
            		turnNum++;
					break;

				case 2:
					score2++;
					clear();
					printw("Congratulations, ");
					player2(&name2[0], count2);
					printw(" wins!");
					printw("\nPress any key to continue.");
					move(6, 62);
					printw("Score: \n");
					move(7, 62);
					player1(&name1[0], count1);
					printw(": %d", score1);
					move(8, 62);
					player2(&name2[0], count2);
					printw(": %d", score2);
					getch();
					break;

				case 3:
					score1++;
					clear();
					printw("Congratulations, ");
					player1(&name1[0], count1);
					printw(" wins!");
					printw("\nPress any key to continue.");
					move(6, 62);
					printw("Score: \n");
					move(7, 62);
					player1(&name1[0], count1);
					printw(": %d", score1);
					move(8, 62);
					player2(&name2[0], count2);
					printw(": %d", score1);
					getch();
					break;

			}

		}

		if (validMove >= 2)
	    {
			validMove = 1;
			move(0,0);
			printw("Welcome to Obstruction! ");
		    printw("Press i, j, k, or l to move up, left, down, or right respectively. ");
		    printw("Press x to select ");
		    move(1, 62);
		    printw("the cell you wish to obstruct. Press q to quit.");
		    move(30,62);
		    printw("Hint: try to force your opponent to give you the last move.");
		    printw(" Near the end");
		    move(31,61);
		    printw(" of the game, try to plan your moves so that ");
		    printw("you'll have the last move.");

		    for (i = 0; i < 7; i++)
		    {
		        move (1,0+i*10);
		        vline('o',30);
		    }

		    for (i = 0; i < 7; i++)
		    {
		        move (1+i*5,0);
		        hline('o',61);
		    }

		    move (2,1);

		}

	}

    endwin();
    return 0;
}
/*
player1: Prints the name of the first player to the screen.
Pre: Takes in the array in which the player's name is stored, and a count
variable which stores how many characters the player's name contains.
Post: The player's name is printed.
*/
void player1 (char *name1, int count1)
{
	int i;

	for (i = 0; i < count1; i++)
    {
        if (name1[i] != '\0')
            printw("%c", name1[i]);
    }
}
/*
player2: Prints the name of the second player to the screen.
Pre: Takes in the array in which the player's name is stored, and a count
variable which stores how many characters the player's name contains.
Post: The player's name is printed.
*/
void player2 (char *name2, int count2)
{
	int i;

	for (i = 0; i < count2; i++)
    {
        if (name2[i] != '\0')
            printw("%c", name2[i]);
    }
}
/*
cursorMove: Moves the cursor based on the key the player presses.
Pre: Pass in character corresponding to the key the player pressed.
Post: Cursor is moved if the key is a movement key.
*/
void cursorMove (char character)
{
    int yCoord, xCoord;

    getyx(stdscr,yCoord,xCoord);

    switch (character)
    {
        case 'i':
            yCoord = yCoord - 5;
            break;

        case 'k':
            yCoord = yCoord + 5;
            break;

        case 'j':
            xCoord = xCoord - 10;
            break;

        case 'l':
            xCoord = xCoord + 10;
            break;

        case 'x':
            break;

        default:
            move(2, 62);
            printw("Please press one of the appropriate keys.");
            move(yCoord, xCoord);
            //getch();
    }

    if ((yCoord >= 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55))
    {
        move(yCoord, xCoord);
        refresh();
    }
}

/*
obstruct: Determines if a player's cell selection is a valid move, if so,
fills the adjacent cells to the one the player chose.
Pre: Pass in the turn number.
Post: Returns validMove to main, which allows it to determine if the
move was valid, and also if the game has ended.
*/
int obstruct (int turnNum)
{
    int validMove, yCoord, xCoord, cellY, cellX, count, i;
    static int gameBoard[6][6];

    validMove = 1;

    getyx(stdscr, yCoord, xCoord);
    cellY = ((yCoord+3)/5)-1;
    cellX = ((xCoord+9)/10)-1;

    if (gameBoard[cellY][cellX] == 1)
        validMove = 0;

    else
    {
	/*This else contains my algorithm for filling the adjacent cells
	around the chosen cell. If the cell chosen is a valid move, this else
	will execute. This else first fills the current cell, and also changes
	the cell's corresponding value in my 2D array to 1, making the cell
	no longer a valid move for future turns. Then, it does the same
	thing for the adjacent cells. It does this by going up one cell from
	the initial cell, then right, down twice, left twice and up twice,
	filling all of the adjacent cells as well as changing the array
	value so that the cell will be an invalid cell for future moves.
	*/

        for (count = 0; count <= 4; count++)
        {
			hline('l', 9);
            move(yCoord+count, xCoord);
        }

        gameBoard[cellY][cellX] = 1;
        cellY = cellY - 1;
        yCoord = yCoord - 5;

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellY >= 0 && cellY <= 5) && (cellX >= 0 && cellX <= 5))
        {
            gameBoard[cellY][cellX] = 1;
            move(yCoord, xCoord);

            for (count = 0; count <= 4; count++)
            {
                hline('x', 9);
                move(yCoord+count, xCoord);
            }

        }

        cellX = cellX + 1;
        move(yCoord, xCoord);
        xCoord = xCoord + 10;

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellX >= 0 && cellX <= 5))
        {
            gameBoard[cellY][cellX] = 1;
            move(yCoord, xCoord);

			for(count = 0; count <= 4; count++)
		    {
				hline('x', 9);
				move(yCoord+count, xCoord);
			}
        }

        cellY = cellY + 1;
        move(yCoord, xCoord);
        yCoord = yCoord + 5;

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellY >= 0 && cellY <= 5) && (cellX >= 0 && cellX <= 5))
        {
            gameBoard[cellY][cellX] = 1;
            move(yCoord, xCoord);

            for (count = 0; count <= 4; count++)
            {
                hline('x', 9);
                move(yCoord+count, xCoord);
            }

        }

        cellY = cellY + 1;
        move(yCoord, xCoord);
        yCoord = yCoord + 5;

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellY >= 0 && cellY <= 5) && (cellX >= 0 && cellX <= 5))
        {
            gameBoard[cellY][cellX] = 1;
            move(yCoord, xCoord);

			for(count = 0; count <= 4; count++)
		    {
				hline('x', 9);
				move(yCoord+count, xCoord);
			}
        }

        cellX = cellX - 1;
        move(yCoord, xCoord);
        xCoord = xCoord - 10;

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellX >= 0 && cellX <= 5))
        {
            gameBoard[cellY][cellX] = 1;
            move(yCoord, xCoord);

			for(count = 0; count <= 4; count++)
		    {
				hline('x', 9);
				move(yCoord+count, xCoord);
			}
        }

        cellX = cellX - 1;
        move(yCoord, xCoord);
        xCoord = xCoord - 10;

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellX >= 0 && cellX <= 5))
        {
            gameBoard[cellY][cellX] = 1;
            move(yCoord, xCoord);

			for(count = 0; count <= 4; count++)
		    {
				hline('x', 9);
				move(yCoord+count, xCoord);
			}
        }

        cellY = cellY - 1;
        move(yCoord, xCoord);
        yCoord = yCoord - 5;

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellY >= 0 && cellY <= 5) && (cellX >= 0 && cellX <= 5))
        {
            gameBoard[cellY][cellX] = 1;
            move(yCoord, xCoord);

			for(count = 0; count <= 4; count++)
		    {
				hline('x', 9);
				move(yCoord+count, xCoord);
			}
        }

        cellY = cellY - 1;
        move(yCoord, xCoord);
        yCoord = yCoord - 5;

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellY >= 0 && cellY <= 5) && (cellX >= 0 && cellX <= 5))
        {
            gameBoard[cellY][cellX] = 1;
            move(yCoord, xCoord);

			for(count = 0; count <= 4; count++)
		    {
				hline('x', 9);
				move(yCoord+count, xCoord);
			}

        }

        if ((yCoord > 0 && yCoord <= 27) && (xCoord >= 0 && xCoord <= 55) && (cellY >= 0 && cellY <= 5) && (cellX >= 0 && cellX <= 5))
            gameBoard[cellY][cellX] = 1;

        yCoord = yCoord + 5;
        xCoord = xCoord + 10;
        move(yCoord, xCoord);
    }

	for (count = 0; count < 6; count++)
    {
		for(i = 0; i < 6; i++)
	    {
			if (gameBoard[count][i] != 1)
				return validMove;
		}

	}

	validMove = (turnNum % 2) + 2;

	if (validMove >= 2)
    {
		for (count = 0; count < 6; count++)
	    {
			for(i = 0; i < 6; i++)
		    {
				gameBoard[count][i] = 0;

			}

		}

	}

	return validMove;
}
