#include "LibrarySystem.h"
#include <iostream>
#include <algorithm>
#include <ranges>

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
    availability = true;
}

void Library::addBook(std::shared_ptr<printedProduct> Book)
{
    Books.push_back(Book);
    numberOfBooks++;
}

int Library::getNumberOfBooks() const { return numberOfBooks; }

void Library::takeBook(int i)
{
    if (Books[i]->getAvailability())
    {
        Books[i]->setAvailability(false);
        cout << "You've just taken a book! Congrats!" << endl;
    }
    else
    {
        cout << "Sorry!! But the book is already taken :(" << endl;
    }
}

void Library::sortBooksByCost()
{
    ranges::sort(Books, [](const shared_ptr<printedProduct>& a, const shared_ptr<printedProduct>& b) {
        return a->getCost() > b->getCost();
        });
}

void Library::sortBooksByNumberOfPages()
{
    ranges::sort(Books, [](const shared_ptr<printedProduct>& a, const shared_ptr<printedProduct>& b) {
        return a->getNumberOfPages() > b->getNumberOfPages();
        });
}

void Library::deleteBookByTitle(std::string_view title)
{
    for (auto it = Books.begin(); it != Books.end(); ++it)
    {
        if ((*it)->getTitle() == title)
        {
            Books.erase(it);
            numberOfBooks--;
            break;
        }
    }
}

std::vector<std::shared_ptr<printedProduct>> Library::findBooksByTitle(std::string_view title) const
{
    std::vector<std::shared_ptr<printedProduct>> result;
    for (const auto& book : Books)
    {
        if (book->getTitle() == title)
        {
            result.push_back(book);
        }
    }
    return result;
}

void Library::printAllBooks() const
{
    for (int i = 0; i < numberOfBooks; i++)
    {
        cout << i << ":" << endl;
        Books[i]->print();
    }
}

std::string Library::getName() const { return Name; }

void Library::setName(std::string_view name) { Name = name; }

void Library::printLibInfo() const
{
    cout << Name << endl
        << "Contains " << numberOfBooks << " books" << endl;
}

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

void Catalog::deleteLibraryByName(std::string_view name)
{
    for (auto it = Librarys.begin(); it != Librarys.end(); ++it)
    {
        if ((*it)->getName() == name)
        {
            Librarys.erase(it);
            --numOfLibrarys; 
            break;
        }
    }
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
void displayMenu()
{
    std::cout << "Menu:\n"
        << "1. Add Library\n"
        << "2. Add Book to Library\n"
        << "3. Find Book by Title\n"
        << "4. Delete Book by Title from All Libraries\n"
        << "5. Print All Libraries\n"
        << "6. Print Full Library Info\n"
        << "7. Delete Library by Name\n"
        << "8. Find Book in Specific Library\n"
        << "9. Delete Book from Specific Library\n"
        << "0. Exit\n";
    std::cout << "Enter your choice: ";
}
