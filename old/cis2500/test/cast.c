#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.141592653589793238

    
int main(int argc, char ** argv)
{
    char * endptr;
    
    if (argc != 3) {
        printf("N-eeds a distance and an angle.");
        exit(1);
    }
    
    int distance = strtol(argv[1], &endptr, 10);
    int angle = strtol(argv[2], &endptr, 10);
    
    double angleD = (double)angle * PI / 180;
    double distanceD = (double)distance;
    
    double riseD = distanceD * sin(angleD);
    double runD = distanceD * cos(angleD);
    
    int rise = round(riseD);
    int run = round(runD);
    printf("dist: %d, ang: %d\n", distance, angle);
    printf("disd: %lf, angd: %lf\n", distanceD, angleD);
    printf("risd: %lf, rund: %lf\n", riseD, runD);
    printf("rise: %d, run: %d\n", rise, run);
    
    return 0;
}
 
   
   
