#include "LibrarySystem.h"
#include <iostream>

void displayMenu()
{
    std::cout << "Menu:\n"
        << "1. Add Library\n"
        << "2. Add Book to Library\n"
        << "3. Find Book by Title\n"
        << "4. Delete Book by Title from All Libraries\n"
        << "5. Print All Libraries\n"
        << "6. Print Full Library Info\n"
        << "7. Delete Library by Name\n"
        << "8. Find Book in Specific Library\n"
        << "9. Delete Book from Specific Library\n"
        << "0. Exit\n";
    std::cout << "Enter your choice: ";
}
