//
//  code.hpp
//  cps271MP8
//
//  Created by TianHang Hu on 4/6/24.
//



#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
using std::string;

#ifndef code_hpp
#define code_hpp

class Card {
private:
    int faceValue;
    string suit;
public:
    // constructors
    Card() : faceValue(0), suit("") {};
    Card(int value, string category) {
        faceValue = value;
        suit = category;
    }
    // getter functions
    int getfaceValue() const;
    string getSuit() const;
    // setter functions
    void setFaceValue(int);
    void setSuit(string);
};

class Deck {
private:
    // have access to vector operations and element operations. 52 empty Card objects
    vector<Card> vecCard;
public:
    // constructor
    Deck() : vecCard() {};  // an empty vector of Cards
    Deck(vector<Card> v) {
        vecCard = v;
    }
    // getter function
    vector<Card> getAllCards();
    Deck populateDeck();
    void shuffleDeck();
};

// guess only the face value
inline int GuessValue() {
    int userInput;
    
    cout << "Please guess the card's value between 1 and 13, inclusive at both ends." << endl;
    std::cin >> userInput;
    
    // Because input stream is in a failed state, cin will be evaluated to false
    while (!cin) {
        // Restore input stream to working state
        cin.clear();
        // Get rid of any garbage that user might have entered
        cin.ignore ( 100 , '\n' );
        cout << "I said enter an integer, Dumbass. Try again: ";
        // After cin is restored and any garbage in the stream has been cleared, store user input in number again
        cin >> userInput;
    }
    
    while (userInput < 1 || userInput > 13) {
        // Restore input stream to working state
        cin.clear();
        // Get rid of any garbage that user might have entered
        cin.ignore ( 100 , '\n' );
        cout << "I said an integer between 1 and 13, inclusive at both ends. Try again: ";
        // After cin is restored and any garbage in the stream has been cleared, store user input in number again
        cin >> userInput;
    }
    
    cout << "You have guessed " << userInput << " as the card's value." << endl;
        
//    catch (const std::out_of_range & oor) {
//        std::cerr << "Have you ever played Poker? Value should be between 1 and 13." << oor.what() << endl;
//    }
//    catch (const std::invalid_argument & ia) {
//        std::cerr << "Make sure you enter a number." << endl;
//    }
    
    return userInput;
};

inline bool containNumber(string n) {
    for (int i = 0; i < n.size(); ++i) {
        if (isdigit(n[i]) == 1){
            return true;
        }
    }
    return false;
}

inline string GuessSuit() {
    string userGuess;
    cout << "Please guess the card's suit: Diamond, Heart, Spade, and Club." << endl;
    std::cin >> userGuess;
    
    bool b = containNumber(userGuess);
    // Because input stream is in a failed state, cin will be evaluated to false
    if (b) {
        // Restore input stream to working state
        cin.clear();
        // Get rid of any garbage that user might have entered
        cin.ignore(100 , '\n');
        cout << "I said guess a suit, Dumbass. Try again: ";
        // After cin is restored and any garbage in the stream has been cleared, store user input in number again
        cin >> userGuess;
    }
    
    cout << "You have guessed " << userGuess << " as the card's suit." << endl;
    
    return userGuess;
};

inline void GuessBoth() {
    GuessValue();
    GuessSuit();
};

#endif /* code_hpp */
