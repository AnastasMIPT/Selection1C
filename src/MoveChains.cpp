#include "../include/MoveChains.hpp"


void MoveChains (std::vector<Deck>& decks) {
    std::pair<int, int> best_move = GetBestMove (decks);
    Chain chain_to_move = decks[best_move.first].PopChain ();
    decks[best_move.second].PushChain (chain_to_move);
}


std::pair<int, int> GetBestMove (std::vector<Deck>& decks) {
    std::pair<int, int> best_move (-1, -1);

    for (size_t i = 0; i < decks.size() - 1; ++i) {
        for (size_t j = i + 1; j < decks.size (); ++j) {
            Chain first  = decks[i].Top ();
            Chain second = decks[j].Top ();
            std::pair<int, int> cur_move (-1, -1);
            if (second.top + 1 == first.bottom) {
                cur_move = {i, j};
            }
            if (first.top + 1 == second.bottom) {
                cur_move = {j, i};
            }

            if (cur_move != std::make_pair (-1, -1)) {
                if (best_move == std::make_pair (-1, -1)) {
                    best_move = cur_move;
                } else if (cur_move.first + cur_move.second < best_move.first + best_move.second) {
                    best_move = cur_move;
                }
            }
        }
    }

    return best_move;
}
