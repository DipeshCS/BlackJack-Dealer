#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "QDataStream"

class Player
{
public:
    Player();
    Player(QString nick,bool isFold = false);
    void setUnique_num(int num);
    void addCardToHand(Card card);
    void setFoldTrue();
    bool isFold();
    std::vector<Card> * getCardHand();
    QString getName() const;



private:
    QString nick_name;
    int unique_num;
    std::vector<Card> hand;
    bool fold;
};

QDataStream & operator <<( QDataStream & stream, const Player &player);
QDataStream & operator >>(QDataStream & stream, Player &player);


#endif // PLAYER_H
