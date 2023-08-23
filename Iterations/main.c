#include <stdio.h>

int main(int argc, char *argv[]) {
	
	for(int i = 0; i < 10; i++) {
		if (i == 3) continue;
		if (i == 8) break; // return 0;
		
		printf("%d\n", i);
	}
		
	puts("continue main");
	/*
		1  2  3    10
		2  4  6    20
		..
		10 20 30  100
	*/
	for(int i = 1; i <= 10; i++) {
		for(int j = 1; j <= 10; j++) {
			printf("%-4d", i*j);
		}
		printf("\n");
	}
	
	int i=100;
	for(; (i -= 3) >=0;  )
		printf("%d ", i);
		
	puts("");
	
	// infinite iterations
	// for(;;);
	
	//for(;условие;)
	//while(условие)
	
	int x = 2000;
	while( x < 1000 ) {
		printf("%d ", x);
		x *= 2; // x = x * 2;
	}

	puts("");
	
	x = 2000;
	do {
		printf("%d ", x);
		x *= 2; 
	} while( x < 1000 );
	
	puts("");
	
	
}