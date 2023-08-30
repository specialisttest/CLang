#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	int n = 14;
	
	for(int i=1; i<=1024; i++) {
		//bool r = (i & (i-1)) == 0;
		bool r = (i & -i) == i;
		if (r)
			printf("%d\n", i);
	}
	
	printf("sizeof int: %d\n", sizeof(int));
	
	for(int i = sizeof(int)*8-1; i >=0; i--) {
		printf( "%d", (n >> i) & 1);
		if ( i % 4 == 0) printf(" ");
	}
	
	
	
	
	
	
	return 0;
}
