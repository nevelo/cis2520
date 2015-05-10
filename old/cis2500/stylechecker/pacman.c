/*******************************obstruc.c*************************************
Student Name: Matt Saunders               Student Number: 0906453
Date: January 23, 2015                       Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
*********************************************************************************/

#include "pacman.h"

int main(void)
{
    unsigned char * board;
    struct Pill * pills;
    struct PacmanVar * pacman;
    
    board = calloc(MEMORY_REQ, sizeof(unsigned char));
    pacman = malloc(sizeof(struct PacmanVar));
    if (board == NULL || pacman == NULL)
    {
        printError(1);
        return -1;
    }
    
    pills = initialize(board, pacman);
    
    playGame(board, pills, pacman);
    
    refresh();
    
    endwin();
    free(board);
    free(pills);
    return 0;
}

void drawBoard(unsigned char * board)
{
    int i; // row pos
    int j; // column pos
    // board is 20 columns wide, 11 rows tall
    
    /* Runs through the array for the game board, printing the proper "wall"
     * character wherever it's needed. */
    
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 20; j++)
        {
            switch (*(board+(i*20)+j))
            {
                case 0:
                    break;
                    
                case 1:
                    mvaddch(i, j, ACS_ULCORNER);
                    break;
                    
                case 2:
                    mvaddch(i, j, ACS_LLCORNER);
                    break;
                
                case 3:
                    mvaddch(i, j, ACS_URCORNER);
                    break;
                    
                case 4:
                    mvaddch(i, j, ACS_LRCORNER);
                    break;
                    
                case 5:
                    mvaddch(i, j, ACS_RTEE);
                    break;
                    
                case 6:
                    mvaddch(i, j, ACS_LTEE);
                    break;
                    
                case 7:
                    mvaddch(i, j, ACS_BTEE);
                    break;
                
                case 8:
                    mvaddch(i, j, ACS_TTEE);
                    break;
                    
                case 9:
                    mvaddch(i, j, ACS_HLINE);
                    break;
                    
                case 10:
                    mvaddch(i, j, ACS_VLINE);
                    break;
                    
                case 11:
                    mvaddch(i, j, ACS_PLUS);
                    break;
            }
        }
    }
       
    return;
}

void drawPacman(struct PacmanVar * pacman)
{
    char pacDir;
    if(pacman->dir == north)
        pacDir = 'W';
    
    if(pacman->dir == west)
        pacDir = '3';
        
    if(pacman->dir == east)
        pacDir = 'E';
        
    if(pacman->dir == south)
        pacDir = 'M';
        
    mvaddch(pacman->yloc, pacman->xloc, pacDir);
    return;
}

void drawPills(struct Pill * pills, int numPills)
{
    int i;
    int row;
    int col;
    char pillStyle;
    
    for (i = 0; i <= numPills; i++)
    {
        if ( ((pills+i)->eaten) == true )
            continue;
        else
        {
            row = (pills+i)->yloc;
            col = (pills+i)->xloc;
            pillStyle = (char)(0x2E + ((pills+i)->type)*0x41); // Chooses either '.' or 'o' depending on stored value.
            mvaddch(row, col, pillStyle);
        }
    }
}

void eat(struct Pill * pills, int row, int col, int numPills)
{
    int i;
    for(i = 0; i < numPills; i++)
    {
        if((pills+i)->yloc == row && (pills+i)->xloc == col)
        {
            (pills+i)->eaten = TRUE;
            break;
        }
    }
    return;
}

struct Pill * initialize(unsigned char * board, struct PacmanVar * pacman)
{
    FILE * boardLayout;
    FILE * pillLayout;
    struct Pill * curPill; // pointer to struct .. wacky!
    //int maxrow;
    //int maxcol;
    int row;
    int col;
    int value;
    int i = -1; // 
    
    /* Reads the board layout from a file.  Instead of hardcoding the layout
     * and compiling it into binary, we just have a board.dat from which the
     * coordinates are read. */
    boardLayout = fopen("data/board.dat", "r");
    if (boardLayout == NULL)
        return NULL;
    
    /* Same deal, for pill layout. */
    pillLayout = fopen("data/pills.dat", "r");
    if (pillLayout == NULL)
        return NULL;
    
    curPill = malloc(100 * sizeof(struct Pill)); // pointer to array of structs... scary!
    if (curPill == NULL)
        return NULL;
    
    // Until the end of file is reached, keep reading in data.
    while (feof(boardLayout) != TRUE)
    {
        // Reads in data.
        fscanf(boardLayout, "%d %d %d", &row, &col, &value);
        // Puts it in its proper place.
        *(board+(row*20)+col) = (unsigned char) value;
    }
    
    while (feof(pillLayout) != TRUE)
    {
        i++; //  Incremented here so when we exit the loop, the value points to the last element
        fscanf(pillLayout, "%d %d %d", &row, &col, &value);
        (curPill+i)->type = value;
        (curPill+i)->xloc = col;
        (curPill+i)->yloc = row;
        (curPill+i)->eaten = FALSE;
    }
    *(board+220) = i; // Stores the amount of pills we have in the main board array.
    
    fclose(boardLayout);
    fclose(pillLayout);
    
    // Initialize pacman
    pacman->state = scared;
    pacman->xloc=10;
    pacman->yloc=7;
    pacman->dir=east;
    
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    
    //getmaxyx(stdscr, maxrow, maxcol);
    
    return curPill;
}

int movePacman(unsigned char * board, struct Pill * pills, struct PacmanVar * pacman)
{
    int move;
    char validate = '\0';
    
    move = getch();
    mvaddch(pacman->yloc, pacman->xloc, ' ');
    
    switch (move)
    {
        case KEY_UP:
        case 'i':
            validate = mvinch((pacman->yloc - 1), pacman->xloc);
            if ( validate == '.' || validate == ' ' || validate == 'o')
                pacman->yloc = pacman->yloc - 1;
            pacman->dir = north;
            break;            
            
        case KEY_LEFT:
        case 'j':
            validate = mvinch(pacman->yloc, (pacman->xloc - 1));
            if ( validate == '.' || validate == ' ' || validate == 'o')
                pacman->xloc = pacman->xloc - 1;
            pacman->dir = west;
            break;  
        
        case KEY_DOWN:
        case 'k':
            validate = mvinch((pacman->yloc + 1), pacman->xloc);
            if ( validate == '.' || validate == ' ' || validate == 'o')
                pacman->yloc = pacman->yloc + 1;
            pacman->dir = south;
            break; 
        
        case KEY_RIGHT:
        case 'l':
            validate = mvinch(pacman->yloc, (pacman->xloc + 1));
            if ( validate == '.' || validate == ' ' || validate == 'o')
                pacman->xloc = pacman->xloc + 1;
            pacman->dir = east;
            break;
                   
        case 'q':
        case 'Q':
            return 1;
    }
    
    if ( validate == '.' || validate == 'o')
        eat(pills, pacman->yloc, pacman->xloc, (int)*(board+220));
    
    return 0;
}

void playGame(unsigned char * board, struct Pill * pills, struct PacmanVar * pacman)
{
    int winrar = 0;
        
    while (winrar == 0)
    {
        drawBoard(board);
        drawPills(pills, *(board+220));
        drawPacman(pacman);
        winrar = movePacman(board, pills, pacman);
    }
    
    return;
}

void printError(int error)
{
    switch (error)
    {
        case 1:
            fprintf(stderr, "Err 1: Cannot allocate memory.\n");
            break;
            
        case 2:
            fprintf(stderr, "Err 2: Could not import board layout data.\n");
            break;
    }
    
    return;
}
        
