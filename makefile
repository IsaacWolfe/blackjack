blackjack: blackjack.o
	g++ blackjack.o -o blackjack
blackjack.o: blackjack.cpp blackjack.h
	g++ -c blackjack.cpp
clean:
	rm -f *.o blackjack
