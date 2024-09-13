#include "Library.h"
#include <algorithm>
#include <ranges>

using namespace std;

void Library::addBook(std::shared_ptr<printedProduct> Book)
{
    Books.push_back(Book);
    numberOfBooks++;
}

int Library::getNumberOfBooks() const { return numberOfBooks; }

void Library::takeBook(int i)
{
    if (Books[i]->getAvailability())
    {
        Books[i]->setAvailability(false);
        cout << "You've just taken a book! Congrats!" << endl;
    }
    else
    {
        cout << "Sorry!! But the book is already taken :(" << endl;
    }
}

void Library::sortBooksByCost()
{
    ranges::sort(Books, [](const shared_ptr<printedProduct>& a, const shared_ptr<printedProduct>& b) {
        return a->getCost() > b->getCost();
        });
}

void Library::sortBooksByNumberOfPages()
{
    ranges::sort(Books, [](const shared_ptr<printedProduct>& a, const shared_ptr<printedProduct>& b) {
        return a->getNumberOfPages() > b->getNumberOfPages();
        });
}

void Library::deleteBookByTitle(std::string_view title)
{
    auto it = remove_if(Books.begin(), Books.end(), [&](const shared_ptr<printedProduct>& book) {
        return book->getTitle() == title;
        });

    if (it != Books.end()) {
        Books.erase(it, Books.end());
        numberOfBooks--;
    }
}

std::vector<std::shared_ptr<printedProduct>> Library::findBooksByTitle(std::string_view title) const
{
    std::vector<std::shared_ptr<printedProduct>> result;
    for (const auto& book : Books)
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
        cout << i << ":" << endl;
        Books[i]->print();
    }
}

std::string Library::getName() const { return Name; }

void Library::setName(std::string_view name) { Name = name; }

void Library::printLibInfo() const
{
    cout << Name << endl
        << "Contains " << numberOfBooks << " books" << endl;
}
