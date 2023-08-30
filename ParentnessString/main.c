#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
	char* chars;
	int size;
	int maxSize;
};
typedef struct Stack* pStack;

void init_st(pStack st, int max_size) {
	st->chars = malloc(max_size* sizeof(char));
	st->size = 0;
	st->maxSize = max_size;
}

void free_st(pStack st) {
	free(st->chars);
	st->chars = NULL;
	st->maxSize = st->size = 0;
}

void error_st(const char* s) {
	puts(s);
}

void push_st(pStack st, char c) {
	if (st->size >= st->maxSize)
		error_st("Stack overflow");
	else
		st->chars[st->size++] = c;
}


char pop_st(pStack st) {
	if (st->size <=0) {
		error_st("Stack empty");
		return '\0';
	}
	else
		return st->chars[--st->size];
}

void show_st(pStack st) {
	puts("******************");
	for(int i=st->size-1; i>=0; i--)
		printf("%c\n", st->chars[i]);
	
	puts("******************");
}

bool testString(const char* s)
{
	pStack st = malloc(sizeof(struct Stack));
	int len = strlen(s);
	init_st(st, len);
	bool isOk = true;
	for (int i = 0; i < len; i++)
	{
		char c = s[i];
		if (c == '(' || c == '[')
			push_st(st, c);
		if (c == ')' || c == ']')
		{
			if (st->size == 0)
			{
				isOk = false; break;
			}
			char c2 = pop_st(st);
			if (!(((c2 == '(') && (c == ')')) ||
				((c2 == '[') && (c == ']'))))
			{
				isOk = false; break;
			}
		}
	}

	int lastSize = st->size;
	free_st(st);
	free(st);

	return isOk && (lastSize == 0);
}

int main(int argc, char *argv[]) {
	// bool testString(const char*)
	// abc ( ( 1234 ) * [ 2 +  3 ] ) [ ] g
	printf("%d\n", 
testString("abc (  ( 1234 ) * [ 2 + 3]   ) [ ] g"));

	/*struct Stack st;
	init_st(&st, 100);
	push_st(&st, 'a');
	push_st(&st, 'b');
	push_st(&st, 'c');
	show_st(&st);
	printf("%c\n", pop_st(&st));
	show_st(&st);
	printf("%c\n", pop_st(&st));
	show_st(&st);
	printf("%c\n", pop_st(&st));
	show_st(&st);
	printf("%c\n", pop_st(&st));
	show_st(&st);*/
	
	
	
	return 0;
}
