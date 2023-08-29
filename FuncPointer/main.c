#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

int compareNum(const int* p1, const int* p2) {
	return *p1 - *p2;
}


void printArr(const int size, int nums[]) {
	for(int i=0; i < size; i++) {
		printf("%d", nums[i]);
		printf( i != size -1 ? ", " : "\n" );
	}
		
}

typedef double (* MathFunction)(double);

#define STEPS 1000000
//double integral( double (* func)(double), double a, double b) {
double integral(MathFunction func, double a, double b) {
	double w = (b - a) / STEPS;
	double summa = 0.0;
	for(int i=0; i < STEPS; i++) {
		double x = a + w * i + w / 2;
		double h = func(x);// (*func)(x)
		summa += w * h;
	}
	
	return summa;
}

double my_func(double x) {
	return log(sin(x));
}

double x2(double x) {
	return x*x;
}



bool select_func(MathFunction* pf) {
	puts("Select function for integral:");
	puts("sin");
	puts("cos");
	puts("x^2");
	char select[100];
	gets(select);
	if (strcmp(select, "sin") == 0) {
		*pf = sin;
		return true;
	}
	if (strcmp(select, "cos") == 0) {
		*pf = cos;
		return true;
	}
	if (strcmp(select, "x^2") == 0) {
		*pf = x2;
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	#define A_SIZE 5
	int nums[A_SIZE] = {100, 98, 77, 34, 99};
	printArr(A_SIZE, nums);
	
	int (*compareFunc)(const void* p1, const void* p2);
	compareFunc = (int (*)(const void* p1, const void* p2))compareNum;
	
	qsort(nums, A_SIZE, sizeof(int), compareFunc) ;
	
	double r1 = integral(sin, 0.0, M_PI_2);
	printf("integral(sin) (0, PI/2) = %f\n", r1);
	
	double r2 = integral(my_func, 0.0, M_PI_2);
	printf("integral(my_func) (0, PI/2) = %f\n", r2);
	
	MathFunction f;
	if (select_func(&f)) {
		double r = integral(f, 0.0, M_PI_2);
		printf("integral (0, PI/2) = %f\n", r);
	}
	

}