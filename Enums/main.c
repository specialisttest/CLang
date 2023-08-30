#include <stdio.h>
#include <stdlib.h>

enum Colors { red = 1, green = 10, blue = 100};
			// 1		10			100	
			
			// 0	1		2
int main(int argc, char *argv[]) {
	enum Colors c1 = green;
	int k1 = c1;
	printf("k1 = %d\n", k1);
	printf("c1 = %d\n", c1);
	
	c1 = 200;
	
	printf("c1 = %d\n", c1);
	return 0;
}