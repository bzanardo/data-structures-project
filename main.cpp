//  main.cpp
//  chess

#include <iostream>
#include <string>
#include <cctype>
#include "board.h"
using namespace std;

string get_turn(int);
bool valid_move(Board, int, int, int, int, int);
bool move_pawn(Board, int, int, int, int, int);

int main() {
    Board new_game;
    new_game.print();
    int player = 0;
    string turn;
    
    while (1) {
        turn = get_turn(player);
        if (valid_move(new_game, turn[0]-'0', turn[1]-'0', turn[2]-'0', turn[3]-'0', player)) { 
            new_game.make_move(turn[0]-'0', turn[1]-'0', turn[2]-'0', turn[3]-'0');
            cout << "Successful move" << endl;
        }
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

bool valid_move(Board b, int src_row, int src_col, int dest_row, int dest_col, int player) {
    char c = b.get_piece(src_row, src_col);
    player = player%2;
    if (player == 0) {       // White player
        if (isupper(c) == 0) {
            cout << "Invalid move." << endl;
            return false;
        }
    }
    if (player == 1) {      // Black player
        if (islower(c) == 0) {
            cout << "Invalid move." << endl;
            return false;
        }
    }

    if ( (c == 'p') || (c == 'P') ){
        if (move_pawn(b, src_row, src_col, dest_row, dest_col, player)) {
            return true;
        } else {
            cout << "Invalid move." << endl;
            return false;
        }
    }
    return true;
}

bool move_pawn(Board b, int src_row, int src_col, int dest_row, int dest_col, int player) {
    char c = b.get_piece(src_row, src_col);       // Piece to be moved
    char d = b.get_piece(dest_row, dest_col);
    if (player == 0) {      // White piece
        if ((dest_row == src_row - 1) && (src_col == dest_col)) {     // Moving one square forward
            if (d != ' ') {
                return false;
            } else {
                return true;
            }
        }
        if ((dest_row == src_row - 1) && (dest_col == (src_col + 1 || src_col - 1))) {   // Diagonal capture
            if (d == ' ') {     // No piece to be captured.
                return false;
            }
            if (islower(d) == 0) {
                return false;   // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
    }
    if (player == 1) {
        if ((dest_row == src_row + 1) && (src_col == dest_col)) {     // Moving one square forward
            if (d != ' ') {
                return false;
            } else {
                return true;
            }

        }
        if ((dest_row == src_row + 1) && (dest_col == (src_col + 1 || src_col - 1))) {   // Diagonal capture
            if (d == ' ') {     // No piece to be captured.
                return false;
            }
            if (isupper(d) == 0) {
                return false;   // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
    }
}
