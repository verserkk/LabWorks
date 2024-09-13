#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <string_view>

class printedProduct
{
private:
    int cost;
    int numberOfPages;
    std::string title;
    std::string nameOfAuthor;
    bool availability = true;

public:
    printedProduct(int costIn, int numberOfPagesIn, std::string_view titleIn, std::string_view nameOfAuthorIn);
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

class Library
{
private:
    std::string Name;
    std::vector<std::shared_ptr<printedProduct>> Books;
    int numberOfBooks = 0;

public:
    void addBook(std::shared_ptr<printedProduct> Book);
    int getNumberOfBooks() const;
    void takeBook(int i);
    void sortBooksByCost();
    void sortBooksByNumberOfPages();
    void deleteBookByTitle(std::string_view title);
    std::vector<std::shared_ptr<printedProduct>> findBooksByTitle(std::string_view title) const;
    void printAllBooks() const;
    std::string getName() const;
    void setName(std::string_view name);
    void printLibInfo() const;
};

class Catalog
{
private:
    int numOfLibrarys = 0;
    std::vector<std::shared_ptr<Library>> Librarys;

public:
    void addLibrary(std::shared_ptr<Library> Lib);
    int getNumOfLibrarys() const;
    std::shared_ptr<Library> findLibraryByName(const std::string& name) const;
    void deleteLibraryByName(const std::string& name);
    void printAllLibrarys() const;
    void printFullLibraryInfo(const std::string& name) const;
    void findBookByName(const std::string& name) const;
    void deleteBookFromAllLibraries(const std::string& bookTitle);
    void deleteBookFromLibrary(const std::string& libName, const std::string& bookTitle);
};

#endif // LIBRARYSYSTEM_H
