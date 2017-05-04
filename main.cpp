//  main.cpp
//  chess

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include "board.h"
#include "movement.h"
#include "promotion.h"
using namespace std;

string get_turn(int);
bool valid_move(Board, string&, int);

int main() {
    Board new_game;
    new_game.print();
    int player = 0;
    string turn;
    char piece;
    
    while (1) {
        turn = get_turn(player);
        if (valid_move(new_game, turn, player)) {
	    if (can_promote(new_game, turn, player)) {
		cout << "\nPawn promtion available. What piece would you like to add? ";
		cin >> piece;
		// ensure correct case for new piece
		if (player%2 == 0)
			piece = toupper(piece);	
		else
			piece = tolower(piece);

		make_promotion(new_game, turn, piece);
	    }
            new_game.make_move(turn);
	    system("clear");
        } else {
            continue;
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

bool valid_move(Board b, string &turn, int player) {
    int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
    player = player%2;
    if ( (src_row < 0) || (src_col > 7) ) {
        cout << "Out of range." << endl;
        return false;
    }
    if ( (src_col < 0) || (src_col > 7)) {
        cout << "Out of range." << endl;
        return false;
    }
    if ( (dest_row < 0) || (dest_row > 7)) {
        cout << "Out of range." << endl;
        return false;
    }
    if ( (dest_col < 0) || (dest_col > 7)) {
        cout << "Out of range." << endl;
        return false;
    }

    char c = b.get_piece(src_row, src_col);

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

    if ( (c == 'p') || (c == 'P') ) {       // Pawn
        if (move_pawn(b, turn, player)) {
            return true;
        } else {
            cout << "Invalid move." << endl;
            return false;
        }
    }
    if ( (c == 'n') || (c == 'N') ) {
        if (move_knight(b, turn, player)) {
            return true;
        } else {
            cout << "Invalid move." << endl;
            return false;
        }
    }
    if ( (c == 'r') || (c == 'R') ) {
        if (move_rook(b, turn, player)) {
            return true;
        } else {
            cout << "Invalid move." << endl;
            return false;
        }
    }
    if ( (c == 'b') || (c == 'B') ) {
        if (move_bishop(b, turn, player)) {
            return true;
        } else {
            cout << "Invalid move." << endl;
            return false;
        }
    }

    if ( (c == 'q') || (c == 'Q') ) {
        if (move_queen(b, turn, player)) {
            return true;
        } else {
            cout << "Invalid move." << endl;
            return false;
        }
    }

    if ( (c == 'k') || (c == 'K') ) {
        if (move_king(b, turn, player)) {
            return true;
        } else {
            cout << "Invalid move." << endl;
            return false;
        }
    }
    return true;
}
