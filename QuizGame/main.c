#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MAX_ATTEMPTS 7

int main(int argc, char *argv[]) {
	system("chcp 65001 > null");
	
	puts("Игра \"Угадай число\"\n");
	srand((unsigned)time(NULL));
	int x = rand() % 100 + 1; // 1..100
	//printf("%d\n", x);
	
	int y, counter = 0;
	do {
		printf("Угадай число (1-100): ");
		scanf("%d", &y);
		if (y == 0) break;
		counter++;
		if (y > x) puts("Много");
		if (y < x) puts("Мало");
	
	} while( (x != y) && (counter < MAX_ATTEMPTS));
	
	if (x == y)
		printf("Вы выиграли. Число попыток: %d\n", counter);
	else
		printf("Вы проиграли.\n");
	
	
	
	
	
	return 0;
}
