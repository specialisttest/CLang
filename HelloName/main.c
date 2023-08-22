#define __STDC_LIB_EXT1__ 1
#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char name[31];
	printf("Enter your name: ");
	//scanf_s("%s", name, sizeof(name));
	//gets_s(name, sizeof(name));
	gets(name);
	
	//if (strlen(name)!=0)
	if (strlen(name))
		printf("Hello, %s!\n", name);
	else
		printf("Hello, Stranger!");

	return 0;
}