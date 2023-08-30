#ifndef _INC_BOOK_H_
#define _INC_BOOK_H_

#include "String.h"

#define MAX_TITLE_LEN 200

typedef struct {
	String 			title;
	unsigned int	price;
} Book;

typedef Book* pBook;

typedef struct {
	pBook*  start;
	int 	size;
} BookList;

enum BookSort { byTitle, byPrice};
enum Order { ASC, DESC};

typedef int (*compareBookFunction)(const pBook* , const pBook* ) ;

pBook inputBook();
void  printBook(const pBook b);
void  deleteBook(pBook b);

void  addBook(BookList* list, const pBook);
void  iterateBookList(const BookList* list, void (*)(const pBook));
void  deleteBookList(BookList* list);

void  sortBookList(BookList* list, enum BookSort sort, enum Order order);

#endif