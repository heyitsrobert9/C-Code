//
//  main.cpp
//  Problem3
//
//  Created by Rosas, Roberto C on 1/13/15.
//  Copyright (c) 2015 Rosas, Roberto C. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int rollDice();
int rollOrHold();
int replay()
;
int user(int userTotal);
int computer(int computerTotal);


int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    //int play;
    int userTotal = 0;
    int computerTotal = 0;
    int playGame;
    int replay();
    
   
        cout << " Welcome to the Dice game \n";
        cout << " Would you like to play Yes (1) or No(2)";
        cin >> playGame;
        
    do{
        if (playGame == '2')
        {
            cout << " You have chose not to play, good bye. " << endl;
            break;
        }
    }while(playGame != 1);
        
  
    
    do{
    
        do
        {
            
            cout << " Your total score = " << userTotal
            << "\n Computer's total score = " << computerTotal << endl;
            
            if (computerTotal < 100)
                userTotal = user(userTotal);
            
            if (userTotal < 100)
                computerTotal = computer(computerTotal);
            
        }while (userTotal < 100  && computerTotal < 100);
        
        if (userTotal >= 100 && computerTotal <= 99)
        {
            cout << " \n\n You win! " << endl;
        }
        
        if (userTotal <= 99 && computerTotal >= 100)
        {
            cout << " \n\n Sorry you lost... " << endl;
        }
        
        playGame = replay();
        if ( playGame == '2')
        {
            cout << " Okay see you later :) " << endl;
        }
        
        userTotal = 0;
        computerTotal = 0;
        
    } while (playGame != '2');
}


int rollDice()
{
    return rand() % 6 + 1;
}

int rollOrHold()
{
    int roll_choice;
    cout << " Would you like to Roll(1) or Hold (0): ";
    cin >> roll_choice;
    return roll_choice;
}

int replay()
{
    int play_choice;
    cout << "Would you like to play again? Yes (1) or No(2)";
    cin >> play_choice;
    return play_choice;
}

int user(int userTotal)
{
    int userCurrentScore = 0;
    int rollDice();
    int choice;
    
    
    do
    {
        choice = '1';
        int rollDice();
        int user = rollDice();
        cout << " You rolled a " << user << endl;
        
        if (user == 1)
        {
            cout <<  " You rolled a one so you lost all your points " << endl;
            userCurrentScore = 0;
            break;
        }
        
        else
        {
            userCurrentScore += user;
            cout << " Your current total : " << userCurrentScore << endl << endl;
            userTotal += userCurrentScore;
            choice = rollOrHold();
            
            if (choice == '0')
            {
                userTotal += userCurrentScore;
                cout << " Your total score : " << userTotal << endl;
                break;
            }
        }
    } while (choice == '1');
    return userTotal;
}

int computer(int computerTotal)
{
    int computerCurrentScore = 0;
    
    do
    {
        int ComputerRoll = rollDice();
        cout << "Computer rolled a " << ComputerRoll << endl;
        
        if (ComputerRoll == 1)
        {
            cout <<  " Computer rolled a 1 so no points were gained " << endl;
            computerCurrentScore = 0;
            break;
        }
        else
        {
            computerCurrentScore += ComputerRoll;
            if (computerCurrentScore >= 20)
            {
                computerTotal += computerCurrentScore;
                cout << " Computer's current total is " << computerCurrentScore << endl << endl;
                cout << " Computer held. Computer's total score: " << computerTotal << endl << endl;
            }
        }
    }while (computerTotal <= 19);
    
    
    
    return computerTotal;
    
}

