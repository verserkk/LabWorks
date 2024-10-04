#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <iostream>
#include "Catalog.h"
#include "Library.h"
#include "PrintedProduct.h"
#include <memory>


void addLibrary(Catalog& catalog);
void addBook(const Catalog& catalog);
void findBook(const Catalog& catalog);
void deleteBookFromAllLibraries(const Catalog& catalog);
void printAllLibraries(const Catalog& catalog);
void libraryDetails(const Catalog& catalog);
void deleteLibrary(Catalog& catalog);
void findBooksInLibrary(const Catalog& catalog);
void deleteBookFromLibrary(const Catalog& catalog);
void sortByCost(const Catalog& catalog);
void sortByNumberOfPages(const Catalog& catalog);
void displayMenu();

#endif 
