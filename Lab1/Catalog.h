#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <memory>
#include <string>
#include <ranges>
#include <algorithm>
#include <iostream>
#include "Library.h"

class Catalog
{
private:
    int numOfLibrarys = 0;
    std::vector<std::shared_ptr<Library>> Librarys;

public:
    void addLibrary(std::shared_ptr<Library> Lib);
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
};

#endif 
