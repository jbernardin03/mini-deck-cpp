#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // for std::shuffle
#include <random>     // for random number generator

using namespace std;

// Card class stores a suit and value
class Card {
private:
    string suit;
    int value;

public:
    // Constructor
    Card(string s, int v) {
        suit = s;
        value = v;
    }

    // Getter for suit
    string getSuit() const {
        return suit;
    }

    // Getter for value
    int getValue() const {
        return value;
    }

    // Print the card
    void printCard() const {
        cout << suit << " " << value;
    }
};

// Deck class stores all cards in a vector
class Deck {
private:
    vector<Card> cards;

public:
    // Constructor creates the 20-card deck
    Deck() {
        string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

        // Create all combinations of suits and values
        for (int i = 0; i < 4; i++) {
            for (int value = 1; value <= 5; value++) {
                cards.push_back(Card(suits[i], value));
            }
        }
    }

    // Shuffle the deck
    void shuffle() {
        random_device rd;
        mt19937 gen(rd());

        std::shuffle(cards.begin(), cards.end(), gen);
    }

    // Draw a card from the back of the vector
    Card draw() {
        Card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }

    // Return remaining number of cards
    int cardsRemaining() const {
        return cards.size();
    }
};

int main() {

    // Create deck
    Deck deck;

    // Print starting card count
    cout << "Starting card count: "
         << deck.cardsRemaining() << endl;

    // Shuffle once
    deck.shuffle();

    // Draw first two cards
    Card card1 = deck.draw();
    Card card2 = deck.draw();

    cout << "\nFirst card: ";
    card1.printCard();
    cout << endl;

    cout << "Second card: ";
    card2.printCard();
    cout << endl;

    // Calculate value sum
    int sum = card1.getValue() + card2.getValue();

    cout << "\nSum of first two card values: "
         << sum << endl;

    cout << "Cards remaining: "
         << deck.cardsRemaining() << endl;

    // Draw the remaining 18 cards
    cout << "\nRemaining cards:" << endl;

    while (deck.cardsRemaining() > 0) {
        Card currentCard = deck.draw();
        currentCard.printCard();
        cout << endl;
    }

    // Print final card count
    cout << "\nFinal card count: "
         << deck.cardsRemaining() << endl;

    return 0;
}