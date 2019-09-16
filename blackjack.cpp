#include <iostream>
#include "blackjack.h"
using namespace std;

int main() {
		bool playing = true;

		cout << "Welcome to Blackjack.\nThe goal is to add the cards up to 21 without going over. Aces count as an 11 or 1 if you go over. More than 5 cards in your hand without going over is an automatic win.";
		do {
				char menu;
				Card opShow, opHidden, self1, self2;
				cout << "Please select from below:\n\t(H)it\n\t(S)tand\n\t(E)xit" << endl;
				cin >> menu;
				if (menu == 'h' || menu == 'H') {
				}
		} while(playing);
		return 0;
}

Card::Card() {
		value = rand() % 52 + 1;
		cout << value;
}
