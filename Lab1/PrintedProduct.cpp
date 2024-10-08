#include "PrintedProduct.h"
#include <iostream>



PrintedProduct::PrintedProduct(int costIn, int numberOfPagesIn, std::string_view titleIn, std::string_view nameOfAuthorIn)
    : cost(costIn), numberOfPages(numberOfPagesIn), title(titleIn), nameOfAuthor(nameOfAuthorIn) {}

void PrintedProduct::setNumberOfPages(int numberOfPagesIn) {
    numberOfPages = numberOfPagesIn;
}
void PrintedProduct::setCost(int costIn) {
    cost = costIn;
}
void PrintedProduct::setTitle(std::string_view titleIn) {
    title = titleIn;
}
void PrintedProduct::setNameOfAuthor(std::string_view nameOfAuthorIn) { 
    nameOfAuthor = nameOfAuthorIn;
}
void PrintedProduct::setAvailability(bool availabilityIn) { 
    availability = availabilityIn;
}

int PrintedProduct::getCost() const {
    return cost;
}
int PrintedProduct::getNumberOfPages() const { 
    return numberOfPages;
}
std::string PrintedProduct::getTitle() const {
    return title;
}
std::string PrintedProduct::getNameOfAuthor() const {
    return nameOfAuthor;
}
bool PrintedProduct::getAvailability() const { 
    return availability;
}

void PrintedProduct::print() const
{
    std::cout << title << " by " << nameOfAuthor << std::endl
        << "Number of pages: " << numberOfPages << std::endl
        << "Cost: " << cost << std::endl;
    if (availability)
    {
        std::cout << "Available" << std::endl;
    }
    else
    {
        std::cout << "Not available" << std::endl;
    }
}
bool PrintedProduct::operator ==(const PrintedProduct& book) const
{
    return this->title == book.title;
}



void PrintedProduct::createBook()
{
    std::cout << "Enter title: ";
    getline(std::cin, title);
    std::cout << "Enter author name: ";
    getline(std::cin, nameOfAuthor);
    std::cout << "Enter number of pages: ";
    std::cin >> numberOfPages;
    std::cout << "Enter cost: ";
    std::cin >> cost;
    std::cin.ignore(); 
    availability = true;
}
