#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const char* fname_1 = "test.txt";

int count_words(const char* s) {
	int wordCount = 0;
	const int len = strlen(s);
	for(int i=0; i < len; i++){
		if (isblank((unsigned char)s[i])) {
			wordCount++;
		}
	}
	return wordCount+1;
	
}

int main(int argc, char *argv[]) {
	FILE* f = fopen(fname_1, "r");
	if (!f) {
		printf("File %s error\n", fname_1);
		exit(1);
	}
	#define MAX_STR_SIZE 200
	char str[MAX_STR_SIZE];
	
	int lines = 0;
	int chars = 0;
	int words = 0;
	
	while (fgets(str, MAX_STR_SIZE, f) != NULL){
		int p = strlen(str)-1;
		while(p >= 0 && (str[p]=='\n' || str[p]=='\r'))
			str[p--] = '\0';
		
		puts(str);
		lines++;
		chars += strlen(str);
		words += count_words(str);
	}
	
	fclose(f);
	
	puts("****************************");
	printf("Lines : %d Chars : %d Words : %d\n", lines, chars, words);
	
	
	
	
	
	
	
	return 0;
}
