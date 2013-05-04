#ifndef DECK_H_
#define DECK_H_

#include <stdint.h>

// a structure to hold the card data.
struct Card
{
    Card* next;
    Card* prev;
    uint32_t value;
    Card( uint32_t inValue ) : next( 0 ), prev( 0 ), value( inValue ){};
};

class Deck
{
public:
    // Default constructor
    Deck();

    // Constructor: Creates a list representing a deck of cards
    //     Adding Cards to the deck with an increasing value
    // Input: Number of cards to add to the deck
    Deck( uint32_t numCards );

    // Desctructor
    virtual ~Deck();

    // Shuffle: Shuffles the deck of cards by taking the top card ( mStart ) and adding
    //     to the top of a new deck.
    //     The next card is then moved from the top of the original deck to the bottom.
    //     This is repeated untill all cards are moved to a new deck.
    // Input: None
    // Post Condition: The deck of cards has been shuffled one (1) round
    void Shuffle();

    // ShowDeck: Displays the current order of the cards in the deck
    // Input: None
    // PostCondition: None - the deck is in the original order
    void ShowDeck();

    // pop_back: Removes the card at the end of the deck and returns to caller.
    // Input: None
    // Post Condition: Last card is removed from deck and pointer is returned to the caller.
    Card* pop_back();

    // pop_front: Removes the card at the front of the deck and returns to caller.
    // Input: None
    // Post Condition: First card is removed from deck and pointer is returned to the caller.
    //     The mStart member pointer is updated to new start card.
    Card* pop_front();

    // peek_back: Returns a pointer to the card at the back of the deck.
    // Input: None
    // Post Condition: Last card pointer is returned to the caller.
    //     The deck is unchanged
    Card* peek_back();

    // peek_front: Returns a pointer to the card at the front of the deck.
    // Input: None
    // Post Condition: First card pointer is returned to the caller.
    //     The deck is unchanged
    Card* peek_front();

    // push_back: Addes a new card to the end of the deck.
    // Input: Pointer to a Card structure
    // Post Condition: Adds the card to the end of the deck, updating the mEnd pointer
    void push_back( Card* card );

    // push_front: Addes a new card to the front of the deck.
    // Input: Pointer to a Card structure
    // Post Condition: Adds the card to the front of the deck, updating the mStart pointer
    void push_front( Card* card );

    // Overloaded == Operator:
    // Input: Another instance of Deck
    // Post Condition: Returns a boolean TRUE if all the cards in both decks have the same values in the same order.
    //     FALSE otherwise
    bool operator==( Deck& other );

    // Overloaded != Operator:
    // Input: Another instance of Deck
    // Post Condition: Returns a boolean TRUE if all the cards in both decks do not have the same values in the same order.
    //     FALSE otherwise
    bool operator!=( Deck& other );

    // GetNumCards: Returns the number of cards on the deck;
    // Input: None
    // Post Condition: Returns the data member mNumCards
    uint32_t GetNumCards();

private:
    Card* mEnd;
    Card* mStart;
    uint32_t mNumCards;
};

#endif /* DECK_H_ */
