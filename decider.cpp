#include "decider.h"
#include "card.h"

Decider::Decider(){


}

static void Decider::gameDecider(Table *table)
{

        vector<Card> temp;
        vector<int> values;

        for(iterator<Player> it=table.connectedPalyer.begin();it!=table.connectedPalyer.end();it++){

            temp = *((*it).getCardHand());
            int value=0;
            for(iterator<Card> itcard=temp.begin();itcard!=temp.end();itcard++){
                value+=(*itcard).getValue();
            }
               values.push_back(value);
        }
         int ans=0,index=0;
        for(int i=1;i<=values.size();i++){

            if(a[i]<=21 && a[i]>ans){
                ans=a[i];
                index=i;
            }
        }
        for(int i=1;i<=values.size();i++){
            int count=0;
            if(a[i]==ans)count++;
            if(count>1)
            {qDebug<<'Match Draw.';
            break;}
        }

        qDebug<<"player "<< index << " won the game.";

    }


