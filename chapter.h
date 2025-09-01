#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "author.h"
#include "article.h"

class Chapter {

private:
    std::string title;
    Author author;
    int chapterNumber;


public:
    // Konstruktor domyślny
    Chapter() : title(""), author(), chapterNumber(1) {}


    // Konstruktor parametryczny
    Chapter(const std::string& title, const Author& author, int chapterNumber)
        : title(title), author(author), chapterNumber(chapterNumber) {}


    // Konstruktor kopiujący
    Chapter(const Chapter& other)
        : title(other.title), author(other.author), chapterNumber(other.chapterNumber) {}


    // Konstruktor z Article
    Chapter(const Article& article)
        : title(article.getTitle()), author(article.getAuthor()), chapterNumber(1) {}

    // Gettery
    std::string getTitle() const { return title; }
    Author getAuthor() const { return author; }
    int getChapterNumber() const { return chapterNumber; }

    // Wyświetlanie informacji o rozdziale
    void displayInfo() const {
        std::cout << "Chapter " << chapterNumber << ": " << title
                  << " by " << author.getName() << " " << author.getSurname() << std::endl;

    }


    // Przeciążenie operatora przypisania
    Chapter& operator=(const Chapter& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            chapterNumber = other.chapterNumber;
        }
        return *this;

    }


    // Przeciążenie operatora porównania
    bool operator==(const Chapter& other) const {
        return title == other.title && author == other.author && chapterNumber == other.chapterNumber;
    }
    
};