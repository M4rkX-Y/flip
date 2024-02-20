#ifndef card_H
#define card_H
#include <iostream>
class card
{
public:
    card(int v = 0, char s = 's', card *n = NULL) : value(v), suit(s), next(n) {}
    card(card &c);
    void setValue(int v);
    void setSuit(char s);
    void setNext(card *n);
    int getValue();
    char getSuit();
    card *getNext();
    friend std::ostream &operator<<(std::ostream &out, const card &c);
    void operator=(card &c);

private:
    int value;
    char suit;
    card *next;
};

#endif