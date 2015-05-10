#include <stdio.h>
#include <ncurses.h>

int main(void)
{
    printf("ACS_ULCORNER: %d\n", ACS_ULCORNER);
    printf("ACS_LLCORNER: %d\n", (int)ACS_LLCORNER);
    printf("ACS_URCORNER: %d\n", (int)ACS_URCORNER);
    printf("ACS_LRCORNER: %d\n", (int)ACS_LRCORNER);
    printf("ACS_RTEE:     %d\n", (int)ACS_RTEE);
    printf("ACS_LTEE:     %d\n", (int)ACS_LTEE);
    printf("ACS_BTEE:     %d\n", (int)ACS_BTEE);
    printf("ACS_TTEE:     %d\n", (int)ACS_TTEE);
    printf("ACS_HLINE:    %d\n", (int)ACS_HLINE);
    printf("ACS_VLINE:    %d\n", (int)ACS_VLINE);
    printf("ACS_PLUS:     %d\n", (int)ACS_PLUS);
    
    return 0;
}
