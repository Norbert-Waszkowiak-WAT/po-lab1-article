#include "article.h"
#include "chapter.h"
#include "author.h"
#include "book.h"

int main() {
    Author jan("Jan", "Kowalski");
    jan.print();
    Article article("Sample Article", jan, 2023, "Sample Journal");
    article.displayInfo();
    return 0;
}
