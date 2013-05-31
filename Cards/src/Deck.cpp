#include <iostream>

#include "Deck.h"

Deck::Deck() : mEnd( 0 ), mStart( 0 ), mNumCards( 0 )
{

}

Deck::Deck( uint32_t numCards ) : mEnd( 0 ), mStart( 0 ), mNumCards( numCards )
{
    for( uint32_t i = 0; i < numCards; i++ )
    {
        Card* card = new Card( i );
        push_back( card );
    }
}

Deck::~Deck()
{
    while( 0 != mStart )
    {
        Card* card = mStart;
        mStart = card->next;
        delete card;
    }
}

void Deck::Shuffle()
{
    Card* newEnd = 0;
    Card* newStart = 0;

    while( 0 != mStart )
    {
        Card* current = pop_front();
        if( 0 == newEnd )
        {
            newEnd = current;
        }
        current->next = newStart;
        current->prev = 0;
        newStart = current;

        // move top card to bottom of deck
        // only if there is still a top card
        if( 0 != mStart )
        {
            current = pop_front();
            push_back( current );
        }
    }
    mStart = newStart;
    mEnd = newEnd;
}

void Deck::ShowDeck()
{
    Card* card = mStart;
    while( 0 != card )
    {
        std::cout << card->value << " ";
        card = card->next;
    }
    std::cout << std::endl;
}

Card* Deck::pop_back()
{
    Card* card = mEnd;
    if( 0 != mEnd )
    {
        mEnd = mEnd->prev;
        mEnd->next = 0;
    }
    return card;
}

Card* Deck::pop_front()
{
    Card* card = mStart;
    if( 0 != mStart )
    {
        mStart = mStart->next;
        if( 0 != mStart )
        {
            mStart->prev = 0;
        }
    }
    return card;
}

Card* Deck::peek_back()
{
    return mEnd;
}

Card* Deck::peek_front()
{
    return mStart;
}

void Deck::push_back( Card* card )
{
    if( 0 != card )
    {
        if( 0 == mStart )
        {
            mStart = card;
        }

        if( 0 != mEnd )
        {
            mEnd->next = card;
        }
        card->prev = mEnd;
        card->next = 0;
        mEnd = card;
    }
}

void Deck::push_front( Card* card )
{
    if( 0 != card )
    {
        if( 0 == mEnd )
        {
            mEnd = card;
        }

        if( 0 != mStart )
        {
            mStart->prev = card;
        }
        card->next = mStart;
        card->prev = 0;
        mStart = card;
    }
}

bool Deck::operator==( Deck& other )
{
    bool retval = false;

    // A quick and easy check to see if the decks are equal,
    // Do they have the same number of cards?
    if( other.GetNumCards() == mNumCards )
    {
        // OK both decks have the same number of cards so now check the ordering
        retval = true;

        Card* otherCard = other.peek_front();
        Card* card = mStart;
        while( 0 != otherCard && 0 != card && retval )
        {
            retval &= ( otherCard->value == card->value );
            otherCard = otherCard->next;
            card = card->next;
        }
    }
    return retval;
}

bool Deck::operator!=( Deck& other )
{
    bool equal = this->operator ==( other );
    return !equal;
}

uint32_t Deck::GetNumCards()
{
    return mNumCards;
}
