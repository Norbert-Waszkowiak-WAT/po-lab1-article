#include "catch_amalgamated.hpp"
#include "author.h"
#include <iostream>
#include <sstream> 

TEST_CASE("Author constructor initializes name and surname", "[constructor]") {
    Author author("John", "Doe");
    REQUIRE(author.getName() == "John");
    REQUIRE(author.getSurname() == "Doe");
}

TEST_CASE("Author getName method returns the name", "[getName]") {
    Author author("John", "Doe");
    REQUIRE(author.getName() == "John");
}

TEST_CASE("Author getSurname method returns the surname", "[getSurname]") {
    Author author("John", "Doe");
    REQUIRE(author.getSurname() == "Doe");
}

TEST_CASE("Author toString method returns the correct string", "[toString]") {
    Author author("John", "Doe");
    REQUIRE(author.toString() == "John Doe");
}

TEST_CASE("Author print method outputs the correct string", "[print]") {
    Author author("John", "Doe");
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    author.print();

    std::cout.rdbuf(p_cout_streambuf);
    REQUIRE(oss.str() == "John Doe\n");
}

TEST_CASE("Author default constructor initializes empty name and surname", "[constructor][default]") {
    Author author;
    REQUIRE(author.getName().empty());
    REQUIRE(author.getSurname().empty());
}

TEST_CASE("Author setName and setSurname update fields", "[setters]") {
    Author author;
    author.setName("Anna");
    author.setSurname("Nowak");
    REQUIRE(author.getName() == "Anna");
    REQUIRE(author.getSurname() == "Nowak");
}

TEST_CASE("Author comparison operator works correctly", "[operator==]") {
    Author a1("Adam", "Mickiewicz");
    Author a2("Adam", "Mickiewicz");
    Author a3("Juliusz", "Słowacki");
    REQUIRE(a1 == a2);
    REQUIRE_FALSE(a1 == a3);
}