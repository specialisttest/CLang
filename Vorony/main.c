#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
// sqrt()

int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");
	
	printf("Сколько ворон на ветке: ");
	int n;
	scanf("%d", &n);
	char* v;
	int n2 = n % 100;
	
	if ( (n2 >= 11) && (n2 <= 14) )
		v = "ворон";
	else
		switch(n%10) {
			case 1 : v = "ворона"; break;
			case 2 :
			case 3 :
			case 4 : v = "вороны"; break;
			default:  v = "ворон"; break;
		}
	
	printf("На ветке %d %s\n", n, v);
	
	
	return 0;
}