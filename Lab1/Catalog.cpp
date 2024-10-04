#include "Catalog.h"




void Catalog::addLibrary(std::shared_ptr<Library> lib)
{
    librarys.push_back(lib);
    numOfLibrarys++;
}

int Catalog::getNumOfLibrarys() const { return numOfLibrarys; }

std::shared_ptr<Library> Catalog::findLibraryByName(std::string_view name) const
{
    for (const auto& library : librarys)
    {
        if (library->getName() == name)
        {
            return library;
        }
    }
    return nullptr;
}

void Catalog::deleteLibraryByName(std::string_view name)
{
    auto newEnd = std::ranges::remove_if(librarys, [&](const std::shared_ptr<Library>& library) {
        return library->getName() == name;
        });
    librarys.erase(newEnd.begin(), librarys.end());
    numOfLibrarys = librarys.size();
}

void Catalog::printAllLibrarys() const
{
    for (const auto& library : librarys)
    {
        library->printLibInfo();
    }
}

void Catalog::printFullLibraryInfo(const std::string& name) const
{
    if (auto library = findLibraryByName(name); library)
    {
        library->printLibInfo();
        library->printAllBooks();
    }
    else
    {
        std::cout << "Library with name \"" << name << "\" not found." << std::endl;
    }
}

void Catalog::findBookByName(const std::string& name) const
{
    bool found = false;

    for (const auto& library : librarys)
    {
        auto books = library->findBooksByTitle(name);
        if (!books.empty())
        {
            found = true;
            std::cout << "Books in library \"" << library->getName() << "\":" << std::endl;
            for (const auto& book : books)
            {
                book->print();
            }
        }
    }

    if (!found)
    {
        std::cout << "No books with title \"" << name << "\" were found." << std::endl;
    }
}

void Catalog::deleteBookFromAllLibraries(const std::string& bookTitle) const
{
    for (const auto& library : librarys)
    {
        library->deleteBookByTitle(bookTitle);
    }
}

void Catalog::deleteBookFromLibrary(const std::string& libName, const std::string& bookTitle) const
{
    if (auto library = findLibraryByName(libName); library)
    {
        library->deleteBookByTitle(bookTitle);
    }
}

void Catalog::sortBooksInLibraryByCost(const std::string& libName) const {
    if (auto library = findLibraryByName(libName); library) {
        library->sortBooksByCost();
        std::cout << "Books in library \"" << libName << "\" sorted by cost." << std::endl;
    }
    else {
        std::cout << "Library with name \"" << libName << "\" not found." << std::endl;
    }
}

void Catalog::sortBooksInLibraryByNumberOfPages(const std::string& libName) const {
    if (auto library = findLibraryByName(libName); library) {
        library->sortBooksByNumberOfPages();
        std::cout << "Books in library \"" << libName << "\" sorted by number of pages." << std::endl;
    }
    else {
        std::cout << "Library with name \"" << libName << "\" not found." << std::endl;
    }
}