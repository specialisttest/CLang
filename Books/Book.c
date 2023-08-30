#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "String.h"
#include "Book.h"

pBook inputBook() {
	unsigned char title[MAX_TITLE_LEN];
	unsigned int price;
	
	printf("Enter book title: ");
	gets(title);
	fflush(stdin);
	if (strlen(title) == 0) return NULL;
	
	printf("Enter book price: ");
	scanf("%d", &price);
	fflush(stdin);
	
	pBook pb = malloc(sizeof(Book));
	pb->title = malloc((strlen(title)+1)*sizeof(unsigned char));
	strcpy(pb->title, title);
	pb->price = price;
	
	return pb;
	
}
void  printBook(const pBook b) {
	if (b != NULL)
		printf("%-20s : %5d\n", b->title, b->price);
}
void  deleteBook(pBook b) {
	free(b->title);
	free(b);
}

void  addBook(BookList* list, const pBook pb) {
	list->start = realloc(list->start, sizeof(pBook)*(list->size+1));
	if (list->start == NULL) {
		perror("Out of memory");
		exit(1);
	}
	list->start[list->size++] = pb;
}
void  iterateBookList(const BookList* list, void (* f)(const pBook) ) {
	if (list == NULL || list->size == 0 || list->start == NULL) return;
	for(int i=0; i < list->size; i++)
		f(list->start[i]);
}
void  deleteBookList(BookList* list) {
	iterateBookList(list, deleteBook);
	free(list);
}

int compareBookByTitle(const pBook* p1, const pBook* p2) {
	return strcmp( (*p1)->title, (*p2)->title);
}
int compareBookByTitleDesc(const pBook* p1, const pBook* p2) {
	return compareBookByTitle(p2, p1);
}
int compareBookByPrice(const pBook* p1, const pBook* p2) {
	return (*p1)->price - (*p2)->price;
}
int compareBookByPriceDesc(const pBook* p1, const pBook* p2) {
	return compareBookByPrice(p2, p1);
}

compareBookFunction comparesFunction[4] = {
	compareBookByTitle,
	compareBookByTitleDesc,
	compareBookByPrice,
	compareBookByPriceDesc
};

void  sortBookList(BookList* list, enum BookSort sort, enum Order order){
	qsort(list->start, list->size, sizeof(pBook), 
		(int (*)(const void*,const void*))comparesFunction[sort*2+order] );
}
