#include <iostream>
#include "author.h"
#include "article.h"
#include "chapter.h"
#include "author.h"
#include "book.h"


int main() {
    Author author("Jan", "Kowalski");
    Article article("Sample Article", author, 2024, "Sample Journal");
    Chapter chapter(article);
    Book book("Przykladowa Ksiazka", author, 2024, {chapter});

    std::cout << "Tytul ksiazki: " << book.getTitle() << std::endl;
    std::cout << "Autor ksiazki: " << book.getAuthor().getName() << " " << book.getAuthor().getSurname() << std::endl;
    std::cout << "Rok wydania: " << book.getPublicationYear() << std::endl;
    std::cout << "Rozdzialy:" << std::endl;

    for (const auto& ch : book.getChapters()) {
        ch.displayInfo(); //wywołanie displayInfo() zamiast getArticle().getTitle()
        
    }

    return 0;
}
