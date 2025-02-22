#include <iostream>
using namespace std;

class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
         */
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
         */
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main(){
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    book1.printBook(); //Giai tich 1 Nguyen Dinh Huy 2000
    
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    Book book2 = book1;
    book2.printBook(); //Giai tich 1 Nguyen Dinh Huy 2000

    return 0;
}