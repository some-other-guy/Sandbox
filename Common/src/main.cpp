#include <time.h>
#include <cstdlib>
#include <iostream>

#include "Deck.h"

#define DEBUG
#undef DEBUG

// Default maximum number of re-shuffles to attempt to get the deck back to original order.
static const uint32_t MAX_RESHUFFLES( 100000 );

// Main entry point of the program
// Usage: shuffle <number of cards> [maximum shuffle attempts]
//   number of cards: The number of cards that will be added to a Deck of cards and shuffled
//   maximum shuffle attempts: Optional maximum number of times we will try to re-shuffle the deck
//     If this argument is supplied it will override the MAX_RESHUFFLES number above.
int main( int argc, char* argv[] )
{
    if( 2 <= argc )
    {
        uint32_t numCards = strtoul( argv[1], NULL, 10 );

        // create 2 decks that are initialized to the same card ordering.
        // the referenceDeck will be used to compare so we know when we are back at the original
        // ordering.
        Deck deck( numCards );
        Deck referenceDeck( numCards );

        uint32_t numShuffles = 0;
        uint32_t maxReshuffles = MAX_RESHUFFLES;

        if( 2 < argc )
        {
            maxReshuffles = strtoul( argv[2], NULL, 10 );
        }

        std::cout << "Shuffling deck with " << numCards << " cards ... ";
#ifdef DEBUG
        std::cout << std::endl;
        deck.ShowDeck();
#endif
        do
        {
            deck.Shuffle();
            numShuffles++;
#ifdef DEBUG
            deck.ShowDeck();
#endif

        } while( deck != referenceDeck && maxReshuffles > numShuffles );
        // some numbers of cards take a LONG time to re-shuffle.
        // so if numShuffles get to maxReshuffles end the loop, so we don't sit here forever.

        if( maxReshuffles == numShuffles )
        {
            std::cout << "Still not back to original order after " << numShuffles << " re-shuffles, giving up" << std::endl;
        }
        else
        {
            std::cout << "Finished: Re-shuffles needed to get back to original order: " << numShuffles << std::endl;
        }
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " <number of cards in deck> [ <maximum re-shuffle attempts> ]" << std::endl;
    }
    return 0;
}
