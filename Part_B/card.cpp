#include "card.h"

card::card(card &c)
{
    value = c.value;
    suit = c.suit;
    next = c.next;
}

void card::operator=(card &c)
{
    value = c.value;
    suit = c.suit;
    next = c.next;
}

void card::setValue(int v)
{
    value = v;
}

void card::setSuit(char s)
{
    suit = s;
}

void card::setNext(card *n)
{
    next = n;
}

int card::getValue()
{
    return value;
}

char card::getSuit()
{
    return suit;
}

card *card::getNext()
{
    return next;
}

std::ostream &operator<<(std::ostream &out, const card &c)
{
    out << "Card Value: " << c.value << " Suit: " << c.suit << std::endl;
    return out;
}
