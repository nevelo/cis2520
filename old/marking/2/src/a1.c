/*********************************a1.c************************************
Student Name:                     Student Number:  
Date:January 15,2015              Course Name: cis2500

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
**************************************************************************/
#include "a1.h"

/*The game will start off by introducing 
  the name of the game all the way till a player wins*/

int main()
{
    char curInput= ' ';
    char p1Name[50];
    char p2Name[50];
    int i;
    int rw = 0;
    int cl = 0;
    int turn = 0;
    int blankS = 0;
    for (i = 0; i <= 50; i = i + 1)
    {
        p1Name[i] = 'o';
    }
    for (i = 0; i <= 50; i = i + 1)
    {
        p2Name[i] = 'o';
    }

    initscr();
    cbreak ();
    noecho ();

    printw("Welcome to OBSTRUCTION the game. Press any key to continue.");
    getch();

    menu1();

    printw("Player 1, enter your first name\n\n\n"
           "return key:to SUBMIT your name");
    move(1, 0);
    while (curInput != '\n')
    {
        getyx(stdscr, rw, cl);
        curInput = getch();
        if (curInput == 127)
        {
            mvaddch(rw, cl - 1, ' ');
            curInput=' ';
            move(rw, cl - 1);
        }
        else
        {
            mvaddch(rw, cl, curInput);
        }
    }
    for (i = 0; i <= 50; i = i + 1)
    {
        p1Name[i] = mvinch(1, i);
    }
    clear();
    curInput=' ';
    printw("Player 2, enter your first name\n\n\n"
           "return key:to SUBMIT your name");
    move(1, 0);
    while (curInput != '\n')
    {
        curInput = getch();
        getyx(stdscr, rw, cl);
        mvaddch(rw , cl, curInput);
    }
    for (i = 0; i <= 50; i = i + 1)
    {
        p2Name[i] = mvinch(1, i); 
    }
    clear();
    refresh();

    blankS = board(menu3());
    blankS = blankS * blankS;
    move(1, 10);
    printw("Current Turn:");
    move(3, 10);
    printw("X[ ]");
    for (i = 0; i <= 50; i = i + 1)
    {
        if (p1Name[i]!=' ')
        {
            printw("%c", p1Name[i]);    
        }
    }
    move(4, 10);
    printw("O[ ]");
    for (i = 0; i <= 50; i = i + 1)
    {
        if (p2Name[i] != ' ')
        {
            printw("%c", p2Name[i]);    
        }   
    }

    while (curInput != 'q' && blankS > 0)
    {
        getyx(stdscr, rw, cl);
        if (turn == 0)
        {
            turn = 1;
            mvaddch(3, 12, '>');
            mvaddch(4, 12, ' ');
            move(1, 1);
        }
        if (curInput == 's' && mvinch(rw, cl)!='O' && mvinch(rw, cl)!='X' && mvinch(rw, cl) != '+')
        {
            if (turn == 1)
            {
                mvaddch(rw, cl, 'X');
                blankS = blankS - okFill(rw, cl - 1);
                blankS = blankS - okFill(rw, cl + 1);
                blankS = blankS - okFill(rw - 1, cl);
                blankS = blankS - okFill(rw + 1, cl);
                blankS = blankS - okFill(rw - 1, cl - 1);
                blankS = blankS - okFill(rw - 1, cl + 1);
                blankS = blankS - okFill(rw + 1, cl - 1);
                blankS = blankS - okFill(rw + 1, cl + 1);
                blankS = blankS - 1;
                turn = 2;
                mvaddch(3, 12, ' ');
                mvaddch(4, 12, '>');
            }
            else if (turn == 2)
            {
                mvaddch(rw,cl,'0');
                blankS = blankS - okFill(rw, cl - 1);
                blankS = blankS - okFill(rw, cl + 1);
                blankS = blankS - okFill(rw - 1, cl);
                blankS = blankS - okFill(rw + 1, cl);
                blankS = blankS - okFill(rw - 1, cl - 1);
                blankS = blankS - okFill(rw - 1, cl + 1);
                blankS = blankS - okFill(rw + 1, cl - 1);
                blankS = blankS - okFill(rw + 1, cl + 1);
                blankS = blankS - 1;
                turn = 1;
                mvaddch(3, 12, '>');
                mvaddch(4, 12, ' ');
            }
            move(1, 1);
        }        
        if (curInput != 'q' && blankS > 0)
        {
            curInput = getch();
            arrowInput(curInput);
            refresh();
        }
    }
    move(9, 10);
    if (blankS > 0)
    {
        printw("--------------------------\n");
        move(10, 10);
        printw(" You quit the game early! \n");
        move(11, 10);
        printw("--------------------------\n");
    }
    else if (turn == 0)
    {
        printw("---------------------------\n");
        move(10, 10);
        printw("Abnormal Gameplay Occurred.\n");
        move(11, 10);
        printw("---------------------------\n");
    }
    else if (turn == 1)
    {
        move(9, 0);
        printw("************************\n");
        move(10, 0);
        for (i = 0; i <= 50; i = i + 1)
        {
            if (p2Name[i] != ' ')
            {
                printw("%c", p2Name[i]);    
            }   
        }
        printw(", who is using O's wins!\n"
               "************************\n");
    }
    else if (turn == 2)
    {
        move(9, 0);
        printw("***********************\n");
        move(10, 0);
        for (i = 0; i <= 50; i = i + 1)
        {
            if (p1Name[i] != ' ')
            {
                printw("%c", p1Name[i]);    
            }   
        }
        printw(", who is using X's wins!\n"
               "***********************\n");
    }
    refresh();
    getch();
    endwin();
    return (0);
}

/**
 Control: Converts inputs into interaction with the cursor
 Pre: Pass char to interpreter
 Post: char determines cursor movement and does not return a value
*/
void arrowInput (char dir)
{
    int x, y;
    int xNew;
    int yNew;

    getyx(stdscr, y, x);
    xNew = x;
    yNew = y;
    switch (dir)
    {
    case 'i':
    yNew = yNew - 1;
    break;
    case 'k':
    yNew = yNew + 1;
    break;
    case 'j':
    xNew = xNew - 1;
    break;
    case 'l':
    xNew = xNew + 1;
    break;
    }
    if (mvinch(yNew, xNew) != '|' && mvinch(yNew, xNew) != '-')
    {
        move(yNew, xNew);
    }
    else
    {
        move(y, x);
    }
    return;
}

/**
 Menu1: A buffer to display the multiplayer mechanic
 Pre: Takes no values
 Post: Leads to the name creation menu
*/
void menu1()
{
    while (getch() != 's')
    {
        clear();
        printw("*For a 2 Player game of obstruction, press 's' to start");
        move(0, 0);
    }
    clear();
    return;
}

/**
 Menu3: A buffer to display the choices of board sizes
 Pre: Takes no values
 Post: A size is elected and returned
*/
int menu3()
{
    int x = 0;
    int y = 0;
    int size;
    char kBuffer = '0';
    printw("*6x6\n"
           "*7x7\n"
           "*8x8\n"
           "s:to SELECT a option\n\n"
           "i:to go UP a option\n"
           "k:to go DOWN a option\n");
    move(0, 0);
    refresh();
    arrowInput(kBuffer);
    while (kBuffer != 's')
    {
        kBuffer = getch();
        clear();
        printw("*6x6\n"
               "*7x7\n"
               "*8x8\n"
               "s:to SELECT a option\n\n"
               "i:to go UP a option\n"
               "k:to go DOWN a option\n");
        move(y, x);
        arrowInput(kBuffer);
        getyx(stdscr, y, x);
        if (y > 2)
        {
            y = 2;
        }
        else if (y < 0)
        {
            y = 0;
        }
        move(y, 0);        
        refresh();
    }
    clear();
    if (y == 0)
    {
        size = 6;
    }
    else if (y == 1)
    {
        size = 7;
    }
    else if (y == 2)
    {
        size = 8;
    }
    return size;
}

/**
 Board: Creates a given board size visually
 Pre: Passes an int to determine the board's looks
 Post: int is set for the size and is regurgitated
*/
int board(int size)
{
    int i, j;
    printw("+");   
    for (i = 1; i <= size; i = i + 1)
    {
        printw("-");
    }
    printw("+\n");
    for (i = 1; i <= size; i = i + 1)
    {
        printw("|");
        for (j = 1; j <= size; j = j + 1)
        {
            printw(" ");
        }
        printw("|\n");
    }
    printw("+");   
    for (i = 1; i <= size; i = i + 1)
    {
        printw("-");
    }
    printw("+\n"
           "s:to SELECT a spot\n\n"
           "i:to go UP a spot\n"
           "k:to go DOWN a spot\n"
           "j:to go LEFT a spot\n"
           "l:to go RIGHT a spot\n\n"
           "Goal:If the next person can't put down a game piece. You win!\n\n"
           "q:to force QUIT the game");
    return size;
}

/**
 Fill: Determines if a spot should be filled
 Pre: Two int values determines the space elegibility
 Post: An int of 1 is returned when a symbol is placed
*/
int okFill(int y, int x)
{
    int filled = 0;
    if (mvinch(y, x) == ' ')
    {
        mvaddch(y, x, '+');
        filled = 1;
    }
    return filled;
}
