#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <iostream>
#include "Catalog.h"
#include "Library.h"
#include "PrintedProduct.h"
#include <memory>


void AddLibrary(Catalog& catalog);
void AddBook(const Catalog& catalog);
void FindBook(const Catalog& catalog);
void DeleteBookFromAllLibraries(const Catalog& catalog);
void PrintAllLibraries(const Catalog& catalog);
void LibraryDetails(const Catalog& catalog);
void DeleteLibrary(Catalog& catalog);
void FindBooksInLibrary(const Catalog& catalog);
void DeleteBookFromLibrary(const Catalog& catalog);
void SortByCost(const Catalog& catalog);
void SortByNumberOfPages(const Catalog& catalog);
void displayMenu();

#endif 
