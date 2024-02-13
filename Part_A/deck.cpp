#include "deck.h"
#include <ctime>

deck::deck()
{
    char suits[4] = {'c', 'd', 'h', 's'};
    top = NULL;
    for (int i = 4; i > 0; i--)
    {
        for (int j = 13; j > 0; j--)
        {
            addCard(j, suits[i - 1], top);
        }
    }
}

void deck::addCard(int v, char s, card *h)
{
    card *tmp = new card(v, s, h);
    top = tmp;
}

void deck::shuffle()
{
    srand(time(0));
    card *tmp_top = NULL;
    for (int i = 52; i > 0; i--)
    {
        card *curr = top;
        card *prev = NULL;
        int r = rand() % i;
        for (int j = 0; j < r; j++)
        {
            prev = curr;
            curr = curr->getNext();
        }
        if (prev == NULL)
        {
            top = top->getNext();
        }
        else
        {
            prev->setNext(curr->getNext());
        }
        card *tmp = new card(curr->getValue(), curr->getSuit(), tmp_top);
        tmp_top = tmp;
        delete curr;
    }
    top = tmp_top;
}

std::ostream &operator<<(std::ostream &out, const deck &d)
{
    card *curr = d.top;
    while (curr != NULL)
    {
        out << "Card Value: " << curr->getValue() << " Suit: " << curr->getSuit() << std::endl;
        curr = curr->getNext();
    }
    return out;
}
