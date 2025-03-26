/*
    Problem 1: Library System
    Create a program that organizes a library. The library has books stored on shelves A to Z. 
    Each shelf stores books whose titles start with the corresponding letter. Each book should have:

    A unique ID.
    Title.
    Author.
    Year of publication.
    Number of copies available.
    
    Tasks:
    Write a function to add a new book to the correct shelf and ensure the books on each shelf are sorted by title.
    Write a function to borrow a book. Reduce the number of 
        available copies. If no copies are available, display a message saying the book is out of stock.
    Write a function to remove books published before a certain year.
    Write a function to display all books on a specific shelf.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int shelfID;



