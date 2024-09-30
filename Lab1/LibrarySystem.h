#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <iostream>
#include "Catalog.h"
#include "Library.h"
#include "PrintedProduct.h"
#include <memory>


void handleAddLibrary(Catalog& catalog);
void handleAddBook(const Catalog& catalog);
void handleFindBook(const Catalog& catalog);
void handleDeleteBookFromAllLibraries(const Catalog& catalog);
void handlePrintAllLibraries(const Catalog& catalog);
void handleLibraryDetails(const Catalog& catalog);
void handleDeleteLibrary(Catalog& catalog);
void handleFindBooksInLibrary(const Catalog& catalog);
void handleDeleteBookFromLibrary(const Catalog& catalog);
void handleSortByCost(const Catalog& catalog);
void handleSortByNumberOfPages(const Catalog& catalog);
void displayMenu();

#endif 
