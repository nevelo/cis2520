#include <stdio.h>

int main(void)
{
    int array[2][2][3]={0,1,2,3,4,5,6,7,8,9,10,11};
    int i=0;
    int j=0;
    int k=0;
    
    for (k=0; k<3; k++)
    {
        for (j=0; j<2; j++)
        {
            for(i=0; i<2; i++)
            {
                printf(" %d %d %d: %2d |", i, j, k, array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    
    return 0;
}
