#include <stdio.h>
#include <stdlib.h>

/*
	1071 462 == 21
	найти НОД (GCD)
	
	k1 >= k2
	k1 % k2 = k3 (если k3 == 0, то ответ k2)
	k2 % k3 = k4 (если k4 == 0, то ответ k3)

*/
int main(int argc, char *argv[]) {
	
	printf("GCD enter a b: ");
	int k1, k2, k3;
	scanf("%d %d", &k1, &k2);
	
	while ( (k3 = k1 % k2) != 0 ) {
		k1 = k2;
		k2 = k3;
	}
	
	printf("GCD %d\n", k2);
	
	return 0;
}