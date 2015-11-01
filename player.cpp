#include "player.h"

Player::Player()
{

}

Player::Player(QString nick, bool isFold)
{
    nick_name = nick;
    fold = isFold;
}

void Player::setFoldTrue()
{
    fold = true;
}

bool Player::isFold()
{
    return fold;
}

void Player::setUnique_num(int num)
{
    unique_num = num;
}

void Player::addCardToHand(Card card)
{
    hand.push_back(card);
}

std::vector<Card> * Player::getCardHand()
{
    return &hand;
}

QString  Player::getName() const
{
    return  nick_name;
}

//QDataStream & operator << (QDataStream & stream, Player &player1){
//    stream << player1.setFoldTrue();
//    stream << player1.setUnique_num(num);
//    stream << player1.getName();

//    vector<Player> joinedPlayers;
//    for(std::list<Player>::iterator it=table.playerListBegin();it!=table.playerListEnd();it++){
//        joinedPlayers.push_back((*it));
//    }
//    int joinedPlayersSize = joinedPlayers.size();
//    stream << joinedPlayersSize;
//    for(std::vector<Player>::iterator player=joinedPlayers.begin();player!=joinedPlayers.end();player++){
//        stream << player;
//    }

//}
