#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
	1. Определить константу PI через макрос
	2. Опрелить макрофункцию для нахождения длины окружности по радиусу
	3. Определить макрофункцию для нахождения круга по радиусу
	4. Перенести созданные макросы в отдельный заголовочный файл, оформив его правильно
	
*/


#include "A.h"
#include "A.h"
#include "B.h"
#include "My.h"



#define THE_END {\
	printf("Press enter...");\
	getchar();\
	fflush(stdin);\
}

#define X2(x) ((x)*(x))


#define ENTRY_POINT

#define RUS

#define ERROR_LEVEL 2

ENTRY_POINT int main(int argc, char *argv[]) {
	
#if ERROR_LEVEL == 0
	puts("Errors");
#elif ERROR_LEVEL == 1
	puts("Errors, Warnings");
#elif ERROR_LEVEL == 2
	puts("Errors, Warnings, Notices");
#else
	#line 23
	#error INVALID_ERROR_LEVEL_0_2
#endif

//#undef RUS
	
//#if defined RUS
#ifdef RUS
	system("chcp 65001 > nul");
#endif
	
	printf("Привет\n");
//#undef PI
	printf("PI = %f\n", PI);
	//double r = 10;
	printf("LEN = %f\nSQR = %f\n", CLEN(5+5), CSQR(5+5));
	

	int y = 5;
	
	int z = X2(2*y+1); // (2*y+1)*(2*y+1)
	// z = X2(++y); // (++y)*(++y) UB
	
#define S(x) #x
	printf(S(z = %d\n), z); // S(z = %d\n) == "z = %d\n"
	
	test(); // from A.h
	super_test(); // B.h
	
	printf("File: %s Line number: %d\n", __FILE__, __LINE__);
	printf("Date: %s\n", __DATE__);
	printf("Time: %s\n", __TIME__);
	printf("Current function: %s\n", __func__); // C11
	int a = 1, b = 2, c = 3;
	int abc = 123;
#define C(a,b,c,sign) ((a) sign (b) sign (c))
	z = C(a,b,c,-); //a+b+c;
//#define Concat(a,b,c) a##b##c
//	z = Concat(a,b,c); // abc
	
	printf("z = %d\n", z);

	
	a*b*c;
	a-b-c;
	
	float f = 1.5;
	double dd = 2.5;
	long double lf = 2.5;
	printf("Round: %f\n",  ROUND(f));  // roundf
	printf("Round: %f\n", ROUND(dd)); // round
	printf("Round: %lf\n", (double)ROUND(lf)); // roundl

	
	THE_END 

	return 0;
}