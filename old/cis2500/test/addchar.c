#include <stdio.h>

int main(void)
{
    printf("a: %d %d\n", 'a', 'A');
    printf("fd: %x\n", ('F'-'@')+('D'-'@')*32);
    printf("bk: %d\n", ('B'+'K'));
    printf("lt: %d\n", ('L'+'T'));
    printf("rt: %d\n", ('R'+'T'));
    printf("pu: %d\n", ('P'+'U'));
    printf("pd: %d\n", ('P'+'D'));
    printf("setxy: %d\n", (int)('S'+'E'+'T'+'X'+'Y'));
    printf("home: %d\n", (int)('H'+'O'+'M'+'E'));
    printf("st: %d\n", (int)('S'+'T'));
    printf("ht: %d\n", (int)('H'+'T'));
    printf("setpc: %d\n", (int)('S'+'E'+'T'+'P'+'C'));
    printf("clean: %d\n", (int)('C'+'L'+'E'+'A'+'N'));
    return 0;
}
    
