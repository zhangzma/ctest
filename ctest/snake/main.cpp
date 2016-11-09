// main.cc
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "game_board.h"


using namespace std;

const int ROW = 20;
const int COL = 60;

void clear_screen()
{
    system("cls");
}

void display(char (*start)[COL], int row, int col = COL)
{
    char *line;
    for (int i=0; i<row; i++) {
        line = *(start + i);
        // std::cout << line << std::endl;
        printf("%s\n", line);
    }
}

void display(char (*start)[2])
{
    std::cout << *(*(start) + 1) << std::endl;
}

int main(int argc, char *argv[])
{
    CGameBoard game(COL, ROW);
    clear_screen();
    game.create_a_apple();
    game.create_a_apple();
    game.display();

    // unsigned int counter = 0;
    // char play[10][COL];
    // for (int row=0; row<10; row++) {
    //     for (int col=0; col<COL; col++) {
    //         play[row][col] = 'a';
    //     }
    //     play[row][COL-1] = '\0';
    // }
    // std::cout << play[0] << std::endl;
    // // display(play);
    
    // while (true) {
    //     counter++;
    //     clear_screen();
    //     std::cout << counter << std::endl;
    //     display(&play[0], 10 , COL);
    //     // for (int i=0; i<counter; i++) {
    //     //     std::cout << "*";
    //     // }
    //     std::cout << std::endl;

        
    //     // 每秒刷新一次
    //     static time_t tm = time(NULL);
    //     while (tm == time(NULL));
    //     tm = time(NULL);
    // }
    
    return 0;
}

