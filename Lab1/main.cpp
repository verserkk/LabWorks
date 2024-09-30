#include "PrintedProduct.h"
#include "Library.h"
#include "Catalog.h"
#include "LibrarySystem.h"

#include <iostream>
#include <memory>

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

int main() {
    Catalog catalog;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 0) return 0;

        switch (choice) {
        case 1: handleAddLibrary(catalog); break;
        case 2: handleAddBook(catalog); break;
        case 3: handleFindBook(catalog); break;
        case 4: handleDeleteBookFromAllLibraries(catalog); break;
        case 5: handlePrintAllLibraries(catalog); break;
        case 6: handleLibraryDetails(catalog); break;
        case 7: handleDeleteLibrary(catalog); break;
        case 8: handleFindBooksInLibrary(catalog); break;
        case 9: handleDeleteBookFromLibrary(catalog); break;
        default: cout << "Invalid choice. Please enter a number between 0 and 9." << endl; break;
        }
    }
}