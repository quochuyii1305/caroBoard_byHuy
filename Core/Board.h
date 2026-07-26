#pragma once
#include <iostream>

#define SIZE 10

using namespace std;

class Board
{
    private:
        char grid[SIZE][SIZE];
        // hàm đếm số quân liên tiếp theo 1 hướng
        int countDirection(int row, int col, int dx, int dy, char symbol) const;
    public:
        // constructor
        Board();
        void Reset();
        // kiem tra xem co di thanh cong khong
        bool isValidMove(int row, int col) const;
        // nuoc di cua player, row, col, X/O
        bool placeMove(int row, int col, char symbol);
        // kiem tra xem co 5 quan thang hang khong
        bool checkWin(int row, int col, char symbol) const;
        // kiem tra xem ban co full 100 o chua
        bool isFull() const;
        // hien thi ban co 
        void display() const;
};