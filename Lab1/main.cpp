#include "PrintedProduct.h"
#include "Library.h"
#include "Catalog.h"
#include "LibrarySystem.h"





int main() {
    setlocale(LC_ALL,"ru_RU.UTF-8");
    pqxx::connection C("host=localhost port=5432 dbname=postgres user=postgres password=123321");
    Catalog catalog("host=localhost port=5432 dbname=postgres user=postgres password=123321");
   
    
    
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 0) return 0;

        switch (choice) {
        case 1: addLibrary(catalog); 
            break;
        case 2: addBook(catalog); 
            break;
        case 3: findBook(catalog); 
            break;
        case 4: deleteBookFromAllLibraries(catalog);
            break;
        case 5: printAllLibraries(catalog);
            break;
        case 6: libraryDetails(catalog);
            break;
        case 7: deleteLibrary(catalog);
            break;
        case 8: findBooksInLibrary(catalog);
            break;
        case 9: deleteBookFromLibrary(catalog);
            break;
        case 10: sortByCost(catalog);
            break;
        case 11: sortByNumberOfPages(catalog);
            break;
        default: std::cout << "Invalid choice. Please enter a number between 0 and 9." << std::endl;
            break;
        }
    }
}