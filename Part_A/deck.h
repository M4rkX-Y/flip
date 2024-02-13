#ifndef deck_H
#define deck_H
#include "card.h"
class deck
{
public:
    deck();
    void addCard(int v, char s, card *h);
    void shuffle();
    friend std::ostream &operator<<(std::ostream &out, const deck &d);

private:
    card *top;
};

#endif