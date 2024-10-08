#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <ranges>
#include <pqxx/pqxx>
#include "PrintedProduct.h"




class Library
{
private:
    std::string name;
    std::vector<std::shared_ptr<PrintedProduct>> books;
    int numberOfBooks = 0;

public:
    void addBook(std::shared_ptr<PrintedProduct> book);
    int getNumberOfBooks() const;

    void sortBooksByCost();
    std::vector<std::shared_ptr<PrintedProduct>> getBooks() const;
    void sortBooksByNumberOfPages();
    void deleteBookByTitle(std::string_view title);
    std::vector<std::shared_ptr<PrintedProduct>> findBooksByTitle(std::string_view title) const;
    void printAllBooks() const;
    std::string getName() const;
    void setName(std::string_view name);
    void printLibInfo() const;
    void operator +=(std::shared_ptr<PrintedProduct> book);
    void takeBook(int i);
    friend void printLibraryInfo(const Library& library);
 
};

#endif
