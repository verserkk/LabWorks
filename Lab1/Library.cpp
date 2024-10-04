#include "Library.h"




void Library::addBook(std::shared_ptr<PrintedProduct> book)
{
    books.push_back(book);
    numberOfBooks++;
}

int Library::getNumberOfBooks() const { return numberOfBooks; }

void Library::takeBook(int i)
{
    if (books[i]->getAvailability())
    {
        books[i]->setAvailability(false);
        std::cout << "You've just taken a book! Congrats!" << std::endl;
    }
    else
    {
        std::cout << "Sorry!! But the book is already taken :(" << std::endl;
    }
}

void Library::sortBooksByCost()
{
    std::ranges::sort(books, [](const std::shared_ptr<PrintedProduct>&a, const std::shared_ptr<PrintedProduct>& b) {
        return a->getCost() > b->getCost();
        });
}

void Library::sortBooksByNumberOfPages()
{
    std::ranges::sort(books, [](const std::shared_ptr<PrintedProduct>& a, const std::shared_ptr<PrintedProduct>& b) {
        return a->getNumberOfPages() > b->getNumberOfPages();
        });
}

void Library::deleteBookByTitle(std::string_view title)
{
    auto newEnd = std::ranges::remove_if(books, [&](const std::shared_ptr<PrintedProduct>& book) {
        return book->getTitle() == title;
        });

    books.erase(newEnd.begin(), books.end());
    numberOfBooks = books.size();
}

std::vector<std::shared_ptr<PrintedProduct>> Library::findBooksByTitle(std::string_view title) const
{
    std::vector<std::shared_ptr<PrintedProduct>> result;
    for (const auto& book : books)
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
        std::cout << i << ":" << std::endl;
        books[i]->print();
    }
}

std::string Library::getName() const { return name; }

void Library::setName(std::string_view nameIn) { name = nameIn; }

void Library::printLibInfo() const
{
    std::cout << name << std::endl
        << "Contains " << numberOfBooks << " books" << std::endl;
}
