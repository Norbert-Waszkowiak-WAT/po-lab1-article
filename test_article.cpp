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

TEST_CASE("Tworzenie i modyfikacja artykułu naukowego", "[Article][integration]") {
    Author author("Maria", "Curie");
    Article article("O promieniotwórczości", author, 1903, "Comptes Rendus");

    SECTION("Początkowe wartości są poprawne") {
        REQUIRE(article.getTitle() == "O promieniotwórczości");
        REQUIRE(article.getAuthor().getName() == "Maria");
        REQUIRE(article.getAuthor().getSurname() == "Curie");
        REQUIRE(article.getPublicationYear() == 1903);
        REQUIRE(article.getJournal() == "Comptes Rendus");
    }

    SECTION("Zmiana tytułu i czasopisma") {
        article.setTitle("Nowy tytuł");
        article.setJournal("Nature");
        REQUIRE(article.getTitle() == "Nowy tytuł");
        REQUIRE(article.getJournal() == "Nature");
    }

    SECTION("Zmiana autora i roku publikacji") {
        Author newAuthor("Albert", "Einstein");
        article.setAuthor(newAuthor);
        article.setPublicationYear(1905);
        REQUIRE(article.getAuthor().getName() == "Albert");
        REQUIRE(article.getAuthor().getSurname() == "Einstein");
        REQUIRE(article.getPublicationYear() == 1905);
    }
}

TEST_CASE("Porównywanie artykułów", "[Article][operator==]") {
    Author a1("Isaac", "Newton");
    Author a2("Isaac", "Newton");
    Article art1("Philosophiæ Naturalis Principia Mathematica", a1, 1687, "Royal Society");
    Article art2("Philosophiæ Naturalis Principia Mathematica", a2, 1687, "Royal Society");
    Article art3("Opticks", a1, 1704, "Royal Society");

    REQUIRE(art1 == art2);
    REQUIRE_FALSE(art1 == art3);
}