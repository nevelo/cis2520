/************************A1.c****************************
Student Name:                                     Student Number:
Date: 16/01/15                                    Course Name: CIS 2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course
****************************************************************************/
#include "A1.h"

int main() // the main function is used for two players to play a game of Obstruction against eachother
{
    char user1Name[32];
    char user2Name[32];
    char userInput;
    int player = 1;
    int length;
    printf("Welcome. Please enter player 1's name:\n");
    fgets(user1Name, 32, stdin); // takes in the first user's name
    length = strlen(user1Name);
    user1Name[length-1] = '\0'; // sets the newline character at the end to a null terminator 
    printf("Thank you. Please enter player 2's name:\n");
    fgets(user2Name, 32, stdin); // takes in the second user's name
    length = strlen(user2Name);
    user2Name[length-1] = '\0';
    initscr(); // initializes ncurses
    cbreak();
    noecho();
    mvprintw(3, 5, "Welcome to Obstruction! %s VS. %s", user1Name, user2Name);
    mvprintw(4, 5, "%s goes first . . .", user1Name);
    mvprintw(7, 5, "h = help\tq = quit\tspacebar = select square");
    drawBoard(); // calls function do draw the empty board
    move (11, 36);
    while ((userInput!='q') && (userInput!='Q')) // loop to keep moving the cursor around
    {
        userInput = getch();
        cursor(userInput, &player, user1Name, user2Name); // calls cursor function which allows user to move cursor around the screen
    }
    mvprintw(6, 5, "Thanks for playing Obstruction!");
    refresh();
    getch();
    endwin();
    
    return 0;
}

void drawBoard()
{
    int i;
    for (i=35;i<48;i++) // for loop to draw all the rows for the board
    {
        mvaddch(10, i, '-');
        mvaddch(22, i, '-');
        mvaddch(12, i, '-');
        mvaddch(14, i, '-');
        mvaddch(16, i, '-');
        mvaddch(18, i, '-');
        mvaddch(20, i, '-');
    }
    for (i=11;i<23;i++) // for loop to draw all the columns for the board
    {
        mvaddch(i, 35, '|');
        mvaddch(i, 47, '|');
        mvaddch(i, 37, '|');
        mvaddch(i, 39, '|');
        mvaddch(i, 41, '|');
        mvaddch(i, 43, '|');
        mvaddch(i, 45, '|');
    }
}
     
void cursor(char movement, int *player, char player1[], char player2[]) // function to move the cursor around the board
{
    int xPos = 0;
    int yPos = 0;
    int i;
    
    getyx (stdscr, yPos, xPos); // gets current position of cursor and stored it in yPos and xPos
    mvprintw(5, 5, "                                           ");

    switch (movement) // switch statement to move cursor around or select a square or other options
    {    
        case 'i':
            yPos--;
            break;
        case 'j':
            xPos--;
            break;
        case 'k':
            yPos++;
            break;
        case 'l':
            xPos++;
            break;
        case 'q':
            break;
        case 'h':
            helpMessage();
            break;
        case ' ':
            if (nextChar(yPos, xPos)) // calls function nextChar with current cursor position
            {
                mvprintw(15, 0, "You can only go in an empty space!");
            }
            else
            {
                mvprintw(yPos, xPos, "."); // fills in the square the user selected
                mvprintw(yPos+2, xPos+2, "x"); // these statements block off spaces directly adjacent/diagonal to a taken square
                mvprintw(yPos+2, xPos-2, "x");
                mvprintw(yPos-2, xPos+2, "x");
                mvprintw(yPos-2, xPos-2, "x");
                mvprintw(yPos+2, xPos, "x");
                mvprintw(yPos-2, xPos, "x");
                mvprintw(yPos, xPos+2, "x");
                mvprintw(yPos, xPos-2, "x");
                mvprintw(9, 30, "                                 "); // clears away x's outside of the board
                mvprintw(23, 30, "                                "); // ""
                for (i=10;i<24;i++)
                {
                    mvprintw(i, 34, " ");
                    mvprintw(i, 48, " "); 
                }
            }
            if (gameOver()) // checks to see if the game is over yet
            {
                endGame(); // if so, calls endGame function
            }
            if (*player == 1) // switches players
            {
                *player = 2;
            }
            else
            {
                *player = 1;
            }
            if (*player==1)
            {
                mvprintw(4, 5, "%s's turn               ", player1); // calls user by his/her name
            }
            else
            {
                mvprintw(4, 5, "%s's turn               ", player2); // ""
            }
            break;
        default:
            mvprintw(8, 5, "Use ijkl to move or q to quit only"); // tells user to use these keys if they are not
    }
    if (xPos>45) 
    {
        xPos=46;
    }
    if (yPos>20)
    {
        yPos=21;
    }
    if (xPos<37)
    {
        xPos=36;
    }
    if (yPos<12)
    {
        yPos=11;
    }
    move (yPos, xPos); // does not allow user to go outside of the range of the board
    refresh();
}


void helpMessage() // function to display help message if the 'h' key is pressed during the game
{
    mvprintw(0, 1, "Players take turns choosing a box to move in.\n Players cannot move in a box touching another box that is already used.\n");
    mvprintw(2, 3, "Use i, j, k, and l buttons to move the cursor,\n and the spacebar to select a valid box. Last to move wins.");
}

int nextChar(int y, int x) // checks the character at the position y, x to see if it is occupied already
{
    char taken;
    taken = mvinch(y,x); // sets variable taken to the char at position y,x
    if ((taken == 'x')||(taken == '.')||(taken == '-')||(taken == '|')) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
    
int gameOver() // function that checks to see if the game is over yet
{
    int row;
    int column;
    int totalUsed = 0;
    
    for (column=10;column<22;column++) // for loops to go through each coordinate on the board
    {
        for (row=35;row<47;row++)
        {
            if ((mvinch(column, row)=='.')||(mvinch(column, row)=='x')) // if any coordinate is occupied, increase totalUsed by 1
            {
                totalUsed++;
            }
        }
    }
    if (totalUsed == 36) // if every square on the board is occupied, then the game is over, and return true
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void endGame() // function to shut down ncurses and exit the program when someone wins
{
    mvprintw(26, 30, "Game Over. Press any button to exit . . .");
    refresh();
    getch();
    endwin(); // closes ncurses
    exit(0); // exits the program
}
