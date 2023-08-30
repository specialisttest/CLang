#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Book.h"

// Book
//   title
//   price
// printBook
// inputBook (create in heap)
// array Book*
// sort by title, price

int main(int argc, char *argv[]) {
	BookList* list = calloc(1, sizeof(BookList));
	
	pBook pb;
	while ( (pb = inputBook()) != NULL)
		addBook(list, pb);
		
	sortBookList(list, byTitle, ASC);
	iterateBookList(list, printBook);
	
	sortBookList(list, byTitle, DESC);
	iterateBookList(list, printBook);
	
	sortBookList(list, byPrice, ASC);
	iterateBookList(list, printBook);
	
	sortBookList(list, byPrice, DESC);
	iterateBookList(list, printBook);
	
	deleteBookList(list);

	return 0;
}