#include "catch_amalgamated.hpp"
#include "article.h"
#include "author.h"

TEST_CASE("Article default constructor initializes with default values", "[constructor]") {
    Article article;
    REQUIRE(article.getTitle().empty());
    REQUIRE(article.getAuthor().getName().empty());
    REQUIRE(article.getAuthor().getSurname().empty());
    REQUIRE(article.getPublicationYear() == 0);
    REQUIRE(article.getJournal().empty());
}

TEST_CASE("Article parameterized constructor initializes title, author, publication year, and journal", "[constructor]") {
    Author author("John", "Doe");
    Article article("Sample Title", author, 2023, "Sample Journal");
    REQUIRE(article.getTitle() == "Sample Title");
    REQUIRE(article.getAuthor().getName() == "John");
    REQUIRE(article.getAuthor().getSurname() == "Doe");
    REQUIRE(article.getPublicationYear() == 2023);
    REQUIRE(article.getJournal() == "Sample Journal");
}

TEST_CASE("Article copy constructor creates a copy of the article", "[copy constructor]") {
    Author author("John", "Doe");
    Article original("Sample Title", author, 2023, "Sample Journal");
    Article copy(original);
    REQUIRE(copy.getTitle() == "Sample Title");
    REQUIRE(copy.getAuthor().getName() == "John");
    REQUIRE(copy.getAuthor().getSurname() == "Doe");
    REQUIRE(copy.getPublicationYear() == 2023);
    REQUIRE(copy.getJournal() == "Sample Journal");
}

TEST_CASE("Article getTitle method returns the title", "[getTitle]") {
    Author author("John", "Doe");
    Article article("Sample Title", author, 2023, "Sample Journal");
    REQUIRE(article.getTitle() == "Sample Title");
}

TEST_CASE("Article getAuthor method returns the author", "[getAuthor]") {
    Author author("John", "Doe");
    Article article("Sample Title", author, 2023, "Sample Journal");
    REQUIRE(article.getAuthor().getName() == "John");
    REQUIRE(article.getAuthor().getSurname() == "Doe");
}

TEST_CASE("Article getPublicationYear method returns the publication year", "[getPublicationYear]") {
    Author author("John", "Doe");
    Article article("Sample Title", author, 2023, "Sample Journal");
    REQUIRE(article.getPublicationYear() == 2023);
}

TEST_CASE("Article getJournal method returns the journal", "[getJournal]") {
    Author author("John", "Doe");
    Article article("Sample Title", author, 2023, "Sample Journal");
    REQUIRE(article.getJournal() == "Sample Journal");
}