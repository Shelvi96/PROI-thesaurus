CFLAGS=-std=c++11 -Wall -Wextra -Wshadow

main: main.o Word.o Thesaurus.o
	g++ -o main Word.o Thesaurus.o main.o $(CFLAGS)

Word.o: Word.cpp Word.h
	g++ -c Word.cpp $(CFLAGS)

Thesaurus.o: Thesaurus.cpp Thesaurus.h
	g++ -c Thesaurus.cpp $(CFLAGS)

main.o: main.cpp
	g++ -c main.cpp $(CFLAGS)

clean:
	@echo "Removing unnecessary files..."
	rm Word.o
	rm Thesaurus.o
	rm main.o
	rm main
	@echo "Done."