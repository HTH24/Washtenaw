//
//  main.cpp
//  cps271MP8
//
//  Created by TianHang Hu on 4/6/24.
//

#include "code.hpp"

int chooseGuessGame() {
    int userInput;
    cout << "Please choose which game you want to play by entering a number among 1, 2, and 3, or enter a number other than those three to exit the game." << endl;
    cout << "1: Guess Value Only\n2: Guess Suit Only\n3: Guess Both" << endl;
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

    switch (userInput) {
        case 1:
            cout << "You chose to play the 'Guess Face Value Only' game" << endl;
            break;
        case 2:
            cout << "You chose to play the 'Guess Suit Only' game" << endl;
            break;
        case 3:
            cout << "You chose to play the 'Guess Both' game" << endl;
            break;
        default:
            cout << "You entered something other than 1, 2, or 3 to exit the game." << endl;
            exit(0);
    }
    
    return userInput;
}

int main() {
    // program random draws a card from the allCards vector / the deck
    int generatedNumber(0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 52); // closed interval [1, 52]
    generatedNumber = dist(gen);
    
    Deck emptyDeck;
    Deck fullDeck = emptyDeck.populateDeck();
    fullDeck.shuffleDeck();
    
    vector<Card> allCards = fullDeck.getAllCards();
    Card gameCard = allCards[generatedNumber];
    
    auto correctValue = gameCard.getfaceValue();
    auto correctSuit = gameCard.getSuit();
    /*
     let the user choose whether to 1. guess only the card value 2. guess only the suit 3. guess both
     */
    int userChoice = chooseGuessGame();
    
    /*
     check if the user was correct
     */
    
    if (userChoice == 1) {
        int guessedValue = GuessValue();
        if (guessedValue == correctValue) {
            cout << "Your guess was correct. Genius." << endl;
        }
        else {
            cout << "Wrong Number." << endl;
            cout << "The correct number is " << correctValue << endl;
        }
    }
    
    else if (userChoice == 2) {
        string guessedSuit = GuessSuit();
        if (guessedSuit == correctSuit) {
            cout << "Your guess was correct. Genius." << endl;
        }
        else {
            cout << "Wrong Suit." << endl;
            cout << "The correct suit is " << correctSuit << endl;
        }
    }
    
    else {
        // Guess both the value and the suit
        int guessedValue = GuessValue();
        string guessedSuit = GuessSuit();
        if (guessedSuit == correctSuit && guessedValue == correctValue) {
            cout << "Your guesses were both correct. Genius." << endl;
        }
        else if (guessedSuit != correctSuit && guessedValue == correctValue) {
            cout << "Value was correct, Suit was wrong." << endl;
        }
        else if (guessedSuit == correctSuit && guessedValue != correctValue) {
            cout << "Value was wrong, Suit was correct." << endl;
        }
        else {
            cout << "Both are wrong." << endl;
            cout << "The correct suit is " << correctSuit << endl;
            cout << "The correct number is " << correctValue << endl;
        }
    }
    cout << endl;
    cout << "Do you want to play the game again? Enter 0 to indicate yes, or anything else to exit game." << endl;
    int again;
    cin >> again;
    
    while (!cin) {
        // Restore input stream to working state
        cin.clear();
        // Get rid of any garbage that user might have entered
        cin.ignore ( 100 , '\n' );
        cout << "I said enter an integer, Dumbass. Try again: ";
        // After cin is restored and any garbage in the stream has been cleared, store user input in number again
        cin >> again;
    }
    
    if (!again) {
        main();
    }
    else {
        cout << "Exiting the game..." << endl;
        exit(0);
    }

    return 0;
}
