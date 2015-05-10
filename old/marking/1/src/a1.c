

#include "gameFunct.h"


int main()
     {
        /* initialization of ncurses */
        int i = 0;
        int maxX = 0;
        int maxY = 0;
        int AI_ENABLED = 0;
        char selection;
        int selected;
        int menuVar = 1;
        int termCheck;
        int boardXnum = 6;
        int boardYnum = 6;
        int boardCornerX;
        int boardCornerY;
        int gameCount = 1;
        int gamesPlayed = 0;
        int cancelGame = 0;
        int player1Score = 0;
        int player2Score = 0;
        char name1[100];
        char name2[100];
        initscr();
        cbreak ();
        noecho ();
        
        termCheck = is_term_resized(55, 100);
        
        if (termCheck == TRUE)
        {
            printw("I'm sorry but your terminal size does not support this program. To run this program you must change the terminal size to 100x55 by right clicking the bottom of the terminal window and dragging to the appropriate value");
            move(5,5);
            printw("press any key to quit");
            refresh();
            getchar();
        }
        else
        {
            start_color();
            init_color(COLOR_BLACK,204,204,204);
            init_pair(1,COLOR_BLUE, COLOR_RED);
            init_pair(2,COLOR_RED, COLOR_BLUE);
            init_pair(3,COLOR_RED, COLOR_GREEN);
            init_pair(4,COLOR_RED, COLOR_BLACK);
            init_pair(5,COLOR_RED, COLOR_CYAN);
            wbkgd(stdscr,COLOR_PAIR(1));
            getmaxyx(stdscr, maxY, maxX);
            
            getchar();
            borderSetup(maxY, maxX, 2);
            menuSetup(menuVar);
            while (menuVar != 0)
            {
                /* quits game */
                selection = getch();
                if (selection == 'q')
                {
                    menuVar = 0;
                    break;
                } 
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
                else if (selection == UP)
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
                else if (selection == SELECT)
                {
                    selected = TRUE;
                }
            
                if (menuVar == 1 && selected == TRUE)
                {
                    if (AI_ENABLED == 0)
                    {    
                        clear();
                        move(1,1);
                        echo();
                        printw("Please type the name of player one (player X)");
                        refresh();
                        move(2,1);
                        getstr(name1);
                        clear();
                        move(1,1);
                        printw("Please type the name of player two (player O)");
                        move(2,1);
                        refresh();
                        getstr(name2);   
                        clear();
                        move(1,1);
                        printw("up and down to change the number of games you would like to play then press p to start (max 20)"); 
                        move(2,1);
                        printw("   " );
                        noecho(); 
                    }
                    else
                    {
                        clear();
                        move(1,1);
                        echo();
                        printw("Please type the name of the human player (player X)");
                        refresh();
                        move(2,1);
                        getstr(name1);
                        clear();
                        move(1,1);
                        printw("Please type the name of computer player (player O)");
                        move(2,1);
                        refresh();
                        getstr(name2);   
                        clear();
                        move(1,1);
                        printw("up and down to change the number of games you would like to play then press p to start (max 20)"); 
                        move(2,1);
                        printw("   " );
                        noecho();  
                    }
                    selection = 'g';
                    while (selection != SELECT)
                    {
                        borderSetup(maxY, maxX, 2);
                        selection = getch();
                        if (selection == DOWN)
                        {
                            if (gameCount - 1 >= 1)
                            {
                                gameCount = gameCount - 1;
                            }
                        }
                        else if (selection == UP)
                        {
                            if (gameCount + 1 <= 20)
                            {
                                gameCount = gameCount + 1;
                            }
                            
                        }
                        else if (selection == 'q')
                        {
                            break;
                        }
                        
                    
                        move(3,1);
                        printw("   " );
                        move(3,1);
                        printw("%d", gameCount);
                        refresh(); 
                        
                            
                    } 
                    
                    if (selection == 'q')
                    {
                        clear();
                        selected = FALSE;
                    }  
                    else
                    {     
                        noecho();                       
                        while (gamesPlayed <= gameCount)
                        {
                            boardSetup(boardXnum, boardYnum, maxX, maxY, &boardCornerX, &boardCornerY);
                            borderSetup(maxY, maxX, 5);
                            cancelGame = gamePlay(boardCornerX, boardCornerY, boardXnum,boardYnum, &player1Score, &player2Score, AI_ENABLED, name1, name2);
                            clear();
                            if (cancelGame == 1)
                            {
                                break;
                            }
                            else
                            {
                                gamesPlayed++; 
                            }
                        
                    }
                    
                    if (cancelGame == 0)
                    {
                        if (player1Score > player2Score)
                        {
                            clear();
                            attron(COLOR_PAIR(4));
                            while (i < 40)
                            {
                                move(i,1);
                                printw("YOU ARE THE F***ING CHAMP THIS TIME %s!!!", name1);
                                move(i,1);
                                printw("YOU ARE THE F***ING CHAMP THIS TIME %s!!!!", name1);
                                i++;
                            }
                            i = 0;
                            refresh();
			                getch();
			                
			                attroff(COLOR_PAIR(4));
                            clear();
                            refresh();
                            
                        }
                        else if (player2Score > player1Score)
                        {
                            clear();
                            attron(COLOR_PAIR(4));
                            while (i < 40)
                            {
                                move(i,1);
                                printw("YOU ARE THE F***ING CHAMP THIS TIME %s!!!!", name2);
                                move(i,20);
                                printw("YOU ARE THE F***ING CHAMP THIS TIME %s!!!!", name2);
                                i++;
                            }
                            i = 0;			                
			                refresh();
			                getch();
			                
			                attroff(COLOR_PAIR(4));                            
                            clear();
                            refresh();
                        }
                        else if (player1Score == player2Score)
                        {
                            clear();
                            
                            attron(COLOR_PAIR(4));
                            while (i < 20)
			                {   
                                move(i,1);
                                printw("IT LOOKS LIKE YOU ARE BOTH GODLIKE ITS A TIE!!!!");
                                i++;
                            }
			                
			                refresh();
                            getch();
			                attroff(COLOR_PAIR(4));                            
                            clear();
                            refresh();
                        }
                        
                    }
                    gamesPlayed = 0;
                    player1Score = 0;
                    player2Score = 0;
                    borderSetup(maxY, maxX, 2);
                    selected = FALSE;
                    }
                }
                else if (menuVar == 3 && selected == TRUE)
                {
                    
                    clear();
                    borderSetup(maxY, maxX, 3);
                    optionsMenu(&boardXnum, &boardYnum, &AI_ENABLED);
                    clear();
                    borderSetup(maxY, maxX, 2);
                    refresh();
                    selected = FALSE;
                }
                else if (menuVar == 2 && selected == TRUE)
                {
                    clear();
                    borderSetup(maxY, maxX, 3);
                    
                    
                    move (20, 18);
                    printw("The rules are simple,");
                    move (21,18);
                    printw("you control either an X or an O. The purpose of the game is to fill in every box");
                    move (22,18);
                    printw("placing an X or an O will fill out all available spaces around the X or O.");
                    move (23,18);
                    printw("You cannot place on a filled in box");
                    move (24,18);
                    printw("The person who makes the last move wins!");
                    move (25,18);
                    printw("AI can be turned on in the options menu. GOOD LUCK!");
                    refresh();
                    getch();
                    clear();
                    borderSetup(maxY, maxX, 2);
                    selected = FALSE;
                }
            
                menuSetup(menuVar);
              }
        }     

        
        
        
        clear();

        refresh();
        endwin();
        return(0);
         
        
        

     }
     
