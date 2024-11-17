#include "catch_amalgamated.hpp"
#include "author.h"
#include <iostream>

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