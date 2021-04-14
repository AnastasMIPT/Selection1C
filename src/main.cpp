#include <cstdio>
#include <stack>
#include <vector>
#include "../include/Deck.hpp"
#include "../include/MoveChains.hpp"
#include "../include/DecksCompleted.hpp"


constexpr int DeckNum = 8;
constexpr int NumCardsInDeck = 9;
constexpr int LoopIterations = 20;

int main () {


   std::vector<Deck> decks;

    for (int i = 0; i < DeckNum; ++i) {
        decks.push_back (Deck (i));
    }

    for (int i = 0; i < DeckNum; ++i) {
        decks[i].Read (NumCardsInDeck);
    }

    

    bool possible = false;

    while (true) {
        MoveChains (decks);
        if (DecksCompleted (decks)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        printf ("Yes\n");
    } else {
        printf ("No\n");
    }
}
