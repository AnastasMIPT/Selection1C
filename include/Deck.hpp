#include "Chain.hpp"
#include <vector>
#include <cstdio>
#include <cstdlib>

class Deck {
public:
    Deck (int deck_no) : deck_no (deck_no) {}
    void PushChain (const Chain chain);
    Chain PopChain ();
    Chain Top();
    void Read(size_t cards_num, FILE* f_in = stdin);
    void Print (FILE* f_out = stdout);
    size_t Size ();

private:
    int deck_no;
    size_t deck_size = 0;
    std::vector<Chain> body;
};


