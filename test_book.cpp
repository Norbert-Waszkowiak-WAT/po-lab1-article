#include "catch_amalgamated.hpp"
#include "book.h"
#include "chapter.h"
#include "author.h"

TEST_CASE("Book default constructor initializes with default values", "[constructor]") {
    Book book;
    REQUIRE(book.getTitle().empty());
    REQUIRE(book.getAuthor().getName().empty());
    REQUIRE(book.getAuthor().getSurname().empty());
    REQUIRE(book.getPublicationYear() == 0);
    REQUIRE(book.getChapters().empty());
}

TEST_CASE("Book parameterized constructor initializes title, author, publication year, and chapters", "[constructor]") {
    Author author("John", "Doe");
    Chapter chapter1("Chapter 1", author, 1);
    Chapter chapter2("Chapter 2", author, 2);
    vector<Chapter> chapters = {chapter1, chapter2};
    Book book("Sample Title", author, 2023, chapters);
    REQUIRE(book.getTitle() == "Sample Title");
    REQUIRE(book.getAuthor().getName() == "John");
    REQUIRE(book.getAuthor().getSurname() == "Doe");
    REQUIRE(book.getPublicationYear() == 2023);
    REQUIRE(book.getChapters().size() == 2);
    REQUIRE(book.getChapters()[0].getTitle() == "Chapter 1");
    REQUIRE(book.getChapters()[1].getTitle() == "Chapter 2");
}

TEST_CASE("Book addChapter method adds a chapter to the book", "[addChapter]") {
    Author author("John", "Doe");
    Book book("Sample Title", author, 2023, {});
    Chapter chapter("New Chapter", author, 1);
    book.addChapter(chapter);
    REQUIRE(book.getChapters().size() == 1);
    REQUIRE(book.getChapters()[0].getTitle() == "New Chapter");
}

TEST_CASE("Book getTitle method returns the title", "[getTitle]") {
    Author author("John", "Doe");
    Book book("Sample Title", author, 2023, {});
    REQUIRE(book.getTitle() == "Sample Title");
}

TEST_CASE("Book getAuthor method returns the author", "[getAuthor]") {
    Author author("John", "Doe");
    Book book("Sample Title", author, 2023, {});
    REQUIRE(book.getAuthor().getName() == "John");
    REQUIRE(book.getAuthor().getSurname() == "Doe");
}

TEST_CASE("Book getPublicationYear method returns the publication year", "[getPublicationYear]") {
    Author author("John", "Doe");
    Book book("Sample Title", author, 2023, {});
    REQUIRE(book.getPublicationYear() == 2023);
}

TEST_CASE("Book getChapters method returns the chapters", "[getChapters]") {
    Author author("John", "Doe");
    Chapter chapter1("Chapter 1", author, 1);
    Chapter chapter2("Chapter 2", author, 2);
    vector<Chapter> chapters = {chapter1, chapter2};
    Book book("Sample Title", author, 2023, chapters);
    REQUIRE(book.getChapters().size() == 2);
    REQUIRE(book.getChapters()[0].getTitle() == "Chapter 1");
    REQUIRE(book.getChapters()[1].getTitle() == "Chapter 2");
}


TEST_CASE("Book setTitle, setAuthor, setPublicationYear update fields", "[setters]") {
    Book book;
    Author author("Jane", "Austen");
    book.setTitle("Pride and Prejudice");
    book.setAuthor(author);
    book.setPublicationYear(1813);
    REQUIRE(book.getTitle() == "Pride and Prejudice");
    REQUIRE(book.getAuthor().getName() == "Jane");
    REQUIRE(book.getAuthor().getSurname() == "Austen");
    REQUIRE(book.getPublicationYear() == 1813);
}

TEST_CASE("Book copy constructor creates an identical copy", "[copy constructor]") {
    Author author("George", "Orwell");
    Chapter chapter("Chapter One", author, 1);
    vector<Chapter> chapters = {chapter};
    Book original("1984", author, 1949, chapters);
    Book copy(original);
    REQUIRE(copy.getTitle() == "1984");
    REQUIRE(copy.getAuthor().getName() == "George");
    REQUIRE(copy.getAuthor().getSurname() == "Orwell");
    REQUIRE(copy.getPublicationYear() == 1949);
    REQUIRE(copy.getChapters().size() == 1);
    REQUIRE(copy.getChapters()[0].getTitle() == "Chapter One");
}

TEST_CASE("Book operator== compares all fields", "[operator==]") {
    Author author("J.K.", "Rowling");
    Chapter chapter("The Boy Who Lived", author, 1);
    vector<Chapter> chapters = {chapter};
    Book book1("Harry Potter", author, 1997, chapters);
    Book book2("Harry Potter", author, 1997, chapters);
    Book book3("Harry Potter", author, 1998, chapters);
    REQUIRE(book1 == book2);
    REQUIRE_FALSE(book1 == book3);
}

TEST_CASE("Book with no chapters returns empty vector", "[chapters][empty]") {
    Author author("No", "Chapters");
    Book book("Empty Book", author, 2023, {});
    REQUIRE(book.getChapters().empty());
}