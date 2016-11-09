// Copyright (c) www.eva-tec.cn
// nplace.cc
// The detect the mine game
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;
void initlialize_gameboard(char **&pg, int width, int length);
void generate_landmine(char **pg, int width, int length, int mineCount);
void gameboard_status(char **pg, int width, int length);

int main(int argc, char *argv[])
{
    int width, length;
    int count;
    cout << "Please input the width and length of PLACE: ";
    cin >> width >> length;
    cout << "Please input the landmine COUNT: ";
    cin >> count;

    if (width > length)
    {
        int tmp = width;
        width = length;
        length = tmp;
    }
    

    char ** pgameboard = NULL;
    // char pgameboard[width][length];
    initlialize_gameboard(pgameboard, width, length);
    generate_landmine(pgameboard, width, length, count);
    gameboard_status(pgameboard, width, length);

    for (int i = 0; i < width; i++) {
        delete[] pgameboard[i];
    }
    delete[] pgameboard;

     return 0;
}

// 初始化面板
void initlialize_gameboard(char **&pg, int width, int length)
{
    pg = new char*[width];
    for (int i = 0; i < width; i++) {
        pg[i] = new char[length];
    }

   for (int row = 0; row < width; row++) {
       for (int col = 0; col < length; col++) {
           pg[row][col] = '_';
       }
   }

   srand(time(NULL));
   // cout << "init ok. " << endl;
}

void generate_mine(int width, int length, int &row, int &col)
{
    row = rand() % width;
    col = rand() % length;

    // cout << "row = " << row
    //      << "col = " << col << endl;
}

void generate_landmine(char **pg, int width, int length, int mineCount)
{
    for (int i = 0; i < mineCount; i++) {
        int row, col;
        generate_mine(width, length, row, col);
        if (pg[row][col] != '*')
        {
            pg[row][col] = '*';
        }
        else
        {
            i--;
        }
    }

    // cout << "landmine ok." << endl;
}

// 指定位置是否合法
bool is_valid(int width, int length, int r, int c)
{
    return (r >=0 && c >= 0 && r < width && c < length);
}

// 判断当前位置是否是地雷
bool is_mine(char **pg, int w, int l, int r, int c)
{
    if (is_valid(w, l, r, c) && pg[r][c] == '*')
    {
        return true;
    }

    return false;
}

// 获取指定位置周围雷的个数
int get_mine_count(char **pg, int w, int l, int r, int c)
{
    const int NEIGHBOUR_COUNT = 8;
    int neighbour[8][2] =
        { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };

    int count = -1;
    if (is_mine(pg, w, l, r, c)) {
        return count;
    }

    count = 0;
    for (int i = 0 ; i < NEIGHBOUR_COUNT; i++) {
        int nr = r + neighbour[i][0];
        int nc = c + neighbour[i][1];
        if (is_mine(pg, w, l, nr, nc)) {
            count++;
        }
    }

    return count;
}

// 检测游戏面板
void detect_game_board(char **pg, int width, int length)
{
    for (int row=0; row<width; row++) {
        for (int col=0; col<length; col++) {
            int count = get_mine_count(pg, width, length, row, col);
            if (count != -1 && count != 0) {
                pg[row][col] = '0' + count;
            }
        }
    }
}

// 打印雷区状态
void gameboard_status(char **pg, int width, int length)
{
    detect_game_board(pg, width, length);

    cout << "Current Game board:" << endl;
    for (int row = 0; row < width; row++) {
       for (int col = 0; col < length; col++) {
           printf("%c", pg[row][col]);
       }
       printf("\n");
   }

    // cout << "print ok." << endl;
}

