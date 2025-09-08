#pragma once // unikna wielokrotnej definicji klas.
#include <string>
#include "author.h"

class Article {

private:
    std::string title;
    Author author;
    int publicationYear;
    std::string journal;

public:
    // Konstruktor domyślny
    Article()
        : title(""), author(), publicationYear(0), journal("") {}

    // Konstruktor parametryczny
    Article(const std::string& title, const Author& author, int publicationYear, const std::string& journal)
        : title(title), author(author), publicationYear(publicationYear), journal(journal) {}

    // Konstruktor kopiujący
    Article(const Article& other)
        : title(other.title), author(other.author), publicationYear(other.publicationYear), journal(other.journal) {}

    // Gettery
    std::string getTitle() const { return title; }
    Author getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
    std::string getJournal() const { return journal; }

    // Settery (opcjonalnie, jeśli potrzebne)
    void setTitle(const std::string& t) { title = t; }
    void setAuthor(const Author& a) { author = a; }
    void setPublicationYear(int y) { publicationYear = y; }
    void setJournal(const std::string& j) { journal = j; }

    // Operator porównania (opcjonalnie)
    bool operator==(const Article& other) const {
        return title == other.title &&
               author == other.author &&
               publicationYear == other.publicationYear &&
               journal == other.journal;
               
    }
};