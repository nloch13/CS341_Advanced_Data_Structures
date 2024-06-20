War.exe: driver.o card.o StandardDeck.o deck.o NonStandardDeck.o
	g++ driver.o card.o StandardDeck.o deck.o NonStandardDeck.o -o War.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

deck.o: deck.cpp deck.h
	g++ -c deck.cpp -o deck.o

StandardDeck.o: StandardDeck.cpp StandardDeck.h 
	g++ -c StandardDeck.cpp -o StandardDeck.o

NonStandardDeck.o: NonStandardDeck.cpp NonStandardDeck.h 
	g++ -c NonStandardDeck.cpp -o NonStandardDeck.o

card.o: card.cpp card.h 
	g++ -c card.cpp -o card.o

clean:
	rm *.o *.exe