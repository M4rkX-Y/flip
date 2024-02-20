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
            if (top == NULL)
            {
                bottom = top;
            }
        }
    }
}
deck::~deck()
{
    card *curr;
    while (top != NULL)
    {
        curr = top;
        top = top->getNext();
        delete curr;
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
    card *tmp_bottom;
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
        if (tmp_top == NULL)
        {
            tmp_bottom = tmp_top;
        }
        delete curr;
    }
    top = tmp_top;
    bottom = tmp_bottom;
}

card *deck::deal()
{
    card *curr = top;
    top = top->getNext();
    return curr;
}

void deck::replace(card &c)
{
    bottom->setNext(&c);
    bottom = &c;
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

void playFlip(deck &d)
{
    std::cout << "Welcome to the Game of Flip!" << std::endl;
    int i = 0;
    int points = 0;
    d.shuffle();
    std::cout << "Entire Deck After Shuffle: " << std::endl;
    std::cout << d << std::endl;
    while (i < 24)
    {
        int input;
        std::cout << "Flip (1) or End the Game (2): ";
        std::cin >> input;
        if (input == 1)
        {
            card *c = d.deal();
            int value = c->getValue();
            char suit = c->getSuit();
            std::cout << "Current hand card value : " << value << "  suit : " << suit << std::endl;
            if (value == 1)
            {
                points += 10;
            }
            if (value > 1 && value < 7)
            {
                points = 0;
            }
            if (value == 7)
            {
                points = points / 2;
            }
            if (value > 10)
            {
                points += 5;
            }
            if (suit == 'h')
            {
                points += 1;
            }
            std::cout << "Your total points: " << points << std::endl;
            std::cout << "You have " << 23 - i << "/24 cards left." << std::endl;
        }
        else if (input == 2)
        {
            break;
        }
        else
        {
            std::cout << "Invalid Input!" << std::endl;
            i--;
        }
        i++;
    }
    std::cout << "Game End!" << std::endl;
}