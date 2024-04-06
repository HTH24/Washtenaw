//
//  code.cpp
//  cps271MP8
//
//  Created by TianHang Hu on 4/6/24.
//

#include "code.hpp"

vector<string> allSuits = {"Diamond", "Heart", "Spade", "Club"};
vector<int> allCardValues = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

int Card::getfaceValue() const {
    return faceValue;
}

string Card::getSuit() const {
    return suit;
}

void Card::setFaceValue(int i) {
    faceValue = i;
}

void Card::setSuit(string s) {
    suit = s;
}

vector<Card> Deck::getAllCards() {
    return vecCard;
}

// initialize the Deck to 52 Card objects
Deck Deck::populateDeck() {
    for (const auto &value : allCardValues) {
        for (const auto &suit : allSuits) {
            vecCard.push_back(Card(value, suit));
        }
    }
    if (vecCard.size() == 52) {
        cout << "Successfully populated a deck of 52 Cards." << endl;
    }
    Deck fullDeck(vecCard);
    return fullDeck;
}

void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 gen(rd());
    // swap needs non-const objects to swap, cannot write vecCard.cbegin()
    std::shuffle(vecCard.begin(), vecCard.end(), gen);
}
