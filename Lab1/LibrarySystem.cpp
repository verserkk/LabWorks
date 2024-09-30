
#include "LibrarySystem.h"

using namespace std;

void handleAddLibrary(Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name: ";
    string name;
    getline(cin, name);

    auto library = make_shared<Library>();
    library->setName(name);
    catalog.addLibrary(library);
    cout << "Library \"" << name << "\" added." << endl;
}

void handleAddBook(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name: ";
    string libName;
    getline(cin, libName);

    if (auto library = catalog.findLibraryByName(libName); library) {
        cout << "Enter book details:" << endl;
        auto book = make_shared<printedProduct>(0, 0, "", "");
        book->createBook();
        library->addBook(book);
        cout << "Book added to library \"" << libName << "\"." << endl;
    }
    else {
        cout << "Library not found." << endl;
    }
}

void handleFindBook(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter book title to find: ";
    string bookTitle;
    getline(cin, bookTitle);
    catalog.findBookByName(bookTitle);
}

void handleDeleteBookFromAllLibraries(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter book title to delete: ";
    string bookTitle;
    getline(cin, bookTitle);
    catalog.deleteBookFromAllLibraries(bookTitle);
    cout << "Book(s) with title \"" << bookTitle << "\" have been deleted from all libraries." << endl;
}

void handlePrintAllLibraries(const Catalog& catalog) {
    catalog.printAllLibrarys();
}

void handleLibraryDetails(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name to view details: ";
    string libName;
    getline(cin, libName);
    catalog.printFullLibraryInfo(libName);
}

void handleDeleteLibrary(Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name to delete: ";
    string libName;
    getline(cin, libName);
    catalog.deleteLibraryByName(libName);
    cout << "Library \"" << libName << "\" has been deleted." << endl;
}

void handleFindBooksInLibrary(const Catalog& catalog) {
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

void handleDeleteBookFromLibrary(const Catalog& catalog) {
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

void handleSortByCost(const Catalog& catalog) {
    cin.ignore();
    cout << "Enter library name to sort books by cost: ";
    string libName;
    getline(cin, libName);
    catalog.sortBooksInLibraryByCost(libName);
}

void handleSortByNumberOfPages(const Catalog& catalog) {
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
