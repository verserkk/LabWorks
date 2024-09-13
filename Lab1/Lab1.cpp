#include "LibrarySystem.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    Catalog catalog;
    int choice;

    while (true)
    {
        cout << "Menu:\n"
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
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice==0)
            return 0;

        if (choice==1)
        {
            cin.ignore(); 
            cout << "Enter library name: ";
            string name;
            getline(cin, name);

            auto library = make_shared<Library>();
            library->setName(name);
            catalog.addLibrary(library);
            cout << "Library \"" << name << "\" added." << endl;

        }
        if (choice==2)
        {
            cin.ignore(); 
            cout << "Enter library name: ";
            string libName;
            getline(cin, libName);

            
            if (auto library = catalog.findLibraryByName(libName); library)
            {
                cout << "Enter book details:" << endl;
                auto book = make_shared<printedProduct>(0, 0, "", "");
                book->createBook();
                library->addBook(book);
                cout << "Book added to library \"" << libName << "\"." << endl;
            }
            else
            {
                cout << "Library not found." << endl;
            }
           
        }
        if (choice==3)
        {
            cin.ignore(); 
            cout << "Enter book title to find: ";
            string bookTitle;
            getline(cin, bookTitle);
            catalog.findBookByName(bookTitle);
        }
        if (choice==4)
        {
            cin.ignore(); 
            cout << "Enter book title to delete: ";
            string bookTitle;
            getline(cin, bookTitle);
            catalog.deleteBookFromAllLibraries(bookTitle);
            cout << "Book(s) with title \"" << bookTitle << "\" have been deleted from all libraries." << endl;
      
        }
        if (choice==5)
        {
            catalog.printAllLibrarys();
    
        }
        if (choice==6)
        {
            cin.ignore(); 
            cout << "Enter library name to view details: ";
            string libName;
            getline(cin, libName);
            catalog.printFullLibraryInfo(libName);
         
        }
        if (choice==7)
        {
            cin.ignore(); 
            cout << "Enter library name to delete: ";
            string libName;
            getline(cin, libName);
            catalog.deleteLibraryByName(libName);
            cout << "Library \"" << libName << "\" has been deleted." << endl;
         
        }
        if (choice==8)
        {
            cin.ignore(); 
            cout << "Enter library name: ";
            string libName;
            getline(cin, libName);

            
            if (auto library = catalog.findLibraryByName(libName); library)
            {
                cout << "Enter book title to find: ";
                string bookTitle;
                getline(cin, bookTitle);
                auto books = library->findBooksByTitle(bookTitle);
                if (!books.empty())
                {
                    cout << "Books in library \"" << libName << "\":" << endl;
                    for (const auto& book : books)
                    {
                        book->print();
                    }
                }
                else
                {
                    cout << "No books with title \"" << bookTitle << "\" found in library \"" << libName << "\"." << endl;
                }
            }
            else
            {
                cout << "Library not found." << endl;
            }
         
        }
        if (choice==9)
        {
            cin.ignore(); 
            cout << "Enter library name: ";
            string libName;
            getline(cin, libName);

            
            if (auto library = catalog.findLibraryByName(libName); library)
            {
                cout << "Enter book title to delete: ";
                string bookTitle;
                getline(cin, bookTitle);
                library->deleteBookByTitle(bookTitle);
                cout << "Book(s) with title \"" << bookTitle << "\" have been deleted from library \"" << libName << "\"." << endl;
            }
            else
            {
                cout << "Library not found." << endl;
            }
    
        }
        if (choice>9 || choice<0)
            cout << "Invalid choice. Please enter a number between 0 and 9." << endl;
        
    }


}
