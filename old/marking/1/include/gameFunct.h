
#include "nCursesLetters.h"

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEFT  'j'
#define RIGHT 'l'
#define UP    'i'
#define DOWN  'k'
#define SELECT 'p'

#define TRUE 1
#define FALSE 0
#define BOOLEAN int



void arrowBlink();
void optionsLayout();
void validBoxDraw(int minX, int minY,int gridValues[50][50], int gridMaxX, int gridMaxY);
void borderSetup(int height,int width, int color);
void optionsMenu(int *boardX, int *boardY,  int *AI_ENABLED);
int gameProgres( int gridValues[50][50], int gridMaxX, int gridMaxY );
void boardSetup(int x, int y,int maxX, int maxY, int *marginX, int *marginY);
int gamePlay(int cornerX, int cornerY,int xMod,int yMod, int *player1Score, int *player2Score, int AI_ENABLED, char name1[], char name2[]);
void menuSetup(int menuVar);


/* the function allows easier placement of a colored border on the screen esp. when the screen is cleared and a new border is initiated
 * uses max height and width of scree to draw and takes an int to change the color of the border depending of initialized colors in the main
 * */
void borderSetup(int height,int width, int color)
	 {
    	 int i;
		 curs_set(0);
		 attron(COLOR_PAIR(color));
		 /*top row*/
		 for (i = 0;i < width; i++)
		 {
			 mvaddch(0, i, ' ');
		 }
		 i = 0;
		 /*left side*/    
		 		 for (i = 0;i < height; i++)
		 {
			 mvaddch(i, 0, ' ');
		 }
		 i = 0; 
		 /* bottom row */
		 		 for (i = 0;i < width; i++)
		 {
			 mvaddch(height - 1, i, ' ');
		 }
		 i = 0; 
		 /*right side*/
		 		 for (i = 0;i < height; i++)
		 {
			 mvaddch(i, width - 1, ' ');
		 }
		 attroff(COLOR_PAIR(color));
		 
		 i = 0; 
	}	 
/* sets up the main menu using space created characters, the words will change color based on whether or not they are selected*/

void menuSetup(int menuVar)
     {
		 /* M */
		 mvaddch(7, 22, 'M');
		 mvaddch(6, 23, 'M');
		 mvaddch(5, 24, 'M');
		 mvaddch(4, 25, 'M');
		 mvaddch(3, 26, 'M');
		 mvaddch(4, 27, 'M');
		 mvaddch(5, 28, 'M');  
		 mvaddch(4, 29, 'M'); 
		 mvaddch(3, 30, 'M'); 
		                      
		 mvaddch(4, 31, 'M');
		 mvaddch(5, 32, 'M');
		 mvaddch(6, 33, 'M');
		 mvaddch(7, 34, 'M');
		 /* E */
		 mvaddch(7, 36, 'E');
		 mvaddch(6, 36, 'E');
		 mvaddch(5, 36, 'E');
		 mvaddch(4, 36, 'E');
		 mvaddch(3, 36, 'E');
		 mvaddch(7, 37, 'E');
		 mvaddch(5, 37, 'E');
		 mvaddch(3, 37, 'E');
		 mvaddch(7, 38, 'E');
		 mvaddch(5, 38, 'E');
		 mvaddch(3, 38, 'E');
		 /* N */
		 mvaddch(7, 40, 'N');
		 mvaddch(6, 41, 'N');
		 mvaddch(5, 42, 'N');
		 mvaddch(4, 43, 'N');
		 mvaddch(3, 44, 'N');
		 mvaddch(4, 45, 'N');
		 mvaddch(5, 46, 'N');
		 mvaddch(6, 47, 'N');
		 mvaddch(7, 48, 'N');
		 mvaddch(6, 49, 'N');
		 mvaddch(5, 50, 'N');
		 mvaddch(4, 51, 'N');
		 mvaddch(3, 52, 'N');
		 /* U */
		 mvaddch(3, 54, 'U');
		 mvaddch(4, 54, 'U');
		 mvaddch(5, 54, 'U');
		 mvaddch(6, 54, 'U');
		 mvaddch(7, 54, 'U');
		 mvaddch(7, 55, 'U');
		 mvaddch(7, 56, 'U');
		 mvaddch(7, 57, 'U');
		 mvaddch(7, 58, 'U');
		 mvaddch(7, 59, 'U');
		 mvaddch(3, 59, 'U');
		 mvaddch(4, 59, 'U');
		 mvaddch(5, 59, 'U');
		 mvaddch(6, 59, 'U');
		 
		 /* boxes */
		 attron(COLOR_PAIR(2));
		 move(10,12);
		 printw("      ");
		 move(11,12);
		 printw("      ");
		 move(12,12);
		 printw("      ");
		 
		 move(20,12);
		 printw("      ");
		 move(21,12);
		 printw("      ");
		 move(22,12);
		 printw("      ");
     
         move(30,12);
    	 printw("      ");
		 move(31,12);
		 printw("      ");
		 move(32,12);
		 printw("      ");
		 refresh();
         
         /* setting up selection*/
         outS(14 + 5,10);
         outT(19 + 5,10);
         outA(26 + 3, 10);
         outR(34 + 3, 10);
         outT(40 + 3, 10);
         outG(47 + 3, 10);
         outA(54 +1, 10);
         outM(63 + 2, 10);
         outE(75 + 1, 10);
         
         outR(19, 20);
         outU(24 + 1, 20);
         outL(31 + 1, 20);
         outE(38 + 1, 20);
         outS(44 + 1, 20);
         
         outO(19,30);
         outP(26,30);
         outT(31,30);
         outI(38,30);
         outO(45,30);
         outN(52,30);
         outS(59,30);
         
         if (menuVar == 1)
         {
			 attron(COLOR_PAIR(3));
			 outS(14 + 5,10);
             outT(19 + 5,10);
             outA(26 + 3, 10);
             outR(34 + 3, 10);
             outT(40 + 3, 10);
             outG(47 + 3, 10);
             outA(54 +1, 10);
             outM(63 + 2, 10);
             outE(75 + 1, 10);
             attroff(COLOR_PAIR(3));
             refresh();
             delay_output(100);
             
             attron(COLOR_PAIR(2));
             outR(19, 20);
             outU(24 + 1, 20);
             outL(31 + 1, 20);
             outE(38 + 1, 20);
             outS(44 + 1, 20);
         
             outO(19,30);
             outP(26,30);
             outT(31,30);
             outI(38,30);
             outO(45,30);
             outN(52,30);
             outS(59,30);
             attroff(COLOR_PAIR(2));
			 refresh();
		 }
         else if (menuVar == 2)
         {
			 attron(COLOR_PAIR(3));
			 outR(19, 20);
             outU(24 + 1, 20);
             outL(31 + 1, 20);
             outE(38 + 1, 20);
             outS(44 + 1, 20);
			 attroff(COLOR_PAIR(3));
			 refresh();
             delay_output(100);
			 
			 attron(COLOR_PAIR(2));
			 outO(19,30);
             outP(26,30);
             outT(31,30);
             outI(38,30);
             outO(45,30);
             outN(52,30);
             outS(59,30);
             
             outS(14 + 5,10);
             outT(19 + 5,10);
             outA(26 + 3, 10);
             outR(34 + 3, 10);
             outT(40 + 3, 10);
             outG(47 + 3, 10);
             outA(54 +1, 10);
             outM(63 + 2, 10);
             outE(75 + 1, 10);
			 attroff(COLOR_PAIR(2));
			 refresh();
			 

             
		 }
		 else if (menuVar == 3)
		 {
			 attron(COLOR_PAIR(3));
			 outO(19,30);
             outP(26,30);
             outT(31,30);
             outI(38,30);
             outO(45,30);
             outN(52,30);
             outS(59,30);
			 attroff(COLOR_PAIR(3));
			 refresh();
             delay_output(100);			 
			 attron(COLOR_PAIR(2));
			 outS(14 + 5,10);
             outT(19 + 5,10);
             outA(26 + 3, 10);
             outR(34 + 3, 10);
             outT(40 + 3, 10);
             outG(47 + 3, 10);
             outA(54 +1, 10);
             outM(63 + 2, 10);
             outE(75 + 1, 10);
             
             outR(19, 20);
             outU(24 + 1, 20);
             outL(31 + 1, 20);
             outE(38 + 1, 20);
             outS(44 + 1, 20);
			 attroff(COLOR_PAIR(2));	
			 refresh();			 	     	 
		 }
     }
/* uses values to center the board and create the columns and rows
 * this function is purely the setup of user interface and has no user interaction
 * */
void boardSetup(int x, int y,int maxX, int maxY, int *marginX, int *marginY)
{
	int i = 0;
	int j = 0;
    /*centers board*/
	*marginX = (maxX -x*4)/2;
	*marginY = (maxY -y*4)/2;
	
	clear();
	attron(COLOR_PAIR(2));
	/* column calculation*/
	while (i <= x)
    { 
	    while (j < (y*4))
	    {
		    mvaddch(*marginY + j,*marginX + i*4, ' ');
		    j = j + 1;
	    }
	    j = 0;
		i = i+1;
	}
	i = 0;
	
	/* row calculation */
    while (i <= y)
    {
		while (j <= (x*4))
	    {
		    mvaddch(*marginY + i*4,*marginX + j, ' ');
		    j = j + 1;
	    }
	    j = 0;
		i = i+1;
	}
	refresh();
}
/* provides functionality to the options menu
 * inside the options menu the user is able to select the AI enabled button to turn on computer player opponent
 * when the board size option is selected the user is able to choose how many rows and columns they would like to play with the pointer value of each is passed back to main
 * 
 * */
void optionsMenu(int *boardX, int *boardY,  int *AI_ENABLED)
     {

		 
		 int menuVar = 1;
		 int selected = FALSE;
		 char selection;
		 char input;
		 
		 int direction = 0;
		 optionsLayout(menuVar, boardX, boardY, *AI_ENABLED);
		 
		 refresh();
		 /* player selection menu*/
		 while (menuVar != 0)
		 {
			 selection = getch();
			 if (selection == DOWN)
			 {
				 if ((menuVar + 1) != 4)
				 {
					 menuVar = menuVar + 1;
				 }
				 else
				 {
					 menuVar = 1;
				 }
			 }
			 else if ( selection == UP)
			 {
				 if ((menuVar - 1) != 0)
				 {
					 menuVar = menuVar - 1;
				 }
				 else
				 {
					 menuVar = 3;
				 }				 
			 }
			 else if (selection == 'q')
			 {
				 menuVar = 0;
			 }
			 else if (selection == SELECT)
			 {
				 selected = TRUE;
			 }
			 
			 if (selected == TRUE)
			 {
				 if ((menuVar == 1))
				 {
					 if (*AI_ENABLED == 0)
					 {
						 
						 *AI_ENABLED = 1;
						 selected = FALSE;
					 }
					 else if (*AI_ENABLED ==1)
					 {
						 *AI_ENABLED = 0;
						 selected = FALSE;
					 }
					 /*AI ENABLED*/
					 selected = FALSE;
				 }
				 else if (menuVar == 2)
				 {/* user selection of board size */
					 menuVar = 4;
					 optionsLayout(menuVar, boardX, boardY, *AI_ENABLED);
					 refresh();
					 while (menuVar == 4 || menuVar == 5)
					 {
						 input = getch();
						 if (input == LEFT)
						 {
							 if (menuVar == 4)
							 {
								 menuVar = 5;
							 }
							 else
							 {
								 menuVar = 4;
							 }
						 }
						 else if (input == RIGHT)
						 {
							 if (menuVar == 4)
							 {
								 menuVar = 5;
							 }
							 else
							 {
								 menuVar = 4;
							 }							 
						 }
						 else if (input == UP)
						 {
							 if (menuVar == 4)
							 {
								 if ((*boardX + 1) <= 21)
								 {
								     *boardX = *boardX + 1;
								     move(1,1);
							         printw("%d", *boardX);
							         direction = 1;
							         arrowBlink(menuVar, direction);
							         optionsLayout(menuVar, boardX, boardY, *AI_ENABLED);
							         refresh();
								 }
							     
							 }
							 else
							 {
								 if ((*boardY + 1) <= 12)
								 {
								     direction = 1;
								     *boardY = *boardY + 1;
								     arrowBlink(menuVar, direction);
							         optionsLayout(menuVar, boardX, boardY, *AI_ENABLED);
							         refresh();
								 }

							 }							 
						 }
						 else if (input == DOWN)
						 {
							 if (menuVar == 4)
							 {
								 if ((*boardX - 1) >= 6)
								 {
									 *boardX = *boardX - 1;
							         direction = 2;
							         move(1,1);
							         printw("%d", *boardX);
							         arrowBlink(menuVar, direction);
							         optionsLayout(menuVar, boardX, boardY, *AI_ENABLED);
							         refresh();
							     }
							 }
							 else
							 {
								 if ((*boardY -1) >= 6)
								 {
								     direction = 2;
								     *boardY = *boardY - 1;
								     arrowBlink(menuVar, direction);
							         optionsLayout(menuVar, boardX, boardY, *AI_ENABLED);
							         refresh();
								 }

							 }							 
						 }
						 else if (input == 'q')
						 {
							 menuVar = 2;
							 selected = FALSE;
						 }
						 optionsLayout(menuVar, boardX, boardY, *AI_ENABLED);
					 }
					 
				 }
				 else if (menuVar == 3)
				 {
					 menuVar = 0;
					 selected = FALSE;
					 break;
				 }
			     	 
				 
			 }
			 optionsLayout(menuVar, boardX, boardY, *AI_ENABLED);
			 move(40,40);
			 printw("%d", menuVar);
			 refresh();
			 
		 }
		
	
	 }
	 /* provides the User interface for the options menu using colored spaces selection of an option turns the option green
	  * turning on AI sets the AI box to green 
	  * uses output functions stored in my nCurses letters.h
	  * 
	  * 
	  * */
void optionsLayout(int menuVar, int  *colVal,int *rowVal,int AI_ENABLED)
     {
		 attron(COLOR_PAIR(2));

		 
		 outE(19, 10);
		 outN(25, 10);
		 outA(31 - 1, 10);
		 outB(39 - 1, 10);
		 outL(45 - 1, 10);
		 outE(51 - 1, 10);
		 outA(59, 10);
		 outI(67, 10);
		 

		 
		 outB(19,20);
		 outO(25,20);
		 outA(31, 20);
		 outR(39, 20);
		 outD(46, 20);
		 outS(54, 20);
		 outI(59, 20);
		 outZ(66, 20);
		 outE(72, 20);
		 /*top arrow 1*/
		 mvaddch(19,77, ' '); 
         mvaddch(19,78, ' ');
         mvaddch(19,79, ' ');
         mvaddch(19,80, ' ');
         mvaddch(19,81, ' ');
         
         mvaddch(18,78, ' ');
         mvaddch(18,79, ' ');
         mvaddch(18,80, ' ');
         
         mvaddch(17,79, ' ');
         /*bottom arrow 1*/
         mvaddch(18+7,77, ' '); 
         mvaddch(18+7,78, ' ');
         mvaddch(18+7,79, ' ');
         mvaddch(18+7,80, ' ');
         mvaddch(18+7,81, ' ');
         
         mvaddch(19+7,78, ' ');
         mvaddch(19+7,79, ' ');
         mvaddch(19+7,80, ' ');
         
         mvaddch(20+7,79, ' ');
         /* top arrow 2*/
         mvaddch(19,77+6, ' '); 
         mvaddch(19,78+6, ' ');
         mvaddch(19,79+6, ' ');
         mvaddch(19,80+6, ' ');
         mvaddch(19,81+6, ' ');
         
         mvaddch(18,78+6, ' ');
         mvaddch(18,79+6, ' ');
         mvaddch(18,80+6, ' ');
         
         mvaddch(17,79+6, ' ');
         /*bottom arrow 2*/
         mvaddch(18+7,77+6, ' '); 
         mvaddch(18+7,78+6, ' ');
         mvaddch(18+7,79+6, ' ');
         mvaddch(18+7,80+6, ' ');
         mvaddch(18+7,81+6, ' ');
         
         mvaddch(19+7,78+6, ' ');
         mvaddch(19+7,79+6, ' ');
         mvaddch(19+7,80+6, ' ');
         
         mvaddch(20+7,79+6, ' ');


         
         /*selection box 1*/
         mvaddch(21, 77, ' ');
         mvaddch(21, 78, ' ');
         mvaddch(21, 79, ' ');
         mvaddch(21, 80, ' ');
         mvaddch(21, 81, ' ');
         
         mvaddch(22, 77, ' ');
         mvaddch(22, 78, ' ');
         
         mvaddch(22, 79, ' ');

         mvaddch(22, 80, ' ');
         mvaddch(22, 81, ' ');
         move(22,79);
         printw("%d ", *colVal);
                 
         mvaddch(23, 77, ' ');
         mvaddch(23, 78, ' ');
         mvaddch(23, 79, ' ');
         mvaddch(23, 80, ' ');
         mvaddch(23, 81, ' ');
         
         /*selection box 2*/
         mvaddch(21, 77+6, ' ');
         mvaddch(21, 78+6, ' ');
         mvaddch(21, 79+6, ' ');
         mvaddch(21, 80+6, ' ');
         mvaddch(21, 81+6, ' ');
         
         mvaddch(22, 77+6, ' ');
         mvaddch(22, 78+6, ' ');
         mvaddch(22, 79+6, ' ');
        
         
         mvaddch(22, 80+6, ' ');
         mvaddch(22, 81+6, ' ');
         move(22,79 +6 );
         printw("%d ", *rowVal);
         
         mvaddch(23, 77+6, ' ');
         mvaddch(23, 78+6, ' ');
         mvaddch(23, 79+6, ' ');
         mvaddch(23, 80+6, ' ');
         mvaddch(23, 81+6, ' ');

         
         
 
		 
		 outB(19,30);
         outA(23,30);
         outC(31,30);
         outK(38,30);
         attron(COLOR_PAIR(1));
         move(20,77);
         printw("Columns");
         move(20, 77+6);
         printw("Rows");
         attron(COLOR_PAIR(2));
         if (AI_ENABLED == 1)
		 {
			 attron(COLOR_PAIR(3));
			 move(10,12);
		     printw("      ");
		     move(11,12);
		     printw("      ");
		     move(12,12);
		     printw("      ");
		     refresh();
		 }
		 else
		 {
			 attron(COLOR_PAIR(2));
			 move(10,12);
			 printw("      ");
		     move(11,12);
		     printw("      ");
		     move(12,12);
		     printw("      ");
		     refresh();
		 }
         
         if (menuVar == 1)
         {
			 attron(COLOR_PAIR(3));
		     outE(19, 10);
		     outN(25, 10);
		     outA(31 - 1, 10);
		     outB(39 - 1, 10);
		     outL(45 - 1, 10);
		     outE(51 - 1, 10);
		     outA(59, 10);
		     outI(67, 10);			 
		  	 attroff(COLOR_PAIR(3));
		  	 refresh();
			 delay_output(100);
			 
			 attron(COLOR_PAIR(2));
			 outB(19,20);
		     outO(25,20);
		     outA(31, 20);
		     outR(39, 20);
		     outD(46, 20);
		     outS(54, 20);
		     outI(59, 20);
		     outZ(66, 20);
		     outE(72, 20);
		     
		     outB(19,30);
             outA(23,30);
             outC(31,30);
             outK(38,30);
		     
			 attroff(COLOR_PAIR(2));
			 refresh();
			 
		 }
		 else if (menuVar == 2)
		 {
			 attron(COLOR_PAIR(3));	
			 outB(19,20);
			 outO(25,20);
		     outA(31, 20);
		     outR(39, 20);
		     outD(46, 20);
		     outS(54, 20);
		     outI(59, 20);
		     outZ(66, 20);
		     outE(72, 20); 	
		  	 attroff(COLOR_PAIR(3));
		  	 refresh();
			 delay_output(100);			 
			 attron(COLOR_PAIR(2));			 
			 outB(19,30);
             outA(23,30);
             outC(31,30);
             outK(38,30);
             
 		     outE(19, 10);
		     outN(25, 10);
		     outA(31 - 1, 10);
		     outB(39 - 1, 10);
		     outL(45 - 1, 10);
		     outE(51 - 1, 10);
		     outA(59, 10);
		     outI(67, 10);            
			 attroff(COLOR_PAIR(2));
			 refresh();
         }
		 else if (menuVar == 3)
		 {
			 attron(COLOR_PAIR(3));
			 outB(19,30);
             outA(23,30);
             outC(31,30);
             outK(38,30);			 		  	
		  	 attroff(COLOR_PAIR(3));
		  	 
		  	 refresh();
			 delay_output(100);			 
			 attron(COLOR_PAIR(2));
 		     outE(19, 10);
		     outN(25, 10);
		     outA(31 - 1, 10);
		     outB(39 - 1, 10);
		     outL(45 - 1, 10);
		     outE(51 - 1, 10);
		     outA(59, 10);
		     outI(67, 10);   
		     
			 outB(19,20);
			 outO(25,20);
		     outA(31, 20);
		     outR(39, 20);
		     outD(46, 20);
		     outS(54, 20);
		     outI(59, 20);
		     outZ(66, 20);
		     outE(72, 20); 		     
		     			 			 
			 attroff(COLOR_PAIR(2));
			 refresh();		 	 
		 }
		 else if (menuVar == 4)
		 {
 
             attron(COLOR_PAIR(3));
             /*selection box 1*/
			 mvaddch(21, 77, ' ');
			 mvaddch(21, 78, ' ');
			 mvaddch(21, 79, ' ');
			 mvaddch(21, 80, ' ');
			 mvaddch(21, 81, ' ');
         
			 mvaddch(22, 77, ' ');
			 mvaddch(22, 78, ' ');
			 mvaddch(22, 79, ' ');

			 mvaddch(22, 80, ' ');
			 mvaddch(22, 81, ' ');
 			 move(22,79);
             printw("%d", *colVal);
                     
			 mvaddch(23, 77, ' ');
			 mvaddch(23, 78, ' ');
			 mvaddch(23, 79, ' ');
			 mvaddch(23, 80, ' ');
			 mvaddch(23, 81, ' '); 	     
	  	     
		  	 attroff(COLOR_PAIR(3));
		  	 refresh();
			 delay_output(100);			 
			 attron(COLOR_PAIR(2));

         
                  /*selection box 2*/
		  	 mvaddch(21, 77+6, ' ');
			 mvaddch(21, 78+6, ' ');
			 mvaddch(21, 79+6, ' ');
			 mvaddch(21, 80+6, ' ');
			 mvaddch(21, 81+6, ' ');
         
			 mvaddch(22, 77+6, ' ');
			 mvaddch(22, 78+6, ' ');
			 mvaddch(22, 79+6, ' ');

			 mvaddch(22, 80+6, ' ');
			 mvaddch(22, 81+6, ' ');
 			 move(22,79+6);
             printw("%d", *rowVal);        
			 mvaddch(23, 77+6, ' ');
			 mvaddch(23, 78+6, ' ');
			 mvaddch(23, 79+6, ' ');
			 mvaddch(23, 80+6, ' ');
			 mvaddch(23, 81+6, ' ');
         			 		 
			 attroff(COLOR_PAIR(2));
			 refresh();			 
		 }
		 else if (menuVar == 5)
		 {
			 attron(COLOR_PAIR(3));

         
                  /*selection box 2*/
		  	 mvaddch(21, 77+6, ' ');
			 mvaddch(21, 78+6, ' ');
			 mvaddch(21, 79+6, ' ');
			 mvaddch(21, 80+6, ' ');
			 mvaddch(21, 81+6, ' ');
         
			 mvaddch(22, 77+6, ' ');
			 mvaddch(22, 78+6, ' ');
			 mvaddch(22, 79+6, ' ');

			 mvaddch(22, 80+6, ' ');
			 mvaddch(22, 81+6, ' ');
 			 move(22,79 + 6);
             printw("%d", *rowVal);        
			 mvaddch(23, 77+6, ' ');
			 mvaddch(23, 78+6, ' ');
			 mvaddch(23, 79+6, ' ');
			 mvaddch(23, 80+6, ' ');
			 mvaddch(23, 81+6, ' ');
         
         
		  	 attroff(COLOR_PAIR(3));
		  	 refresh();
			 delay_output(100);			 
			 attron(COLOR_PAIR(2));
 
             
             /*selection box 1*/
			 mvaddch(21, 77, ' ');
			 mvaddch(21, 78, ' ');
			 mvaddch(21, 79, ' ');
			 mvaddch(21, 80, ' ');
			 mvaddch(21, 81, ' ');
         
			 mvaddch(22, 77, ' ');
			 mvaddch(22, 78, ' ');
			 mvaddch(22, 79, ' ');

			 mvaddch(22, 80, ' ');
			 mvaddch(22, 81, ' ');
			 move(22,79);
             printw("%d", *colVal);         
			 mvaddch(23, 77, ' ');
			 mvaddch(23, 78, ' ');
			 mvaddch(23, 79, ' ');
			 mvaddch(23, 80, ' ');
			 mvaddch(23, 81, ' '); 				 			 
			 attroff(COLOR_PAIR(2));
			 refresh();			 
		 }
	 }
	 /* every coordinate of the game grid was previously given a value 
	  * 0 for unoccupied
	  * 1 for invalid move
	  * 2 for x in spot
	  * 3 for O in spot
	  * with this in mind the function checks the value at every point in the grid and draws fills in each space with it's corresponding filler*/
void validBoxDraw(int minX, int minY,int gridValues[50][50], int gridMaxX, int gridMaxY)
     {
		 int i = 0;
		 int j = 0;
		 while (i <= (gridMaxX - 1 ))
		 {
			 while (j <= (gridMaxY - 1))
			 {
				 if (gridValues[i][ j] == 1)
				 {
					 attron(COLOR_PAIR(4));
					 print6Box(minX + i*4, minY + j*4);
					 j++;
					 attroff(COLOR_PAIR(4));
					 

			     }
			     else if (gridValues[i][ j] == 0)
			     {
					 attron(COLOR_PAIR(5));
					 print6Box(minX + i*4, minY + j*4);
					 j++;
					 attroff(COLOR_PAIR(5));
					 
				 }
				 else if (gridValues[i][ j] == 2)	
				 {
					 attron(COLOR_PAIR(4));
					 print6Box(minX + i*4, minY + j*4);
					 attroff(COLOR_PAIR(4));
					 attron(COLOR_PAIR(5));
					 printGameX(minX + i*4, minY + j*4);
					 attroff(COLOR_PAIR(5));
					 j++;
				 }
				 else if (gridValues[i][ j] == 3)
				 {
					 attron(COLOR_PAIR(4));
					 print6Box(minX + i*4, minY + j*4);
					 attroff(COLOR_PAIR(4));
					 attron(COLOR_PAIR(5));
					 printGameO((minX + i*4), (minY + j*4));
					 attroff(COLOR_PAIR(5));
					 j++;
				 }	 
			 }

		     
				 i++;
				 j = 0;
			 
			 
		 }		 
		 
	 }
/* checks if the game is over or not
 * the game is finished if every point on the grid has a value other than 0
 * if a 0 is found the game is still in progress and therefore the loops break and return a false value to the function
 * */
int gameProgres( int gridValues[50][50], int gridMaxX, int gridMaxY )
     {
		 int i = 0;
		 int j = 0;
		 int k = 0;
		 
		 
		 while (i <= (gridMaxX - 1 ))
		 {
			 while (j <= (gridMaxY - 1))
			 {
				 if (gridValues[i][ j] == 1 || gridValues[i][ j] == 2 || gridValues[i][ j] == 3)
				 {
					 j++;
					 
					 

			     }
			     else if (gridValues[i][ j] == 0)
			     {
					 k = 1;
					 break;
					 
				 }		 
			 }
		     if (k == 1)
		     {
			     break;
		     }
		     else
		     {
				 i++;
				 j = 0;
			 }
			 
		 }
		 if (k == 1)
		 {
			 return(0);
		 } 
		 else
		 {
			 return(1);
		 }
		 
		  
	 }	 
	 /*  the actual game portion of the code is encompassed in this function
	  * the game takes a multitude of parameters to make the final game function play without a hitch
	  * the AI and column and row sizes can be changed in the options menu
	  * the player score is made persistent using pointers
	  * 
	  *  */
int gamePlay(int cornerX, int cornerY,int xMod,int yMod, int *player1Score, int *player2Score, int AI_ENABLED, char name1[], char name2[])
     {
		 int xPos = 0;
         int playerTurn = 1;
		 int yPos = 0;
         
         int AI_validMove = 0;

         int maxY = 0;
         int maxX = 0;
         int minX = 0;
         int minY = 0;
         int gridX = 0;
         int gridY = 0;
         int isValid[50][50] = {{0}};
         int endGame = 0;
         char selection;
         int AI_X;
         int AI_Y;
         srand(time(NULL));
         yPos = cornerY + 2;
         xPos = cornerX + 2;
         minX = xPos;
         minY = yPos;
         maxY = yPos + 4*yMod;
         maxX = xPos + 4*xMod;
         
         move(3, 3);
         
         printw("%s's Score %d",name1, *player1Score);
         
         move(5, 3);
         printw("%s's Score %d",name2, *player2Score);
         
         
	     while (selection != 'q' && endGame != 1)
         {
			 validBoxDraw(minX, minY, isValid, xMod, yMod);
             if ( playerTurn == 2)
             {
		         
		         
                 printGameO(xPos, yPos);
                 move(yPos, xPos);
                 refresh();
			 }
			 else if (playerTurn == 0 || playerTurn == 1)
			 {
                 printGameX(xPos, yPos);  
                 move(yPos, xPos);
                 refresh();
             }			
             
             /* AI is based on random number generation, however it still seems to be a worthy opponent */ 
             if (AI_ENABLED == 1)
			 {
			     if (playerTurn == 0)
				 {
				     while (AI_validMove == 0)
				     {
					     AI_X = rand() % (xMod );
					     AI_Y = rand() % (yMod );
							 
						 if (isValid[AI_X][AI_Y] == 0)
					     {
						     if (AI_X -1 >= 0 && AI_Y + 1 <= yMod)
					         {
							     isValid[AI_X - 1][AI_Y + 1] = 1;
							 }
					         if (AI_X -1 >= 0 )
					         {
								 isValid[AI_X - 1][AI_Y] = 1;
							 }
					         if (AI_X -1 >= 0 && AI_Y - 1 >= 0)
					         {
					             isValid[AI_X - 1][AI_Y - 1] = 1;
							 }
							 if (AI_X +1 <= xMod && AI_Y + 1 <= yMod)
							 {
								 isValid[AI_X + 1][AI_Y + 1] = 1;
							 }
					         if (AI_X + 1 <= yMod)
					         {
								 isValid[AI_X][AI_Y + 1] = 1;
							 }
							 if (AI_X +1 <= xMod && AI_Y - 1 >= 0)
							 {
							     isValid[AI_X + 1][AI_Y - 1] = 1;
							 }
							 if (AI_X +1 <= xMod)
							 {
							     isValid[AI_X + 1][AI_Y] = 1;
							 }
							 if (gridY - 1 >= 0)
						     {
								 isValid[AI_X][AI_Y - 1] = 1;
							 }
							     AI_validMove = 1;
							     isValid[AI_X][AI_Y] = 3;	
							     
					    }
					 }
                     AI_validMove = 0;
					 endGame = gameProgres(isValid, xMod, yMod);
					 if (endGame == 0)
					 {
						 playerTurn = 1;
					 }
					 else
					 {
						 playerTurn = 0;
					 }
					 
					 refresh();
		         }  
		     }     
		     /*user input */       
             selection = getch();
             

             if (selection == RIGHT)
             {
                 if (((xPos + 4) < maxX) && ((xPos + 4) >= minX))
                 {
                     
                     gridX++;
                     xPos = xPos +4;

                 }
                
             }
             else if (selection == LEFT)
             {
                 if (((xPos - 4) < maxX) && ((xPos - 4) >= minX))
                 {
                     
                     gridX--;
                     xPos = xPos -4;

                 }
                
             }
             else if (selection == UP)
             {
                 if (((yPos - 4) < maxY) && ((yPos - 4) >= minY))
                 {
                     
                     gridY--;
                     yPos = yPos - 4;

                 }
             }
             else if (selection == DOWN)
             {
                 if (((yPos + 4) < maxY) && ((yPos + 4) >= minY))
                 {
                     
                     gridY++;
                     yPos = yPos + 4;

                 }
             }
             
             else if (selection == SELECT)
             {
                 if (AI_ENABLED == 1)
                 {

					  
					  
				     
	                 if (playerTurn == 1)
				     {
					     if (isValid[gridX][gridY] == 0)
					     {
					         if (gridX -1 >= 0 && gridY + 1 <= yMod)
					         {
								 isValid[gridX - 1][gridY + 1] = 1;
							 }
					         if (gridX -1 >= 0 )
					         {
								 isValid[gridX - 1][gridY] = 1;
							 }
					         if (gridX -1 >= 0 && gridY - 1 >= 0)
					         {
								isValid[gridX - 1][gridY - 1] = 1;
							 }
							 if (gridX +1 <= xMod && gridY + 1 <= yMod)
							 {
								 isValid[gridX + 1][gridY + 1] = 1;
							 }
					         if (gridY + 1 <= yMod)
					         {
								 isValid[gridX][gridY + 1] = 1;
							 }
							 if (gridX +1 <= xMod && gridY - 1 >= 0)
							 {
								 isValid[gridX + 1][gridY - 1] = 1;
							 }
							 if (gridX +1 <= xMod)
							 {
								 isValid[gridX + 1][gridY] = 1;
							 }
							 if (gridY - 1 >= 0)
							 {
								 isValid[gridX][gridY - 1] = 1;
							 }
							 
							 isValid[gridX][gridY] = 2;
					         
					      
					         
					         
					         endGame = gameProgres(isValid, xMod, yMod);
					         
					         move(1,9);
                             printw("  ");
					         printw("%d",endGame);
					         move(1,14);
                    		 if (endGame == 0)
					         {
						     playerTurn = 0;
					         }
				         }
				         else
				         {
							 endGame = gameProgres(isValid, xMod, yMod);
							 move(1,9);
							 printw("  ");
                             printw("%d",endGame);
						 }				     
				     }
			     }
			     else
			     {
		             if (playerTurn == 1)
				     {
					     if (isValid[gridX][gridY] == 0)
					     {
					         if (gridX -1 >= 0 && gridY + 1 <= yMod)
					         {
								 isValid[gridX - 1][gridY + 1] = 1;
							 }
					         if (gridX -1 >= 0 )
					         {
								 isValid[gridX - 1][gridY] = 1;
							 }
					         if (gridX -1 >= 0 && gridY - 1 >= 0)
					         {
								isValid[gridX - 1][gridY - 1] = 1;
							 }
							 if (gridX +1 <= xMod && gridY + 1 <= yMod)
							 {
								 isValid[gridX + 1][gridY + 1] = 1;
							 }
					         if (gridY + 1 <= yMod)
					         {
								 isValid[gridX][gridY + 1] = 1;
							 }
							 if (gridX +1 <= xMod && gridY - 1 >= 0)
							 {
								 isValid[gridX + 1][gridY - 1] = 1;
							 }
							 if (gridX +1 <= xMod)
							 {
								 isValid[gridX + 1][gridY] = 1;
							 }
							 if (gridY - 1 >= 0)
							 {
								 isValid[gridX][gridY - 1] = 1;
							 }
							 
							 isValid[gridX][gridY] = 2;
					         
					      
					         
					         
					         endGame = gameProgres(isValid, xMod, yMod);
					         
					         move(1,9);
                             printw("  ");
					         printw("%d",endGame);
					         move(1,14);
                             if (endGame == 0)
					         {
						         playerTurn = 2;
					         }
				         }
				         else
				         {
							 endGame = gameProgres(isValid, xMod, yMod);
							 move(1,9);
							 printw("  ");
                             printw("%d",endGame);
						 }
				         
				     }
				     else if (playerTurn == 2)
				     {
					  
					     if (isValid[gridX][gridY] == 0)
					     {
					         if (gridX -1 >= 0 && gridY + 1 <= yMod)
					         {
								 isValid[gridX - 1][gridY + 1] = 1;
							 }
					         if (gridX -1 >= 0 )
					         {
								 isValid[gridX - 1][gridY] = 1;
							 }
					         if (gridX -1 >= 0 && gridY - 1 >= 0)
					         {
								isValid[gridX - 1][gridY - 1] = 1;
							 }
							 if (gridX +1 <= xMod && gridY + 1 <= yMod)
							 {
								 isValid[gridX + 1][gridY + 1] = 1;
							 }
					         if (gridY + 1 <= yMod)
					         {
								 isValid[gridX][gridY + 1] = 1;
							 }
							 if (gridX +1 <= xMod && gridY - 1 >= 0)
							 {
								 isValid[gridX + 1][gridY - 1] = 1;
							 }
							 if (gridX +1 <= xMod)
							 {
								 isValid[gridX + 1][gridY] = 1;
							 }
							 if (gridY - 1 >= 0)
							 {
								 isValid[gridX][gridY - 1] = 1;
							 }
							 
							 					     
					         isValid[gridX][gridY] = 3;
					         
					         endGame = gameProgres(isValid, xMod, yMod);
					         
					         move(1,9);
                             printw("  ");
                             printw("%d",endGame);
                            if (endGame == 0)
					         {
						         playerTurn = 1;
					         }                            
					       
				          }	
				      }    
				      else	
				      {			
						     endGame = gameProgres(isValid, xMod, yMod);
						     move(1,9);
					         printw("  ");
                             printw("%d",endGame);
				      }
			                         
                 
                  }   
              }            
              

             if (playerTurn == 0 || playerTurn == 2)
             {
		     
                 printGameX(xPos, yPos);
                 

                 refresh();
			 }
			 else if (playerTurn == 1)
			 {
				 
                 printGameO(xPos, yPos);
                 

                 move(yPos, xPos);
                 refresh();
             }

             
            
            refresh();
        }

		


		if (selection == 'q')
        {
			return(1);
		} 
		/* endGame results*/
		else 
	    {
		    if (playerTurn == 2 || playerTurn == 0)
		    {
			    clear();
			    move(1,1);
			    attron(COLOR_PAIR(4));
			
			
			
			    printw("YOU ARE THE WINEERR THIS TIME %s!!!!", name2);
			    refresh();
			    getch();
			    attroff(COLOR_PAIR(4));
			
			    *player2Score = *player2Score + 1;
		}
		    else if (playerTurn == 1)
		    {
			    clear();
			    move(1,1);
			    attron(COLOR_PAIR(4));
			    printw("YOU ARE THE WIN BRINGER THIS TIME %s!!!!", name1);
			
			    getch();
			    refresh();
			    attroff(COLOR_PAIR(4));
			    *player1Score = *player1Score + 1;
			    
		    }
		    return(0);		
		}
		
     }
/*  provides visual feedback to the up and down directions of the board size arrows in the options menu */   
void arrowBlink(arrowNum, direction)
    {
		if (arrowNum == 4)
	    {
			if (direction ==1)
		    {        
				attron(COLOR_PAIR(3));

		        /*top arrow 1*/
		        mvaddch(19,77, ' '); 
                mvaddch(19,78, ' ');
                mvaddch(19,79, ' ');
                mvaddch(19,80, ' ');
                mvaddch(19,81, ' ');
         
                mvaddch(18,78, ' ');
                mvaddch(18,79, ' ');
                mvaddch(18,80, ' ');
         
                mvaddch(17,79, ' ');
                attroff(COLOR_PAIR(3));
		  	    refresh();
			    delay_output(100);	
				
			}
			else if (direction == 2)
		    {
	            /*bottom arrow 1*/
	            attron(COLOR_PAIR(3));
                mvaddch(18+7,77, ' '); 
                mvaddch(18+7,78, ' ');
                mvaddch(18+7,79, ' ');
                mvaddch(18+7,80, ' ');
                mvaddch(18+7,81, ' ');
         
                mvaddch(19+7,78, ' ');
                mvaddch(19+7,79, ' ');
                mvaddch(19+7,80, ' ');
         
                mvaddch(20+7,79, ' ');	
                attroff(COLOR_PAIR(3));
		  	    refresh();
			    delay_output(100);				
			}
		}
		else if (arrowNum == 5)
	    {
			if (direction == 1)
		    {
				
	            /* top arrow 2*/
	            attron(COLOR_PAIR(3));
			    mvaddch(19,77+6, ' '); 
			    mvaddch(19,78+6, ' ');
			    mvaddch(19,79+6, ' ');
			    mvaddch(19,80+6, ' ');
			    mvaddch(19,81+6, ' ');
         
		     	mvaddch(18,78+6, ' ');
			    mvaddch(18,79+6, ' ');
			    mvaddch(18,80+6, ' ');
         
			    mvaddch(17,79+6, ' ');
			    attroff(COLOR_PAIR(3));
		  	    refresh();
			    delay_output(100);	
				
			}
			else if (direction == 2)
		    {  
				attron(COLOR_PAIR(3));
                /*bottom arrow 2*/
	 		    mvaddch(18+7,77+6, ' '); 
			    mvaddch(18+7,78+6, ' ');
			    mvaddch(18+7,79+6, ' ');
			    mvaddch(18+7,80+6, ' ');
			    mvaddch(18+7,81+6, ' ');
         
			    mvaddch(19+7,78+6, ' ');
			    mvaddch(19+7,79+6, ' ');
			    mvaddch(19+7,80+6, ' ');
         
      	        mvaddch(20+7,79+6, ' ');
      	        attroff(COLOR_PAIR(3));
      	        			    
		  	    refresh();
			    delay_output(100);					
			}			
		}
		 
	}	
		
     

