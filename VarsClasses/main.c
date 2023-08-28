#include <stdio.h>
#include <stdlib.h>

#include "module2.h"


int funcCount() {
	static int counter = 0;
	counter++;
	return counter;
}


int power(register int base, register int e) {
	register int result = 1;
	while (e-- > 0) result *= base;
	return result;
}

// restrict since C11
void update(int* restrict pa, int* __restrict pb, int val) {
	*pa += val;
	*pb += val;
}
#define REAL_PI 3.1415

int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");

	printf("REAL PI = %f\n", REAL_PI);
	
	#define REAL_PI 5.0
	printf("REAL PI = %f\n", REAL_PI);
	
	const double PI = 3.1415; // readonly variable
	// PI = 4; // compile error
	printf("PI = %f\n", PI);
	double* ppi = &PI;
	(*ppi) = 4;
	printf("PI = %f\n", PI);
	
	{
		auto int x = 0; // int x = 0;
		printf("x = %d\n", x);
	}
	{
		register int x = 5;
		printf("register x = %d\n", x);
	}
	
	printf("3 в степени 4 = %d\n", power(3, 4));
	
	printf("Первый вызов funcCount() : %d\n", funcCount());
	printf("Второй вызов funcCount() : %d\n", funcCount());
	printf("Третий вызов funcCount() : %d\n", funcCount());
	
	
	extern int z;
	printf("z from module  = %d\n", z);
	printZ();
	
	volatile int y = 5;
	
	int a = 10;
	int b = 20;
	update(&a, &b, 5);
	printf("a = %d\nb = %d\n", a, b);
	
	_Atomic long counter = 0; // since C11 
	
	return 0;
}