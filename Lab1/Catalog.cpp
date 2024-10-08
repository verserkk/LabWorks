#include "Catalog.h"

#include "LibrarySystem.h"


void Catalog::addLibrary(std::shared_ptr<Library> lib)
{
    librarys.push_back(lib);
    numOfLibrarys++;
}

int Catalog::getNumOfLibrarys() const { return numOfLibrarys; }

std::shared_ptr<Library> Catalog::findLibraryByName(std::string_view name) const
{
    for (const auto& library : librarys)
    {
        if (library->getName() == name)
        {
            return library;
        }
    }
    return nullptr;
}
void Catalog::saveToDatabase(const std::string& connectionString) {
    try {
        pqxx::connection C(connectionString);
        pqxx::work W(C);
        prepareStatements(C);

        
        W.exec("DELETE FROM books");
        W.exec("DELETE FROM libraries");

  
        for (const auto& library : librarys) {
            W.exec_prepared("insert_library", library->getName());

            for (const auto& book : library->getBooks()) {
                W.exec_prepared("insert_book",
                    book->getTitle(),
                    book->getNameOfAuthor(),
                    book->getCost(),
                    book->getNumberOfPages(),
                    library->getName());
            }
        }
        W.commit();
    }
    catch (const std::system_error& e) {
        std::cerr << "Error saving libraries and books: " << e.what() << std::endl;
    }

}
void Catalog::loadFromDatabase(const std::string& connectionString) {
    try {
        pqxx::connection C(connectionString);
        pqxx::work W(C);
        prepareStatements(C); 
        pqxx::result libraries = W.exec("SELECT * FROM libraries");
        for (const auto& row : libraries) {
            auto lib = std::make_shared<Library>();
            lib->setName(row[1].as<std::string>()); 

        
            pqxx::result books = W.exec_prepared("select_books_by_library", lib->getName());
            for (const auto& bookRow : books) {
                auto book = std::make_shared<PrintedProduct>(
                    bookRow[2].as<int>(), 
                    bookRow[3].as<int>(), 
                    bookRow[0].as<std::string>(),
                    bookRow[1].as<std::string>()  
                );
                lib->addBook(book);
            }
            librarys.push_back(lib);
        }
        W.commit();
    }

    catch (const std::system_error& e) {
        std::cerr << "Error loading libraries: " << e.what() << std::endl;
    }
}
Catalog::Catalog(const std::string& connectionString) {
    loadFromDatabase(connectionString);
}
Catalog::~Catalog() {
    saveToDatabase("host = localhost port = 5432 dbname = postgres user = postgres password = 123321");
}
void Catalog::operator +=(std::shared_ptr<Library> lib) {
    this->addLibrary(lib);
}
void Catalog::deleteLibraryByName(std::string_view name)
{
    auto newEnd = std::ranges::remove_if(librarys, [&](const std::shared_ptr<Library>& library) {
        return library->getName() == name;
        });
    librarys.erase(newEnd.begin(), librarys.end());
    numOfLibrarys = librarys.size();
}

void Catalog::printAllLibrarys() const
{
    for (const auto& library : librarys)
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
        std::cout << "Library with name \"" << name << "\" not found." << std::endl;
    }
}

void Catalog::findBookByName(const std::string& name) const
{
    bool found = false;

    for (const auto& library : librarys)
    {
        auto books = library->findBooksByTitle(name);
        if (!books.empty())
        {
            found = true;
            std::cout << "Books in library \"" << library->getName() << "\":" << std::endl;
            for (const auto& book : books)
            {
                book->print();
            }
        }
    }

    if (!found)
    {
        std::cout << "No books with title \"" << name << "\" were found." << std::endl;
    }
}

void Catalog::deleteBookFromAllLibraries(const std::string& bookTitle) const
{
    for (const auto& library : librarys)
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
        std::cout << "Books in library \"" << libName << "\" sorted by cost." << std::endl;
    }
    else {
        std::cout << "Library with name \"" << libName << "\" not found." << std::endl;
    }
}

void Catalog::sortBooksInLibraryByNumberOfPages(const std::string& libName) const {
    if (auto library = findLibraryByName(libName); library) {
        library->sortBooksByNumberOfPages();
        std::cout << "Books in library \"" << libName << "\" sorted by number of pages." << std::endl;
    }
    else {
        std::cout << "Library with name \"" << libName << "\" not found." << std::endl;
    }
}