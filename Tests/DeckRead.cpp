#include "./Utils/Helpers.hpp"
#include "../include/Deck.hpp"
#include <cstdio>

void DeckReadTest_one () {
    TEST_INIT (1);
    FILE* f_in = fopen ("../Tests/DeckRead_test1.txt", "r");
    assert (f_in);

    Deck deck (0);
    deck.Read (9, f_in);
    deck.Print ();

    fclose (f_in);
    FAIL_IF (deck.Size() != 7);
}

void DeckReadTest_two () {
    TEST_INIT (1);
    FILE* f_in = fopen ("../Tests/DeckRead_test2.txt", "r");
    assert (f_in);

    Deck deck (0);
    deck.Read (9, f_in);
    deck.Print ();

    fclose (f_in);
    FAIL_IF (deck.Size() != 5);
}

void DeckReadTest_three () {
    TEST_INIT (1);
    FILE* f_in = fopen ("../Tests/DeckRead_test3.txt", "r");
    assert (f_in);

    Deck deck (0);
    deck.Read (14, f_in);
    deck.Print ();

    fclose (f_in);
    FAIL_IF (deck.Size() != 9);
}

int main () {
    setbuf (stdout, NULL);
    DeckReadTest_one ();
    DeckReadTest_two ();
    DeckReadTest_three ();
}