#include "PrintedProduct.h"
#include "Library.h"
#include "Catalog.h"
#include "LibrarySystem.h"



using namespace std;


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