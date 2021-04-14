#include "../include/Deck.hpp"

size_t Deck::Size () {
    return body.size ();
}

void Deck::Read (size_t cards_num, FILE* f_in) {
    int cur_card = 0;
    Chain cur_chain = {deck_no, -2, -2};
    for (size_t i = 0; i < cards_num; ++i) {
        fscanf (f_in, "%d", &cur_card);
        printf ("i = %lu\n", i);

        printf ("cur_card = %d, cur_chaintop = %d\n", cur_card, cur_chain.top);
        if (cur_card == cur_chain.top + 1) {
            printf ("Eeeee\n");
            cur_chain.top = cur_card;
        } else if (!(cur_chain.bottom == -2 && cur_chain.top == -2)) {
            printf ("pushed cur_chaintop = %d %d\n", cur_chain.top, cur_chain.bottom);       
            body.push_back (Chain (cur_chain));
            cur_chain = {deck_no, -2, -2};
        } 

        if (cur_chain.bottom == -2 && cur_chain.top == -2) {
            cur_chain.bottom = cur_card;
            cur_chain.top = cur_card;
            printf ("new\n");
        }
    }
    if (cards_num > 0) body.push_back (Chain (cur_chain));
}

void Deck::Print (FILE* f_out) {
    fprintf (f_out, "deck_no = %d\n", deck_no);
    for (size_t i = 0; i < body.size(); ++i) {
        fprintf (f_out, "i = %lu, bot = %d, top = %d\n", i, body[i].bottom, body[i].top);
    }
}
