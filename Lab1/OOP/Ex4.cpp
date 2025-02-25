#include <iostream>
#include <string.h>
using namespace std;

class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book(): title(nullptr), authors(nullptr), publishingYear(0) {}

    Book(const char* title, const char* authors, int publishingYear) {
        if(title != nullptr) {
            this->title = new char[strlen(title) + 1];
            strcpy(this->title, title);
        }
        
        if(authors != nullptr) {
            this->authors = new char[strlen(authors) + 1];
            strcpy(this->authors, authors);
        }
    
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        if(book.title != nullptr) {
            this->title = new char[strlen(book.title) + 1];
            strcpy(this->title, book.title);    
        }
        
        if(book.authors != nullptr) {
            this->authors = new char[strlen(book.authors) + 1];
            strcpy(this->authors, book.authors);
        }
    
        this->publishingYear = book.publishingYear;
    }
    
    void setTitle(const char* title)
    {
        if(title != nullptr) {
            this->title = new char[strlen(title) + 1];
            strcpy(this->title, title);
        }
    }

    void setAuthors(const char* authors)
    {
        if(authors != nullptr) {
            this->authors = new char[strlen(authors) + 1];
            strcpy(this->authors, authors);
        }
    }

    void setPublishingYear(int publishingYear)
    {
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        return this->title;
    }

    char* getAuthors() const
    {
        return this->authors;
    }

    int getPublishingYear() const
    {
        return this->publishingYear;
    }

    ~Book()
    {
        delete[] this->title;
        delete[] this->authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main(){
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    book1.printBook(); //Giai tich 1 Nguyen Dinh Huy 2000
    
    // Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    // Book book2 = book1;
    // book2.printBook(); //Giai tich 1 Nguyen Dinh Huy 2000

    return 0;
}