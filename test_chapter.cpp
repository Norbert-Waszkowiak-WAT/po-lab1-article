#include "catch_amalgamated.hpp"
#include "chapter.h"
#include "author.h"
#include "article.h"
#include <iostream>

TEST_CASE("Chapter default constructor initializes with default values", "[constructor]") {
    Chapter chapter;
    REQUIRE(chapter.getTitle().empty());
    REQUIRE(chapter.getAuthor().getName().empty());
    REQUIRE(chapter.getAuthor().getSurname().empty());
    REQUIRE(chapter.getChapterNumber() == 1);
}

TEST_CASE("Chapter parameterized constructor initializes title, author, and chapter number", "[constructor]") {
    Author author("John", "Doe");
    Chapter chapter("Sample Chapter", author, 1);
    REQUIRE(chapter.getTitle() == "Sample Chapter");
    REQUIRE(chapter.getAuthor().getName() == "John");
    REQUIRE(chapter.getAuthor().getSurname() == "Doe");
    REQUIRE(chapter.getChapterNumber() == 1);
}

TEST_CASE("Chapter copy constructor creates a copy of the chapter", "[copy constructor]") {
    Author author("John", "Doe");
    Chapter original("Sample Chapter", author, 1);
    Chapter copy(original);
    REQUIRE(copy.getTitle() == "Sample Chapter");
    REQUIRE(copy.getAuthor().getName() == "John");
    REQUIRE(copy.getAuthor().getSurname() == "Doe");
    REQUIRE(copy.getChapterNumber() == 1);
}

TEST_CASE("Chapter constructor from Article initializes title and author", "[constructor]") {
    Author author("John", "Doe");
    Article article("Sample Article", author, 2023, "Sample Journal");
    Chapter chapter(article);
    REQUIRE(chapter.getTitle() == "Sample Article");
    REQUIRE(chapter.getAuthor().getName() == "John");
    REQUIRE(chapter.getAuthor().getSurname() == "Doe");
    REQUIRE(chapter.getChapterNumber() == 1); // Assuming default chapter number is 1
}

TEST_CASE("Chapter getTitle method returns the title", "[getTitle]") {
    Author author("John", "Doe");
    Chapter chapter("Sample Chapter", author, 1);
    REQUIRE(chapter.getTitle() == "Sample Chapter");
}

TEST_CASE("Chapter getAuthor method returns the author", "[getAuthor]") {
    Author author("John", "Doe");
    Chapter chapter("Sample Chapter", author, 1);
    REQUIRE(chapter.getAuthor().getName() == "John");
    REQUIRE(chapter.getAuthor().getSurname() == "Doe");
}

TEST_CASE("Chapter getChapterNumber method returns the chapter number", "[getChapterNumber]") {
    Author author("John", "Doe");
    Chapter chapter("Sample Chapter", author, 1);
    REQUIRE(chapter.getChapterNumber() == 1);
}

TEST_CASE("Chapter displayInfo method outputs the correct string", "[displayInfo]") {
    Author author("John", "Doe");
    Chapter chapter("Sample Chapter", author, 1);
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    chapter.displayInfo();

    std::cout.rdbuf(p_cout_streambuf);
    REQUIRE(oss.str() == "Chapter 1: Sample Chapter by John Doe\n");
}