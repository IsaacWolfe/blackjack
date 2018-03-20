#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Function parameters */
void dealerFirst(int *);
void dealerSecond(int *);
void selfFirst(int *);
void selfSecond(int *);
bool playerHand(int *, int *, int *, int *);
int dealerHand(int *, int *);

/* Main */
int main() {
    int dealer1, dealer2, self1, self2;
    bool result;
    srand(time(0));
    cout << "Simple blackjack program.\n\n";

    dealerFirst(&dealer1);
    dealerSecond(&dealer2);
    selfFirst(&self1);
    selfSecond(&self2);

    cout << "Dealer: Hidden + " << dealer2 << endl << endl;
    cout << "You have: " << self1 << " + " << self2 << endl;
    result = playerHand(&dealer1, &dealer2, &self1, &self2);
    if (result == true){
        cout << "Congrats you beat the dealer.\n";
    }
    else {
        cout << "Better luck next time.\n";
    }
    return 0;
}
/* Cards dealt, multiple functions due to rand and srand*/
void dealerFirst(int *dealer1){
    *dealer1 = rand() % 11 + 1;
}
void dealerSecond(int *dealer2){
    *dealer2 = rand() % 11 + 1;
}
void selfFirst(int *self1){
    *self1 = rand() % 11 + 1;
}
void selfSecond(int *self2){
    *self2 = rand() % 11 + 1;
}

/* Player hand */
bool playerHand(int *dealer1, int *dealer2, int *self1, int *self2){
    int newNum, total = *self1 + *self2, dTotal;
    char input = 'a';
    bool result;
    for (;total < 21;){
        cout << "Please enter what you would like to do.\n(H)it\n(S)tand\n";
        cin >> input;
        if (input == 'H' or input == 'h'){
            newNum = rand() % 11 + 1;
            total = total + newNum;
            cout << "You drew " << newNum << " and now have " << total << " total\n";
        }
        else if (input == 'S' or input == 's'){
            break;
        }
        else{
            cout << "Enter a valid input.\n";
            continue;
        }
    }
    if (total > 21){
        cout << "You busted, better luck next time.\n";
        exit(0);
    }
    else {
        dTotal = dealerHand(dealer1, dealer2);
    }
    cout << "Your hand is " << total << endl << "Dealers hand is " << dTotal << endl;
    if (total > dTotal && dTotal < 22)
        result = true;
    else if (dTotal > 22) {
        cout << "Dealer busted." << endl;
        result = false;
    }
    else if (total == dTotal){
        cout << "Tied\n";
        result = false;
    }
    else {
        cout << "You lost. ";
        result = false;
    }
    return result;
}

/* Dealer hand */
int dealerHand(int *dealer1, int *dealer2){
    int num, dTotal = *dealer1 + *dealer2;
    for (;dTotal < 17;){
        num = rand() % 11 + 1;
        dTotal = dTotal + num;
    }
    return dTotal;
}
