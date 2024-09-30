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
        case 1: AddLibrary(catalog); break;
        case 2: AddBook(catalog); break;
        case 3: FindBook(catalog); break;
        case 4: DeleteBookFromAllLibraries(catalog); break;
        case 5: PrintAllLibraries(catalog); break;
        case 6: LibraryDetails(catalog); break;
        case 7: DeleteLibrary(catalog); break;
        case 8: FindBooksInLibrary(catalog); break;
        case 9: DeleteBookFromLibrary(catalog); break;
        case 10: SortByCost(catalog); break;
        case 11: SortByNumberOfPages(catalog); break;
        default: cout << "Invalid choice. Please enter a number between 0 and 9." << endl; break;
        }
    }
}