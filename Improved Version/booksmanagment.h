#ifndef BOOKSMANAGMENT_H
# define BOOKSMANAGMENT_H

#define MAX_BOOKS 50
#define inner_string_size 50

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int book_count;


void addBook();
void findBook();
void viewBooks();
void updateQuantite();
void deleteBook();
void idfindBook();
void isbnfindBook();
void isbndeleteBook();
void menu();
int count();


typedef struct {
    int ig;
    int ce;
    int na;
    int cde;
    int nd;
}isbn;

typedef struct {
    // short id;
    char book_name[50];
    char book_author[50];
    int book_quantity;
    float book_price;
    isbn book_isbn;
}books ;

books book[50];



#endif