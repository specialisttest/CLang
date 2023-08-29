#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef unsigned char* String;
typedef const unsigned char* CString;

bool parseInt(CString s, int* n) {
	if (s == NULL) return false;
	//int len = strlen_s(s, 11);
	int len = strlen(s);
	if (len == 0) return false;
	int p = 1;
	int r = 0;
	for(int i= len - 1; i >= 0; i--) {
		if (isdigit(s[i]))
			r += p*(s[i] - '0');
		else
			if(i == 0) {
				if (s[i] == '-') r = -r;
				else if (s[i] != '+') return false;
			} else return false;
			
		p *= 10;
	}
	*n = r;
	return true;
}


int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");
	{
		
		String s = "abc";
		String names[] = { "Анна", "Алиса", "Арабелла" };
		String* strArray = names; // unsigned char** str 
	}
	{
		String s = "040";
		int n;
		if (parseInt(s, &n))
			printf("Conversion ok: %d\n", n);
		else
			printf("Conversion failed\n");
	}
	
	
	return 0;
}
