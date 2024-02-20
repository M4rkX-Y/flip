#ifndef deck_H
#define deck_H
#include "card.h"
class deck
{
public:
    deck();
    ~deck();
    void addCard(int v, char s, card *h);
    void shuffle();
    card *deal();
    void replace(card &c);
    friend std::ostream &operator<<(std::ostream &out, const deck &d);

private:
    card *top;
    card *bottom;
};

void playFlip(deck &d);

#endif