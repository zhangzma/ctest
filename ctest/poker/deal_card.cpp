// copyright (c) www.eva-tec.cn
// @file deal_card.cpp
#include "player.h"
#include <cstdlib>
#include <ctime>

using namespace std;
const int PLAYER_NUM = 4;
const int CARDS_NUM  = 52;

void init_cards_status(bool cards[], int num);
int  get_random_card(bool cards[]);
bool all_dealed(bool cards[], int num);

int main(int argc, char *argv[])
{
    CPlayer players[PLAYER_NUM]; // players
    bool  cards[CARDS_NUM];      // cards status
    init_cards_status(cards, CARDS_NUM);

    for (int i=0; i<CARDS_NUM; i++) {
        int cardNum = get_random_card(cards);
        CPoker *ppk = new CPoker(cardNum+1);
        // std::cout << cardNum << " ";
        // players[i%4].add_poker(ppk);
    }

    std::cout << "==========" << std::endl;
    for (int i=0; i<PLAYER_NUM; i++) {
        std::cout << "\nThe Player #" << i
                  << "'s cards is :" << std::endl;
        players[i].displayer_all_poker();
    }


    return 0;
}

/**
 * 初始化扑克状态
 */
void init_cards_status(bool cards[], int num)
{
    for (int i=0; i<num; i++) {
        cards[i] = false;
    }
    srand(time(NULL));
}

/**
 * 随机获取一张牌，当无牌可发的时候返回0
 */
int get_random_card(bool cards[])                                                             
{
    if (all_dealed(cards, CARDS_NUM))
    {
        return -1;
    }

    int cardNum = rand() % CARDS_NUM;
    if (!cards[cardNum])
    {
        cards[cardNum] = true;
        return cardNum;
    }
    else
    {
        return get_random_card(cards);
    }
}

/**
 * 判断所有的牌都发完了
 */
bool all_dealed(bool cards[], int num)
{
    bool allDealed = true;
    for (int i=0; i<num; i++) {
        allDealed &= cards[i];
    }

    return allDealed;
}
