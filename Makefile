CXX = g++
CXXFLAGS = -Wall --std=c++17

all: clean main test_article test_book test_chapter test_author

main: main.cpp chapter.cpp author.cpp article.cpp book.cpp
	$(CXX) $(CXXFLAGS) main.cpp chapter.cpp author.cpp article.cpp book.cpp -o main.o
	./main.o

comp_test_article: test_article.cpp article.cpp author.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_article.cpp article.cpp author.cpp catch_amalgamated.cpp -o test_article.o

comp_test_book: test_book.cpp book.cpp chapter.cpp author.cpp article.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_book.cpp book.cpp chapter.cpp author.cpp article.cpp catch_amalgamated.cpp -o test_book.o

comp_test_chapter: test_chapter.cpp chapter.cpp author.cpp article.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_chapter.cpp chapter.cpp author.cpp article.cpp catch_amalgamated.cpp -o test_chapter.o

comp_test_author: test_author.cpp author.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_author.cpp author.cpp catch_amalgamated.cpp -o test_author.o

test_article: comp_test_article
	./test_article.o

test_book: comp_test_book
	./test_book.o

test_chapter: comp_test_chapter
	./test_chapter.o

test_author: comp_test_author
	./test_author.o

clean:
	rm -f main test_article test_book test_chapter test_author