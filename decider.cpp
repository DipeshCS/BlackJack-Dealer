#include "decider.h"
#include "card.h"
#include "table.h"


void Decider::gameDecider(Table *table)
{

        std::vector<Card> temp;
        std::vector<int> values;

        for(std::list<Player>::iterator it=table->playerListBegin();it!=table->playerListEnd();it++){

            temp = *((*it).getCardHand());
            int value=0;
            for(std::vector<Card>::iterator itcard=temp.begin();itcard!=temp.end();itcard++){
                value+=(*itcard).getValue();
            }
               values.push_back(value);
        }
         int ans=0,index=0;
        for(int i=1;i<=values.size();i++){

            if(values[i]<=21 && values[i]>ans){
                ans=values[i];
                index=i;
            }
        }
        for(int i=1;i<=values.size();i++){
            int count=0;
            if(values[i]==ans)count++;
            if(count>1)
            {qDebug()<<'Match Draw.';
            break;}
        }

        qDebug()<<"player "<< index << " won the game.";
    }


