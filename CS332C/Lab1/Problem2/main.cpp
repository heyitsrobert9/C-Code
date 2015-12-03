//
//  main.cpp
//  Problem2
//
//  Created by Rosas, Roberto C on 1/13/15.
//  Copyright (c) 2015 Rosas, Roberto C. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void winner(int, int);

int main(int argc, const char * argv[]) {
    int choice;
    int computer_choice;
    srand(time(NULL));
    computer_choice = rand() % 3 + 1;
    cout << " Welcome to Rock, Paper, Scissors \n";
    cout << " To pick Rock type 1, paper type 2, and scissors type 3 \n";
    cin >> choice;
    winner(choice, computer_choice);
    return 0;
}

void winner(int user, int computer){
    
    enum Choices {
        ROCK = 1,
        PAPER = 2,
        SCISSORS = 3,
    };
    
    if (user == computer)
    {
        cout << " You have tied \n";
    }
    
    else if(user == ROCK)
    {
        
        if(computer == PAPER)
        {
            cout << " Computer chose paper \n" << " So you lose because paper beats rock, sorry " << endl;
        }
        else if(computer == SCISSORS)
        {
            cout << " Computer chose scissors \n" << " So you win because rock beats scissors!!! " << endl;
        }
    }
    
    else if(user == PAPER)
    {
        
        if(computer == SCISSORS)
        {
            cout << " Computer chose scissors \n" << " So you lose because scissors beats paper, sorry " << endl;
        }
        else if(computer == ROCK)
        {
            cout << " Computer chose rock \n" << " So you win because paper beats rock!!! " << endl;
        }
    }
    
    else if(user == SCISSORS){
        
        if(computer == ROCK){
            cout << " Computer chose rock \n" << " You lose because rock beats scissors" << endl;
        }
        else if(computer == PAPER){
            cout << " Computer chose paper \n" << " You win because scissors beats paper" << endl;
        }
    }
    
}