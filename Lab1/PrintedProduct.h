#ifndef PRINTEDPRODUCT_H
#define PRINTEDPRODUCT_H

#include <iostream>
#include <string>
#include <string_view>

class PrintedProduct
{
private:
    int cost;
    int numberOfPages;
    std::string title;
    std::string nameOfAuthor;
    bool availability = true;

public:
    
    PrintedProduct(int costIn, int numberOfPagesIn, std::string_view titleIn, std::string_view nameOfAuthorIn);
    void setNumberOfPages(int numberOfPagesIn);
    void setCost(int costIn);
    void setTitle(std::string_view titleIn);
    void setNameOfAuthor(std::string_view nameOfAuthorIn);
    void setAvailability(bool availabilityIn);

    int getCost() const;
    int getNumberOfPages() const;
    std::string getTitle() const;
    std::string getNameOfAuthor() const;
    bool getAvailability() const;

    void print() const;
    void createBook();
};

#endif 
