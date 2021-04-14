#include "../include/MoveChains.hpp"


void MoveChains (std::vector<Deck>& decks) {
    std::pair<int, int> best_move = GetBestMove (decks);
    Chain chain_to_move = decks[best_move.first].PopChain ();
    decks[best_move.second].PushChain (chain_to_move);
}


std::pair<int, int> GetBestMove (std::vector<Deck>& decks) {
    std::pair<int, int> best_move (-1, -1);
    int best_sum = -1;

    for (size_t i = 0; i < decks.size() - 1; ++i) {
        for (size_t j = i + 1; j < decks.size (); ++j) {
            Chain first  = decks[i].Top ();
            Chain second = decks[j].Top ();
            int cur_sum = 0;
            std::pair<int, int> cur_move (-1, -1);
            if (second.top + 1 == first.bottom) {
                cur_move = {i, j};
                cur_sum  = second.top + first.bottom;
            }
            if (first.top + 1 == second.bottom) {
                cur_move = {j, i};
                cur_sum  = first.top + second.bottom;
            }

            if (cur_move != std::make_pair (-1, -1)) {
                if (best_move == std::make_pair (-1, -1)) {
                    best_move = cur_move;
                    best_sum  = cur_sum;
                } else if (cur_sum < best_sum) {
                    best_move = cur_move;
                    best_sum = cur_sum;
                }
            }
        }
    }

    return best_move;
}
