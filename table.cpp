#include "table.h"
#include "player.h"
#include "QDataStream"

Table::Table()
{

}

int Table:: getCapacity()
{
    return capacity;
}

void Table:: setCapacity(int capacity_)
{
    capacity = capacity_;
}

QString Table::getTableName()
{
    return tableName;
}

void Table::setTableName(QString *tableName_)
{
    tableName = *tableName_;
}

qint64 Table::getPortNo()
{
    return portNo;
}

void Table::setPortNo(qint64 portNo_)
{
    portNo = portNo_;
}

bool Table::isWaitingForPlayer()
{
    return waitForPalyer;
}

void Table::setWaitingForPlayer(bool wait)
{
    waitForPalyer = wait;
}

void Table::addPlayerToTable(Player player)
{
    connectedPalyer.push_back(player);
}

std::list< Player >::iterator Table::playerListBegin()
{
    return connectedPalyer.begin();
}

std::list< Player >::iterator Table::playerListEnd()
{
    return connectedPalyer.end();
}


QDataStream & operator << (QDataStream & stream, Table &table){
    stream << table.getTableName();
    stream << table.getCapacity();
    stream << table.getPortNo();
    vector<Player> joinedPlayers;
    for(std::list<Player>::iterator it=table.playerListBegin();it!=table.playerListEnd();it++){
        joinedPlayers.push_back((*it));
    }
    int joinedPlayersSize = joinedPlayers.size();
    stream << joinedPlayersSize;
   /* for(std::vector<Player>::iterator player=joinedPlayers.begin();player!=joinedPlayers.end();player++){
        stream << player;
    }*/
    for(Player player1: table.connectedPalyer){
        stream<<player1;
    }

}
QDataStream & operator >>(QDataStream & stream, Table &table){
    QString tableName;
    QString tableCap;
    int tablePort;
    int joinedPlayerSize;
    stream >> tableName;
    table.setTableName(&tableName);
    stream >> tableCap;
    table.setCapacity(tableCap.toInt());
    stream >> tablePort;
    table.setPortNo(tablePort);

    stream >> joinedNickSize;
    Player playerObj;
    for(int i=0;i<joinedPlayerSize;i++){
        stream >> playerObj;
        table.addPlayerToTable(playerObj);
    }
}
