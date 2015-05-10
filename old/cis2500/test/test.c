#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int saveHighScores(unsigned char* state);
void viewHighScores(void);

struct HighScore {
    char name[16];
    int value;
} highScore;

int main(void)
{
    unsigned char* state;
    
    state = calloc(120, sizeof(char));
    srand(time(NULL));
    
    *(state+88) = (rand() % 10 ) + 1;
    *(state+89) = (rand() % 10 ) + 1;
    memcpy((state+41), "MATT\0\0\0\0\0\0\0\0\0\0\0\0", 16);
    memcpy((state+57), "NOTMATT\0\0\0\0\0\0\0\0\0", 16);
    
    printf("%s %d, %s %d\n", (state+41), *(state+88), (state+57), *(state+89));
    
    saveHighScores(state);
    viewHighScores();
    
    return 0;
}

int saveHighScores(unsigned char* state)
{
    FILE * scoreTable;
    int oldPlayers = 0;
    int p1pos;
    int p2pos;
    int i;
    struct HighScore scores[50];
    struct HighScore player1;
    struct HighScore player2;
    
    player1.value = *(state+88);
    player2.value = *(state+89);
    memcpy(player1.name, (state+41), 16);
    memcpy(player2.name, (state+57), 16);
    
    printf("Past struct initializations.\n");
    
    // Read in old data.
    scoreTable = fopen("data/scores.dat", "a+");
    if(scoreTable == NULL)
    {
        printf("Failed to open file.\n");
        return -1;
    }
    printf("Opened file.\n");
    // reading scores into memory
    for (i = 0; i < 50; i++)
    {
        printf("Into the for loop, reading scores.\n");
        if (feof(scoreTable) == TRUE)
        {
            printf("Reached end of scores.dat file.\n");
            break;
        }
        fscanf(scoreTable, "%s %d", scores[i].name, &scores[i].value);
        printf("Comparing strings...\n");
        if (strcmp(scores[i].name, player1.name))
        {
            oldPlayers = oldPlayers + 1;
            p1pos = i; // storing the original position of player 1
            scores[i].value = player1.value + scores[i].value;            
        }
        if (strcmp(scores[i].name, player2.name))
        {
            oldPlayers = oldPlayers + 2;
            p2pos = i; // storing the original position of player 2
            scores[i].value = player2.value + scores[i].value;
        }
    }
        
    if (oldPlayers != 1 && oldPlayers != 3) // means player 1 needs a new entry on the table
    {
        i++;
        p1pos = i;
        scores[i].value = player1.value;
        memcpy(scores[i].name, player1.name, 16);
    }
    if (oldPlayers != 2 && oldPlayers != 3) // means player 2 needs a new entry on the table
    {
        i++;
        p2pos = i;
        scores[i].value = player2.value;
        memcpy(scores[i].name, player2.name, 16);
    }
    fclose(scoreTable);
     

    scoreTable = fopen("data/scores.dat", "w+"); 
    if (scoreTable == NULL)
        return 4;
    
    // Printing the updated table to file
    for (i = 0; i < 50; i++)
    {
        if (scores[p1pos].value >= scores[i].value)
        {
            fprintf(scoreTable, "%s %d\n", scores[p1pos].name, scores[p1pos].value);
            scores[p1pos].value = -1; //puts in proper order.
        }

        if (scores[p2pos].value >= scores[i].value)
        {
            fprintf(scoreTable, "%s %d\n", scores[p2pos].name, scores[p2pos].value);
            scores[p2pos].value = -1;
        }
        
        if (scores[i].value < 0)
            break;
        
        fprintf(scoreTable, "%s %d\n", scores[i].name, scores[i].value);
    }
    
    fclose(scoreTable);    
    return 0;
}

void viewHighScores(void)
{
    FILE * scores;
    struct HighScore scoreList[10];
    int i;
    int j;
    
    for (i = 0; i < 10; i++)
    {
        *(scoreList[i].name) = '\0';
        scoreList[i].value = 0;
    }
    
    scores = fopen("data/scores.dat", "a+");
    for (i = 0; i < 10; i++)
    {
        if (feof(scores) == TRUE)
            break;
        fscanf(scores, "%s %d", scoreList[i].name, &scoreList[i].value);
    }

    printf("NUMBER OF WINS\n");
    for (j = 0; j < i; j++)
    {
        if (*(scoreList[j].name) == '\0')
            break;
        printf("%2d. %16s     %2d\n", j+1, scoreList[j].name, scoreList[j].value);
    }
    // TO BE DONE:
    // Center the "TOP TEN PLAYERS" list.
    // PRint the top ten players and their wins.
    // Create a 'delete high scores' feature.
    
    return;
}
