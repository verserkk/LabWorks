#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <memory>
#include <string>
#include <ranges>
#include <algorithm>
#include <iostream>
#include "Library.h"
#include <pqxx/pqxx>

class Catalog
{
private:
    int numOfLibrarys = 0;
    std::vector<std::shared_ptr<Library>> librarys;
    void saveToDatabase(const std::string& connectionString);
    void loadFromDatabase(const std::string& connectionString);

public:
    explicit Catalog(const std::string& connectionString);
    ~Catalog();
    void addLibrary(std::shared_ptr<Library> lib);
    int getNumOfLibrarys() const;
    std::shared_ptr<Library> findLibraryByName(std::string_view name) const;
    void deleteLibraryByName(std::string_view name);
    void printAllLibrarys() const;
    void printFullLibraryInfo(const std::string& name) const;
    void findBookByName(const std::string& name) const;
    void deleteBookFromAllLibraries(const std::string& bookTitle) const;
    void deleteBookFromLibrary(const std::string& libName, const std::string& bookTitle) const;
    void sortBooksInLibraryByCost(const std::string& name) const;
    void sortBooksInLibraryByNumberOfPages(const std::string& name) const;
    void operator +=(std::shared_ptr<Library> lib);
   
};

#endif 
