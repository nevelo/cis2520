#include <stdio.h>
#include <stdlib.h>

int myFunc(int intone, int intwo, int (*functo) (int input1, int input2))
{
	printf("In myFunc.\n");
	return functo(intone, intwo);
}

int function(int input1, int input2)
{
	printf("In function\n");
	return input1 + input2;
}

int function2(int input1, int input2)
{
	printf("In func2\n");
	return input1 * input2;
}

int main(int argc, char* argv[])
{
	int q;
	int r;
	q = strtol(argv[1], NULL, 10);
	r = strtol(argv[2], NULL, 10);

	printf("Top of main.\n");
	int i= myFunc(q,r, &function);
	int j=myFunc(q,r,&function2);
	printf("i=%d, j=%d\n", i, j);
	return 0;
}