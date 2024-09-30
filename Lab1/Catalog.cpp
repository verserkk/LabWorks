#include "Catalog.h"


using namespace std;

void Catalog::addLibrary(std::shared_ptr<Library> Lib)
{
    Librarys.push_back(Lib);
    numOfLibrarys++;
}

int Catalog::getNumOfLibrarys() const { return numOfLibrarys; }

std::shared_ptr<Library> Catalog::findLibraryByName(std::string_view name) const
{
    for (const auto& library : Librarys)
    {
        if (library->getName() == name)
        {
            return library;
        }
    }
    return nullptr;
}

void Catalog::deleteLibraryByName(string_view name)
{
    auto newEnd = std::ranges::remove_if(Librarys, [&](const std::shared_ptr<Library>& library) {
        return library->getName() == name;
        });
    Librarys.erase(newEnd.begin(), Librarys.end());
    numOfLibrarys = Librarys.size();
}

void Catalog::printAllLibrarys() const
{
    for (const auto& library : Librarys)
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
        cout << "Library with name \"" << name << "\" not found." << endl;
    }
}

void Catalog::findBookByName(const std::string& name) const
{
    bool found = false;

    for (const auto& library : Librarys)
    {
        auto books = library->findBooksByTitle(name);
        if (!books.empty())
        {
            found = true;
            cout << "Books in library \"" << library->getName() << "\":" << endl;
            for (const auto& book : books)
            {
                book->print();
            }
        }
    }

    if (!found)
    {
        cout << "No books with title \"" << name << "\" were found." << endl;
    }
}

void Catalog::deleteBookFromAllLibraries(const std::string& bookTitle) const
{
    for (const auto& library : Librarys)
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
        cout << "Books in library \"" << libName << "\" sorted by cost." << endl;
    }
    else {
        cout << "Library with name \"" << libName << "\" not found." << endl;
    }
}

void Catalog::sortBooksInLibraryByNumberOfPages(const std::string& libName) const {
    if (auto library = findLibraryByName(libName); library) {
        library->sortBooksByNumberOfPages();
        cout << "Books in library \"" << libName << "\" sorted by number of pages." << endl;
    }
    else {
        cout << "Library with name \"" << libName << "\" not found." << endl;
    }
}