#include "message.h"

Message::Message()
{

}

Message::Message(MessageType type){

    m_type = type;
}

void Message::setMessageType(const MessageType &mtype){
    m_type = mtype;
}

MessageType Message::getMessageType() const {
    return m_type;
}

std::vector<QString> Message::getDataStrings() const{
    return dataStrings;
}
std::vector<Player> Message::getPlayerVector() const{
    return playerVector;
}

void Message::insertDataString(const QString &string){

    dataStrings.push_back(string);
}

void Message::insertPlayerObj(const Player &player){

    playerVector.push_back(player);
}

std::vector<Table> Message::getTableVector() const{
    return tableVector;
}
void Message::insertTableObj(const Table &table){
    tableVector.push_back(table);
}

QDataStream & operator <<( QDataStream & stream, const MessageType &type){

    return stream <<(int) type;
}
QDataStream & operator >>(QDataStream & stream, MessageType & type){

    int enumVal;
    stream >> enumVal;
    type = MessageType(enumVal);
    return stream;
}

QDataStream & operator <<(QDataStream & stream, const Message &message){

    stream << message.getMessageType();

    std::vector<QString> dataStrings = message.getDataStrings();
    int dataStringsSize = dataStrings.size();
    stream << dataStringsSize;
    std::vector<Player> playerObjects = message.getPlayerVector();
    int playerVectorSize = playerObjects.size();
    stream << playerVectorSize;
    std::vector<Table> tableVector = message.getTableVector();
    int tableVectorSize = tableVector.size();
    stream << tableVectorSize;
    for( QString obj : dataStrings ){
        
        stream << obj;
    }

    /*for(Player player: playerObjects){
        stream<<player;

    }*/
    for(Table table: tableVector){
        stream << table;
    }
    return stream;
}

QDataStream &  operator >>(QDataStream & stream, Message &message){
    MessageType mtype;
    QString stringObj;
    Player playerObj;
    Table tableObj;
    int dataStringsSize;
    int playerVectorSize;
    int tableVectorSize;

    stream >> mtype;
    stream >> dataStringsSize;
    stream >> playerVectorSize;
    stream >> tableVectorSize;
    message.setMessageType(mtype);

    for(int i=0;i<dataStringsSize;i++){
        stream>>stringObj;
        message.insertDataString(stringObj);
    }
   /* for(int i=0;i<playerVectorSize; i++){
        stream>>playerObj;
        message.insertPlayerObj(playerObj);
    }*/
    for(int i=0;i<tableVectorSize; i++){
        stream >> tableObj;
        message.insertTableObj(tableObj);
    }
    return stream;
}

