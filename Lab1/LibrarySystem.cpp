
#include "LibrarySystem.h"

using namespace std;

void AddLibrary(Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name: ";
    string name;
    getline(cin, name);

    auto library = make_shared<Library>();
    library->setName(name);
    catalog.addLibrary(library);
    cout << "Library \"" << name << "\" added." << endl;
}

void AddBook(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name: ";
    string libName;
    getline(cin, libName);

    if (auto library = catalog.findLibraryByName(libName); library) {
        cout << "Enter book details:" << endl;
        auto book = make_shared<PrintedProduct>(0, 0, "", "");
        book->createBook();
        library->addBook(book);
        cout << "Book added to library \"" << libName << "\"." << endl;
    }
    else {
        cout << "Library not found." << endl;
    }
}

void FindBook(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter book title to find: ";
    string bookTitle;
    getline(cin, bookTitle);
    catalog.findBookByName(bookTitle);
}

void DeleteBookFromAllLibraries(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter book title to delete: ";
    string bookTitle;
    getline(cin, bookTitle);
    catalog.deleteBookFromAllLibraries(bookTitle);
    cout << "Book(s) with title \"" << bookTitle << "\" have been deleted from all libraries." << endl;
}

void PrintAllLibraries(const Catalog& catalog) {
    catalog.printAllLibrarys();
}

void LibraryDetails(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name to view details: ";
    string libName;
    getline(cin, libName);
    catalog.printFullLibraryInfo(libName);
}

void DeleteLibrary(Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name to delete: ";
    string libName;
    getline(cin, libName);
    catalog.deleteLibraryByName(libName);
    cout << "Library \"" << libName << "\" has been deleted." << endl;
}

void FindBooksInLibrary(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name: ";
    string libName;
    getline(cin, libName);

    if (auto library = catalog.findLibraryByName(libName); library) {
        cout << "Enter book title to find: ";
        string bookTitle;
        getline(cin, bookTitle);
        auto books = library->findBooksByTitle(bookTitle);
        if (!books.empty()) {
            cout << "Books in library \"" << libName << "\":" << endl;
            for (const auto& book : books) {
                book->print();
            }
        }
        else {
            cout << "No books with title \"" << bookTitle << "\" found in library \"" << libName << "\"." << endl;
        }
    }
    else {
        cout << "Library not found." << endl;
    }
}

void DeleteBookFromLibrary(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name: ";
    string libName;
    getline(cin, libName);

    if (auto library = catalog.findLibraryByName(libName); library) {
        cout << "Enter book title to delete: ";
        string bookTitle;
        getline(cin, bookTitle);
        library->deleteBookByTitle(bookTitle);
        cout << "Book(s) with title \"" << bookTitle << "\" have been deleted from library \"" << libName << "\"." << endl;
    }
    else {
        cout << "Library not found." << endl;
    }
}

void SortByCost(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name to sort books by cost: ";
    string libName;
    getline(cin, libName);
    catalog.sortBooksInLibraryByCost(libName);
}

void SortByNumberOfPages(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name to sort books by number of pages: ";
    string libName;
    getline(cin, libName);
    catalog.sortBooksInLibraryByNumberOfPages(libName);
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
        << "10. Sort Books in a specific library by cost\n"
        << "11. Sort Books in a specific library by number of pages\n"
        << "0. Exit\n";
    std::cout << "Enter your choice: ";
}
