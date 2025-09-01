#pragma once
#include <string>
#include <vector>
#include "author.h"
#include "chapter.h"

using std::string;
using std::vector;

class Book {

private:
    string title;
    Author author;
    int publicationYear;
    vector<Chapter> chapters;


public:
    // Konstruktor domyślny
    Book()
        : title(""), author(), publicationYear(0), chapters() {}


    // Konstruktor parametryczny
    Book(const string& title, const Author& author, int publicationYear, const vector<Chapter>& chapters)
        : title(title), author(author), publicationYear(publicationYear), chapters(chapters) {}

    // Gettery
    string getTitle() const { return title; }
    Author getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
    vector<Chapter> getChapters() const { return chapters; }

    
    // Dodawanie rozdziału
    void addChapter(const Chapter& chapter) {
        chapters.push_back(chapter);
    }

    bool operator==(const Book& other) const {
        return 
            title == other.title &&
            author == other.author &&
            publicationYear == other.publicationYear &&
            chapters == other.chapters;
    }
};