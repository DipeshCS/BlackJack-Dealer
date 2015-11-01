#ifndef TABLE_H
#define TABLE_H

#include <QDataStream>

class Player;

class Table
{
public:
    Table();
    int getCapacity();
    void setCapacity(int capacity_);
    QString getTableName();
    void setTableName(QString * tableName_);
    qint64 getPortNo();
    void setPortNo(qint64 portNo_);
    bool isWaitingForPlayer();
    void setWaitingForPlayer(bool wait);
    void addPlayerToTable(Player player);
    std::list< Player >::iterator playerListBegin();
    std::list< Player >::iterator playerListEnd();
private:
    int capacity;
    QString tableName;
    qint64 portNo;
    std::list< Player > connectedPalyer;
    bool waitForPalyer;

};
QDataStream & operator <<( QDataStream & stream, const Table &Table);
QDataStream & operator >>(QDataStream & stream, Table & Table);
#endif // Table_H
