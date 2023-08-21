#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>

#define ABC 123
const double PI = 3.1415;
const int dimension = 3; // const dimension = 3; 

int main(int argc, char *argv[]) {
	
	system("chcp 65001 > nul"); // utf-8
	//setlocale(LC_ALL, "Russian"); // setlocale(LC_ALL, "ru");
	
	printf("PI = %.4f\n", PI);
	
	//int x;
	//x = ABC; // x = 123
	int x = ABC;
	
	printf("x = %X\n", x);
	int y;
	y = x * 10;
	printf("y = %d\n", y);
	x = x + 2;
	printf("x = %d\n", x);
	printf("dimension = %d\n", dimension);
	
	double z, q = 2.5;
	printf("z = %f\nq = %f\n", z, q);
	
	puts("Hello world");
	printf("Hello ugly world!\n");
	puts("Привет ужасный мир!");
	
	printf("sizeof int = %d\n", sizeof(int));
	printf("sizeof double = %d\n", sizeof(double));
	printf("sizeof long long int = %d\n", sizeof(long long /*int*/ ));
	printf("sizeof long double = %d\n", sizeof(long double));
	
	char ch = 'R';
	printf("ch = %c\n", ch);
	
	printf("Введите ваше имя: ");
	char name[31]; // max 30 char in string (last '\0')
	scanf("%s", name);
	
	
	printf("Введите ваш возраст: ");
	int age;
	scanf("%d", &age);
	
	//char* name = "Сергей";
	printf("Привет, %s - %d!\n", name, age);
	printf("Address in name variable: %p\n", name);
	
	return 0;
}