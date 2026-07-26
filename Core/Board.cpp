#include "Board.h"

Board::Board()
{
    Reset();
}

void Board::Reset()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            grid[i][j] = ' ';
        }
    }
}

bool Board::isValidMove(int row, int col) const
{
    if (row < 0 || col < 0 || row > SIZE || col > SIZE)
    {
        return false;
    }
    return true;
}

bool Board::placeMove(int row, int col, char symbol)
{
    // nếu không tồn tại nước đi có row va column
    if (!isValidMove(row, col))
    {
        return false;
    }
    grid[row][col] = symbol;
    return true;
}
// dem so quan lien tiep
int Board::countDirection(int row, int col, int dx, int dy, char symbol) const
{
    int count = 0;
    int r = row + dx; // r: tọa độ hàng của ô đang xét, bắt đầu bằng ô kế bên + dx
    int c = col + dy; // c: tọa độ cột của ô đang xét
    while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && grid[r][c] == symbol)
    {
        count++;
        r = r + dx;
        c = c + dy;
    }
    return count;
}

// kiem tra chien thang
bool Board::checkWin(int row, int col, char symbol) const
{
    // (0,1) truc ngang  trai phai
    // (1,0) truc doc tren duoi
    // (1,1) truc cheo chinh
    // (1,-1) truc cheo phu
    int directions[4][2] = {
        {0, 1},
        {1, 0},
        {1, 1},
        {1, -1}};
    // duyet qua 4 huong can kiem tra
    for (int i = 0; i < 4; i++)
    {
        int dx = directions[i][0]; // thay doi cua row
        int dy = directions[i][1]; // thay doi cua col

        int total = 1;                                       // tong so quan lien tiep tren truc nay, bat dau = 1
        total += countDirection(row, col, dx, dy, symbol);   // cong them so quan ve 1 phia cua truc
        total += countDirection(row, col, -dx, -dy, symbol); //
        if (total >= 5)
        {
            return true;
        }
    }
    return false;
}

// kiem tra toan bo ban co full chua
bool Board::isFull() const
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
// in ra console
void Board::display() const
{
    cout << "   ";
    for (int j = 0; j < SIZE; j++) // j: chi so cot, in tieu de cot tren cung
        cout << j << "   ";
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    { // i: chi so hang dang in
        cout << "  |";
        for (int j = 0; j < SIZE; j++) // ve dong ke ngan cach phia tren moi hang
            cout << "---|";
        cout << endl;

        cout << i << " |";             // in so thu tu hang o dau dong
        for (int j = 0; j < SIZE; j++) // j: chi so cot, in noi dung tung o trong hang i
            cout << " " << grid[i][j] << " |";
        cout << endl;
    }
    cout << "  |";
    for (int j = 0; j < SIZE; j++) // dong ke ngan cach cuoi cung
        cout << "---|";
    cout << endl;
}