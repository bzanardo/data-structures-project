//  main.cpp
//  chess

#include <iostream>
#include <string>
#include "board.h"
using namespace std;

string get_turn(int);

int main() {
    Board new_game;
    new_game.print();
    int player = 0;
    string turn;
    
    while (1) {
        turn = get_turn(player);
        new_game.make_move(turn[0]-'0', turn[1]-'0', turn[2]-'0', turn[3]-'0');
        new_game.print();
        player++;
    }
}

string get_turn(int player) {
    string turn;
    player = player%2;
    
    switch (player) {
        case 0:
            cout << endl;
            cout << "WHITE: ";
            break;
        case 1:
            cout << endl;
            cout << "BLACK: ";
            break;
    }
    cin >> turn;
    
    return turn;
}
