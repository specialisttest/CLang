#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>


int main(int argc, char *argv[])
{
	
	// Hello, Name!
	// Hello, Stranger!
	
	system("chcp 65001 > nul");
	
	
	char name[21] = "";
	// scanf("%s",name);
	// scanf_s("%s",name, sizeof(name));
	// gets(name);
	// gets_s(name, sizeof(name))
	printf("strlen: %d\n", strlen(name));
	
	

	// оператор-выражение
	int a = 2;
	int b;
	3 * (b = a + 2);
	//goto abc;
	// блочный (составной оператор)
	{
		int x = 5;
		// double x; // compile error
		printf("x = %d\n", x);
	}

	{

		double x = 2.5;
abc: {
			int x = 10;
			printf("x = %d\n", x);
		}
		printf("x = %f\n", x);
	}

	// b = x * 2; // compile error

	// пустой оператор
	;;;;;;

	//goto abc;

	int n = -10;

	if (n > 0) {
		puts("n > 0");
		puts("n больше 0");
	}
	else 
		if (n > -100)
			puts("n in (-100, 0]");
		else
			puts("n <= 0");

	n = 1;
	/*if (n == 1) puts("один");
	if (n == 2) puts("два");
	if (n == 3) puts("три");*/
	#define j 1
	
	switch (n*2) {
		case -1:
		case 1 : 
			puts("один");
			break;
		case j*2 : 
			puts("два");
			break;
		case 3 : 
			puts("три");
			break;
		default:
			puts("много");
	}
	
	// 0..9
	// На ветке 5 ворон
	
	
	
	
	
	
	
	
	
	
	

	return 0;
}