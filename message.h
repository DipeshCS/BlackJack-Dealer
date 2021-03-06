#ifndef MESSAGE_H
#define MESSAGE_H
#include <vector>
#include <QDataStream>
#include <player.h>
#include "table.h"


enum class MessageType{
    GetTableDetails,
    TableDetails,
    JoinTable,
    LeaveTable,
    Message,
    ChekNickAvailability,
    NickAvailable,
    NickRegistered
};

QDataStream & operator <<( QDataStream & stream, const MessageType &type);
QDataStream & operator >>(QDataStream & stream, MessageType & types);


class Message
{
public:
    Message();

    MessageType getMessageType() const;
    void setMessageType(const MessageType &mtype);
    Message(MessageType type);
    std::vector<QString> getDataStrings() const;
    void insertDataString(const QString &string);
    std::vector<Player> getPlayerVector() const;
    void insertPlayerObj(const Player &player);
    std::vector<Table> getTableVector() const;
    void insertTableObj(const Table &table);


private:
    MessageType m_type;
    std::vector<QString> dataStrings;
    std::vector<Player> playerVector;
    std::vector<Table> tableVector;

};

QDataStream & operator <<( QDataStream & stream, const Message &message);
QDataStream & operator >>(QDataStream & stream, Message & message);
#endif // MESSAGE_H
