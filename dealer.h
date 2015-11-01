#ifndef DEALER_H
#define DEALER_H

#include "card.h"
#include <list>

class Dealer
{
public:
    Dealer();
    Card popRandomCard();


private:
    std::list<Card> cards;

};

#endif // DECK_H
