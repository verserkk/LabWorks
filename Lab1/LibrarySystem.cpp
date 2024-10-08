
#include "LibrarySystem.h"

void addLibrary(Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter library name: ";
    std::string name;
    getline(std::cin, name);

    auto library = std::make_shared<Library>();
    library->setName(name);
    catalog+=library;
    std::cout << "Library \"" << name << "\" added." << std::endl;
}
void prepareStatements(pqxx::connection& C) {
    C.prepare("insert_library",
        "INSERT INTO libraries (name) VALUES ($1) "
        "ON CONFLICT (name) DO UPDATE SET name = EXCLUDED.name");
    C.prepare("insert_book",
        "INSERT INTO books (title, author, cost, number_of_pages, library_id) "
        "VALUES ($1, $2, $3, $4, (SELECT id FROM libraries WHERE name = $5)) "
        "ON CONFLICT (title) DO UPDATE SET author = EXCLUDED.author, "
        "cost = EXCLUDED.cost, number_of_pages = EXCLUDED.number_of_pages");
    C.prepare("select_books_by_library",
        "SELECT title, author, cost, number_of_pages FROM books WHERE library_id = (SELECT id FROM libraries WHERE name = $1)");
}
void addBook(const Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter library name: ";
    std::string libName;
    getline(std::cin, libName);

    if (auto library = catalog.findLibraryByName(libName); library) {
        std::cout << "Enter book details:" << std::endl;
        auto book = std::make_shared<PrintedProduct>(0,0,"","");
        book->createBook();
        *library+= book;
        std::cout << "Book added to library \"" << libName << "\"." << std::endl;
    }
    else {
        std::cout << "Library not found." << std::endl;
    }
}

void findBook(const Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter book title to find: ";
    std::string bookTitle;
    getline(std::cin, bookTitle);
    catalog.findBookByName(bookTitle);
}

void deleteBookFromAllLibraries(const Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter book title to delete: ";
    std::string bookTitle;
    getline(std::cin, bookTitle);
    catalog.deleteBookFromAllLibraries(bookTitle);
    std::cout << "Book(s) with title \"" << bookTitle << "\" have been deleted from all libraries." << std::endl;
}

void printAllLibraries(const Catalog& catalog) {
    catalog.printAllLibrarys();
}

void libraryDetails(const Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter library name to view details: ";
    std::string libName;
    getline(std::cin, libName);
    catalog.printFullLibraryInfo(libName);
}

void deleteLibrary(Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter library name to delete: ";
    std::string libName;
    getline(std::cin, libName);
    catalog.deleteLibraryByName(libName);
    std::cout << "Library \"" << libName << "\" has been deleted." << std::endl;
}

void findBooksInLibrary(const Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter library name: ";
    std::string libName;
    getline(std::cin, libName);

    if (auto library = catalog.findLibraryByName(libName); library) {
        std::cout << "Enter book title to find: ";
        std::string bookTitle;
        getline(std::cin, bookTitle);
        auto books = library->findBooksByTitle(bookTitle);
        if (!books.empty()) {
            std::cout << "Books in library \"" << libName << "\":" << std::endl;
            for (const auto& book : books) {
                book->print();
            }
        }
        else {
            std::cout << "No books with title \"" << bookTitle << "\" found in library \"" << libName << "\"." << std::endl;
        }
    }
    else {
        std::cout << "Library not found." << std::endl;
    }
}

void deleteBookFromLibrary(const Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter library name: ";
    std::string libName;
    getline(std::cin, libName);

    if (auto library = catalog.findLibraryByName(libName); library) {
        std::cout << "Enter book title to delete: ";
        std::string bookTitle;
        getline(std::cin, bookTitle);
        library->deleteBookByTitle(bookTitle);
        std::cout << "Book(s) with title \"" << bookTitle << "\" have been deleted from library \"" << libName << "\"." << std::endl;
    }
    else {
        std::cout << "Library not found." << std::endl;
    }
}

void sortByCost(const Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter library name to sort books by cost: ";
    std::string libName;
    getline(std::cin, libName);
    catalog.sortBooksInLibraryByCost(libName);
}

void sortByNumberOfPages(const Catalog& catalog) {
    std::cin.ignore();
    std::cout << "Enter library name to sort books by number of pages: ";
    std::string libName;
    std::getline(std::cin, libName);
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

void printLibraryInfo(const Library& library) {
    std::cout << "Library Name: " << library.name << std::endl;
    std::cout << "Number of Books: " << library.numberOfBooks << std::endl;
}