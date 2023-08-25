#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");
	
	char s[20] = "Hello"; // string up to 19 len
	wchar_t ch;
	wchar_t ws[20] = L"Привет";
	
	puts(s);
	printf("strlen(s): %d sizeof(s): %d\n", strlen(s), sizeof(s));
	printf("wcslen(ws): %d sizeof(ws): %d\n", wcslen(ws), sizeof(ws));
	
	char name[21] = "Sergey"; // name max len 20 symbols
	printf("Введите ваше имя: ");
	//scanf_s("%20s", name, sizeof(name));
	scanf("%20s", name);
	// Hello, name!
	char hello[sizeof(name)+8] = "Hello, ";
	strcat(hello, name);
	strcat(hello, "!");
	puts(hello);
	
	char source[] = "Sergey,Andrey";
	char names[2][21];
	
	int separation_position = -1;
	int strl = strlen(source);
	for(int i = 0; i < strl; i++)
		if(isspace(source[i]) || ispunct(source[i])) {
			separation_position = i;
			break;
		}
		
	if (separation_position >=0) {
		strncpy(names[0], source, separation_position);
		strcpy(names[1], &source[separation_position+1]);
		puts(names[0]);
		puts(names[1]);
	}
		
	
	return 0;
}