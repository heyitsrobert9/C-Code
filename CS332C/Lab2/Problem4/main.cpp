//
//  main.cpp
//  Problem4
//
//  Created by Robert Rosas on 1/16/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void displayBoard();
void nextPlayer();
bool winner();

char player;
bool draw = false;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int main()
{
    cout << " Welcome To Tic Tac Toe " << endl;;
    cout << "X starts first, then O ";
    player = 'X';
    
    while (!winner())
    {
        displayBoard();
        nextPlayer();
        winner();
    }
    
    
    if (player == 'O' && !draw)
    {
        displayBoard();
        cout << endl << endl << "X Wins!" << endl;
    }
    else if (player == 'X' && !draw)
    {
        displayBoard();
        cout << endl << endl << "O Wins!" << endl;
    }
    else
    {
        displayBoard();
        cout << endl << endl << "It's a tie" << endl;
    }
}

void displayBoard()
{
    cout << "-----------------" << endl << endl;
    
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    
    cout << "_______________" << endl;
   
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    
    cout << "_______________" << endl;

    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
}

bool winner()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2])
            || (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            || (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            return true;
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
}


void nextPlayer()
{
    int choice;
    int row = 0;
    int column = 0;
    
    if (player == 'X')
    {
        cout << "Player 1 turn [X]: ";
    }
    else if (player == 'O')
    {
        cout << "Player 2 turn [O]: ";
    }
    cin >> choice;
    
    switch (choice)
    {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "You didn't enter a correct number! Try again\n";
            nextPlayer();
    }
    
    if (player == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        player = 'O';
    }
    else if (player == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        player = 'X';
    }
    else
    {
        cout << "That space has been used already";
        nextPlayer();
    }
    
}