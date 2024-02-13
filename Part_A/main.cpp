#include "deck.h"
#include <iostream>

int main()
{
    deck d;
    std::cout << "Initiation: " << std::endl;
    std::cout << d << std::endl;
    d.shuffle();
    std::cout << "After Shuffle: " << std::endl;
    std::cout << d;
    return 0;
}