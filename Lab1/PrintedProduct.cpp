#include "PrintedProduct.h"
#include <iostream>

using namespace std;

PrintedProduct::PrintedProduct(int costIn, int numberOfPagesIn, std::string_view titleIn, std::string_view nameOfAuthorIn)
    : cost(costIn), numberOfPages(numberOfPagesIn), title(titleIn), nameOfAuthor(nameOfAuthorIn) {}

void PrintedProduct::setNumberOfPages(int numberOfPagesIn) { numberOfPages = numberOfPagesIn; }
void PrintedProduct::setCost(int costIn) { cost = costIn; }
void PrintedProduct::setTitle(std::string_view titleIn) { title = titleIn; }
void PrintedProduct::setNameOfAuthor(std::string_view nameOfAuthorIn) { nameOfAuthor = nameOfAuthorIn; }
void PrintedProduct::setAvailability(bool availabilityIn) { availability = availabilityIn; }

int PrintedProduct::getCost() const { return cost; }
int PrintedProduct::getNumberOfPages() const { return numberOfPages; }
std::string PrintedProduct::getTitle() const { return title; }
std::string PrintedProduct::getNameOfAuthor() const { return nameOfAuthor; }
bool PrintedProduct::getAvailability() const { return availability; }

void PrintedProduct::print() const
{
    cout << title << " by " << nameOfAuthor << endl
        << "Number of pages: " << numberOfPages << endl
        << "Cost: " << cost << endl;
    if (availability)
    {
        cout << "Available" << endl;
    }
    else
    {
        cout << "Not available" << endl;
    }
}

void PrintedProduct::createBook()
{
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, nameOfAuthor);
    cout << "Enter number of pages: ";
    cin >> numberOfPages;
    cout << "Enter cost: ";
    cin >> cost;
    cin.ignore(); 
    availability = true;
}
