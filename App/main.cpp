#include "Board.h"
#include <iostream>

using namespace std;

int main()
{
    Board board;
    char currentSymbol = 'X';
    int row, col;

    while (true)
    {
        board.display();
        cout << "Player " << currentSymbol << "'s turn, enter row col: ";
        cin >> row >> col;

        if (!board.placeMove(row, col, currentSymbol))
        {
            cout << "Invalid move\n";
            continue;
        }
        if (board.checkWin(row, col, currentSymbol))
        {
            board.display();
            cout << "Plauyer " << currentSymbol << " wins\n";
            break;
        }
        if (board.isFull())
        {
            board.display();
            break;
        }
        currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
    }
    return 0;
}