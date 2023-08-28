#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <math.h>

#include "my.h"

void say_hello() {
	puts("Hello");
	// return;
}

void say_hello_w_name(char* name) {
	printf("Hello, %s\n", name);
}

void say_hello_w_name_age(char* name, int age) {
	printf("Hello, %s - %d\n", name, age);
}

void test1(int a) {
	a++;
	printf("test1 a: %d\n", a); // 11
}
void test2(int* a) {
	(*a)++;
	printf("test2 a: %d\n", *a); // 11
}

// банковское округление
// 1.5 => 2.0
// 2.5 => 2.0
// bank_round
double bank_round(double x) {
	if ( ((x - floor(x)) == 0.5) &&
		 ( (long)floor(fabs(x)) % 2 == 0 )  )
		 return x >=0 ? floor(x) : ceil(x);
	return round(x);
}

// round2(double, int)
// round2(1.534, 2) = 1.53
// round2(1.539, 2) = 1.54

// n! = 1*2*3* ..(n-1)*n
// 0! = 1
// n! = n * (n-1)!
int factorial(int n) {
	if (n == 0) return 1;
	else return n*factorial(n-1);
}

double average2(int a, int b){
	return (a+b) / 2.0;
}

double averagem(int m_size, int m[]){
	int summa = 0;
	for(int i=0; i < m_size; i++)
		summa += m[i];
		
	return (double)summa / m_size;
}

double averagen(int n, ...){
	int summa = 0;
	va_list params;
	va_start(params, n);
	for(int i=0; i < n; i++) {
		int k = va_arg(params, int);
		summa += k;
	}
	va_end(params);
	
	return (double)summa / n;
}

int compare_int(const void* a, const void* b ) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}


double mediana(int n, ...) {
	int arr[n]; // VLA
	va_list params;
	va_start(params, n);
	for(int i=0; i < n; i++)
		arr[i] = va_arg(params, int);
	va_end(params);

	double median;
	qsort(arr, n, sizeof(int), compare_int);
	if (n % 2 == 1)
		median = arr[n / 2];
	else
		median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
		
	return median;
	
}

int main(int argc, char *argv[]) {
	say_hello();
	say_hello();
	say_hello_w_name("Sergey");
	say_hello_w_name_age("Andrey", 45);
	
	double d = average(10, 11);
	printf("%f\n", d);
	printf("%f\n", round(d));
	printf("%f\n", floor(d)); // floor(1.9) == 1.0
	printf("%f\n", ceil(d));  // ceil(1.1) == 2.0
	// модуль fabs
	
	printf("round %.1lf : %.1lf\n", -1.1, round(-1.1));
	printf("round %.1lf : %.1lf\n", -1.9, round(-1.9));
	printf("round %.1lf : %.1lf\n", -1.5, round(-1.5));
	printf("round %.1lf : %.1lf\n", -2.5, round(-2.5));
	
	printf("round %.1lf : %.1lf\n", 0.3, round(0.3));

	printf("bank_round %.1lf : %.1lf\n", 0.3, bank_round(0.3));
	
	printf("bank_round %.1lf : %.1lf\n", 1.1, bank_round(1.1));
	printf("bank_round %.1lf : %.1lf\n", 1.9, bank_round(1.9));
	printf("bank_round %.1lf : %.1lf\n", 1.5, bank_round(1.5));
	printf("bank_round %.1lf : %.1lf\n", 2.5, bank_round(2.5));
	printf("bank_round %.1lf : %.1lf\n", 2.9, bank_round(2.9));

	printf("bank_round %.1lf : %.1lf\n", -1.1, bank_round(-1.1));
	printf("bank_round %.1lf : %.1lf\n", -1.9, bank_round(-1.9));
	printf("bank_round %.1lf : %.1lf\n", -1.5, bank_round(-1.5));
	printf("bank_round %.1lf : %.1lf\n", -2.5, bank_round(-2.5));	
	
	// математическое округление
	printf("round(1.1) = %.1f\n", round(1.1));
	printf("round(1.5) = %.1f\n", round(1.5));
	printf("round(1.9) = %.1f\n", round(1.9));
	printf("round(2.5) = %.1f\n", round(2.5));
	
	
	{
		int a = 10;
		test1(a); // by value (copy)
		printf("main1 a: %d\n", a); // 10
	}
	{
		int a = 10;
		test2(&a); // by reference
		printf("main2 a: %d\n", a); // 11
	}
	
	printf("6! = %d\n", factorial(6));
	printf("average(10, 11) = %.2f\n", average(10,11));
	
	int m[] = {10, 11, 12, 13};
	printf("average(10, 11, 12, 13) = %.2f\n", averagem(4, m));
	printf("averagen(18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12) = %.2f\n", 
		averagen(15, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12));
	printf("mediana(18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12) = %.2f\n", 
		mediana(15, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12));
	
	return 0;
}