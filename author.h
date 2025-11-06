#pragma once
#include <string>
#include <iostream>


class Author {
    private:
    std::string name;
    std::string surname;

    public:

    // Konstruktor domyślny
    Author() : name(""), surname("") {}

    // Konstruktor parametryczny
    Author(const std::string& name, const std::string& surname)
        : name(name), surname(surname) {}


    // Gettery
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }


    // toString
    std::string toString() const {
        return name + " " + surname;

    }

    // print
    void print() const {
        std::cout << toString() << "\n";
    }


    // Settery (opcjonalnie)
    void setName(const std::string& n) { name = n; }
    void setSurname(const std::string& s) { surname = s; }


    // Operator porównania
    bool operator==(const Author& other) const {
        return name == other.name && surname == other.surname;
        
    }
};