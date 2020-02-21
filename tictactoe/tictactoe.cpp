// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printBoard(vector<char>& board) {
    // Clear screen
    system("cls");
    // Header
    cout << "\tTic Tac Toe!" << endl;

    // The board
    cout << "   |   |   " << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "   |   |   " << endl;
}

int checkWin(vector<char>& board) {
    char winnerMark = NULL;
    bool boardFilled = true; // Assume board is filled
    // Horizontal lines
    if ((board[0] & board[1]) == board[2]) {
        winnerMark = board[0];
    }
    else if ((board[3] & board[4]) == board[5]) {
        winnerMark = board[3];
    }
    else if ((board[6] & board[7]) == board[8]) {
        winnerMark = board[6];
    }
    else if ((board[0] & board[3]) == board[6]) {
        winnerMark = board[0];
    }
    else if ((board[1] & board[4]) == board[7]) {
        winnerMark = board[1];
    }
    else if ((board[2] & board[5]) == board[8]) {
        winnerMark = board[2];
    }
    else if ((board[0] & board[4]) == board[8]) {
        winnerMark = board[0];
    }
    else if ((board[2] & board[4]) == board[6]) {
        winnerMark = board[2];
    }

    for (int i = 0; i < board.size(); i++) {
        if (board[i] != 'X' & board[i] != 'O') {
            // If there's no mark at any square board is not filled
            boardFilled = false;
        }
    }

    if (winnerMark != NULL) {
        return (winnerMark == 'X') ? 1 : 2;
    }
    else if (boardFilled) {
        return -1; // Draw
    }
    return 0;
}

int main()
{
    vector<char> b = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    
    int player = 1;
    char mark;
    int winner = 0;

    do
    {
        printBoard(b);

        mark = (player == 1) ? 'X' : 'O';

        int roundOver = 0; // 0 = round not over 1 = round over
        do
        {
            cout << "Your move Player" << player << ", enter a number: ";
            char choice;
            cin >> choice;

            if (choice >= '1' && choice <= '9') {
                if (b[(choice - '0') - 1] == choice) {
                    b[(choice - '0') - 1] = mark;
                    roundOver++;
                }
                else
                {
                    cout << "\nThis square is alredy marked\n";
                }
            }
            else
            {
                cout << "\nSquare " << choice << " Does not exist\n";
            }
        } while (roundOver == 0);

        winner = checkWin(b);
        player = (player == 1) ? 2 : 1;

    } while (winner == 0);

    printBoard(b);
    if (winner > 0) {
        cout << "Player " << winner << " Won" << endl;
    }
    else {
        cout << "Draw";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
