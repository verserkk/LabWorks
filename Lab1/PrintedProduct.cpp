#include "PrintedProduct.h"
#include <iostream>

using namespace std;

printedProduct::printedProduct(int costIn, int numberOfPagesIn, std::string_view titleIn, std::string_view nameOfAuthorIn)
    : cost(costIn), numberOfPages(numberOfPagesIn), title(titleIn), nameOfAuthor(nameOfAuthorIn) {}

void printedProduct::setNumberOfPages(int numberOfPagesIn) { numberOfPages = numberOfPagesIn; }
void printedProduct::setCost(int costIn) { cost = costIn; }
void printedProduct::setTitle(std::string_view titleIn) { title = titleIn; }
void printedProduct::setNameOfAuthor(std::string_view nameOfAuthorIn) { nameOfAuthor = nameOfAuthorIn; }
void printedProduct::setAvailability(bool availabilityIn) { availability = availabilityIn; }

int printedProduct::getCost() const { return cost; }
int printedProduct::getNumberOfPages() const { return numberOfPages; }
std::string printedProduct::getTitle() const { return title; }
std::string printedProduct::getNameOfAuthor() const { return nameOfAuthor; }
bool printedProduct::getAvailability() const { return availability; }

void printedProduct::print() const
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

void printedProduct::createBook()
{
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, nameOfAuthor);
    cout << "Enter number of pages: ";
    cin >> numberOfPages;
    cout << "Enter cost: ";
    cin >> cost;
    cin.ignore(); // To consume the newline character left in the buffer
    availability = true;
}
