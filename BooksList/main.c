#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

#define MAX_TITLE_LEN 100
typedef struct {
	char* title;
	double price;
} Book;
typedef Book* pBook;

typedef Book NodeValue;
struct Node {
	NodeValue value;
	struct Node* next;
};
typedef struct Node* pNode;

bool inputBook(pBook b) {
	char title[MAX_TITLE_LEN];
	double price;
	printf("Enter book title: ");
	gets(title);
	if (strlen(title) == 0) return false;
	
	printf("Enter book price: ");
	scanf("%lf", &price);
	getchar();
	b->title = malloc( (strlen(title)+1)*sizeof(char) );
	strcpy_s(b->title, (strlen(title)+1)*sizeof(char), title);
	
	b->price = price;
	return true;
}

void outputBook(const pBook b) {
	printf("%-20s : %.2lf\n", b->title, b->price);
}

void inputBookList(pNode* firstNode) {
	*firstNode = NULL;
	pNode lastNode = NULL;
	while(true) {
		pNode nextNode = malloc(sizeof(struct Node));
		nextNode->next = NULL;
		
		if ( inputBook( &(nextNode->value) ))
		{
			if (lastNode != NULL)
			{
				lastNode->next = nextNode;
				lastNode = nextNode;
			}
			if(*firstNode == NULL)
				lastNode = *firstNode = nextNode;
		}
		else
		{	
			free(nextNode);
			break;
		}
	}
}

void outputBookList(pNode firstNode) {
	pNode nextNode = firstNode;
	while(nextNode != NULL) {
		outputBook( &(nextNode->value));
		nextNode = nextNode->next;
	}
}
void deleteBook(pBook b) {
	free(b->title);
}

void deleteBookList(pNode* firstNode) {
	pNode nextNode = *firstNode;
	while(nextNode != NULL) {
		deleteBook(&nextNode->value);
		pNode nn = nextNode->next;
		free(nextNode);
		nextNode = nn;
	}
	firstNode = NULL;
}


int main(int argc, char *argv[]) {

	
	pNode listBook;
	inputBookList(&listBook);
	if(listBook != NULL) {
		outputBookList(listBook);
		deleteBookList(&listBook);
	}
	

}
