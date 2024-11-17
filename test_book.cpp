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