#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

	// "Sergey, Andrey, Anna, Elena, Alex, Julia"
	// разметить имена в алфавитном порядке
	// 1. Сделать массив строк с именами
	// 2. Сортировать массив (qsort ф-я сравнения strcmp)
	// 3. Объединить массив строк в одну строку strcat
	
#define MAX_LN 60

/*int compareStrings(const void* p1, const void* p2) {
	const char* s1 = (const char* )p1;
	const char* s2 = (const char* )p2;
	return strcmp(s1, s2);
}*/

int main(int argc, char *argv[]) {
	char s[MAX_LN] = "Sergey, Andrey, Anna, Elena, Alex, Julia";
	puts(s);
	char words[MAX_LN / 2 + 1][MAX_LN];
	int wordCount = 0;
	
	int len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(isalpha(s[i])) {
			int last = len;
			for(int j = i + 1; j < len; j++)
				if (!isalpha(s[j])) {
					last = j;
					break;
				}
			strncpy(words[wordCount], &s[i], last - i);
			words[wordCount][last-i] = '\0';
			wordCount++;
			i = last;
		}
	}
	
	qsort(words, wordCount, MAX_LN, strcmp);
	
	//for(int i = 0; i < wordCount; i++)
	//	printf("'%s'\n",words[i]);
		
	char result[MAX_LN] = {0};
	for(int i = 0; i < wordCount; i++){
		strcat(result, words[i]);
		if (i != wordCount-1) strcat(result, ", ");
	}
	
	puts(result);
		
	
	
	
	
	
}