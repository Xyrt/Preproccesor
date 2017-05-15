#include <stdio.h>
#include <stdbool.h>

void max1()
{
	printf("%s", __FUNCTION__);
}

void max2()
{
	printf(__FUNCTION__);
}

void max3()
{
	printf(__FUNCTION__);
}

void min1() { printf(__FUNCTION__); }
void min2() { printf(__FUNCTION__); }
void min3() { printf(__FUNCTION__); }

#define VERSION 2

#define EXEC2(foo, version) foo ## version();
#define EXEC1(foo, version) EXEC2(foo, version)
#define EXEC(foo) EXEC1(foo, VERSION)

int main(int argCount, char* argValues[])
{
	EXEC(max);
	EXEC(min);
}


#define SHOW(arg1, arg2) printf("Max number - %i\n", (arg1 > arg2 ? arg1 : arg2));\
	printf(#arg1 "= %i\n", arg1);\
	printf(#arg2 "= %i\n", arg2);

int main()
{
	int firstNumber = 0;
	int secondNumber = 0;

	printf("Enter first number\n");
	scanf("%i", &firstNumber);
	printf("Enter second number\n");
	scanf("%i", &secondNumber);

	SHOW(firstNumber, secondNumber);
}
