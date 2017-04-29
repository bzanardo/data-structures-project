//  main.cpp
//  chess

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "board.h"
using namespace std;

string get_turn(int);
bool valid_move(Board, string&, int);
bool move_pawn(Board, string&, int);
bool move_knight(Board, string&, int);
bool move_rook(Board, string&, int);
bool move_bishop(Board, string&, int);
bool move_queen(Board, string&, int);
bool move_king(Board, string&, int);

int main() {
    Board new_game;
    new_game.print();
    int player = 0;
    string turn;
    
    while (1) {
        turn = get_turn(player);
        if (valid_move(new_game, turn, player)) { 
            new_game.make_move(turn);
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
    char c = b.get_piece(src_row, src_col);
    player = player%2;
    if ( (src_row < 0) || (src_row > 7)) {
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

bool move_pawn(Board b, string &turn, int player) {
    int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
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

bool move_knight(Board b, string &turn, int player) {
    int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
    char c = b.get_piece(src_row, src_col);       // Piece to be moved
    char d = b.get_piece(dest_row, dest_col);
    if (player == 0) {    // White player.
        if ( (d != ' ') && (islower(d) == 0) ) {
            return false;
        }
    }
    if (player == 1) {    // Black player.
        if ( (d != ' ') && (isupper(d) == 0) ) {
            return false;
        }
    }

    if ( (dest_row = src_row + 1) && (dest_col = src_col + 2) ) {
        return true;
    }
    if ( (dest_row = src_row + 1) && (dest_col = src_col - 2) ) {
        return true;
    }
    if ( (dest_row = src_row + 2) && (dest_col = src_col + 1) ) {
        return true;
    }
    if ( (dest_row = src_row + 2) && (dest_col = src_col - 1) ) {
        return true;
    }
    if ( (dest_row = src_row - 1) && (dest_col = src_col + 2) ) {
        return true;
    }
    if ( (dest_row = src_row - 1) && (dest_col = src_col - 2) ) {
        return true;
    }
    if ( (dest_row = src_row - 2) && (dest_col = src_col - 1) ) {
        return true;
    }
    if ( (dest_row = src_row - 2) && (dest_col = src_col + 1) ) {
        return true;
    }

    return false;
}

bool move_rook(Board b, string &turn, int player) {
    int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
    char c = b.get_piece(src_row, src_col);       // Piece to be moved
    char d = b.get_piece(dest_row, dest_col);

    // Moving vertically forward (i.e row number decreasing)
    if ( (src_col == dest_col) && (dest_row < src_row) ) { 
        char p = b.get_piece(src_row - 1,src_col);
        if ( (p != ' ') && (p != d) ) {
            return false;
        }
        for (int i = (src_row - 1); i > dest_row; i--) {
            p = b.get_piece(i,src_col);
            if (p != ' ') {     // Path is blocked by a piece.
                return false;
            }
        }
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving vertically backward (i.e row number increasing)
    if ( (src_col == dest_col) && (dest_row > src_row) ) {
        char p = b.get_piece(src_row + 1,src_col);
        if ( (p != ' ') && (p != d) ) {
            return false;
        }
        for (int i = (src_row + 1); i < dest_row; i++) {
            p = b.get_piece(i,src_col);
            if (p != ' ') {     // Path is blocked by a piece.
                return false;
            }
        }

        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving horizontally, to the right (i.e col number increasing)
    if ( (src_row == dest_row) && (dest_col > src_col) ) {
        char p = b.get_piece(src_row, src_col + 1);
        if ( (p != ' ') && (p != d) ) {
            return false;
        }
        for (int i = (src_col + 1); i < dest_col; i++) {
            p = b.get_piece(src_row, i);
            if (p != ' ') {     // Path is blocked by a piece.
                return false;
            }
        }
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving horizontally, to the left (i.e col number decreasing)
    if ( (src_row == dest_row) && (dest_col < src_col) ) { 
        char p = b.get_piece(src_row, src_col - 1);
        if ( (p != ' ') && (p != d) ) {
            return false;
        }
        for (int i = (src_col - 1); i > dest_col; i--) {
            p = b.get_piece(src_row, i);
            if (p != ' ') {     // Path is blocked by a piece.
                return false;
            }
        }
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    return false;
}

bool move_bishop(Board b, string &turn, int player) {
    int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
    char c = b.get_piece(src_row, src_col);       // Piece to be moved
    char d = b.get_piece(dest_row, dest_col);

    // Moving diagonally
    if ( abs(src_row - dest_row) == abs(src_col - dest_col) ) {
        int num = abs (src_row - dest_row);

        // Moving down, to the right diagonal
        if ( (dest_row - src_row > 0) && (dest_col - src_col > 0) ) {
            for (int i = 1; i < num; i++) {
                char p = b.get_piece(src_row + i, src_col + i); 
                if (p != ' ') {
                    return false;   // Path is blocked by a piece.
                }
            }
            if (player == 0) {    // White player.
                if ( (d != ' ') && (islower(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else {
                    return true;
                }   
            }
            if (player == 1) {    // Black player.
                if ( (d != ' ') && (isupper(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else { 
                    return true;
                }   
            }
        }

        // Moving down, to the left diagonal
        if ( (dest_row - src_row > 0) && (dest_col - src_col < 0) ) {
            for (int i = 1; i < num; i++) {
                char p = b.get_piece(src_row + i, src_col - i);
                if (p != ' ') {
                    return false;   // Path is blocked by a piece.
                }
            }
            if (player == 0) {    // White player.
                if ( (d != ' ') && (islower(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else {
                    return true;
                }   
            }
            if (player == 1) {    // Black player.
                if ( (d != ' ') && (isupper(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else { 
                    return true;
                }
            }
        }
        
        // Moving up, to the right diagonal
        if ( (dest_row - src_row < 0) && (dest_col - src_col > 0) ) {
            for (int i = 1; i < num; i++) {
                char p = b.get_piece(src_row - i, src_col + i);
                if (p != ' ') {
                    return false;   // Path is blocked by a piece.
                }
            }
            if (player == 0) {    // White player.
                if ( (d != ' ') && (islower(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else {
                    return true;
                }   
            }
            if (player == 1) {    // Black player.
                if ( (d != ' ') && (isupper(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else { 
                    return true;
                }
            }
        }

        // Moving up, to the left diagonal
        if ( (dest_row - src_row < 0) && (dest_col - src_col < 0) ) {
            for (int i = 1; i < num; i++) {
                char p = b.get_piece(src_row - i, src_col - i);
                if (p != ' ') {
                    return false;   // Path is blocked by a piece.
                }
            }
            if (player == 0) {    // White player.
                if ( (d != ' ') && (islower(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else {
                    return true;
                }   
            }
            if (player == 1) {    // Black player.
                if ( (d != ' ') && (isupper(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else { 
                    return true;
                }
            }
        }
    }
    return false;
}

bool move_queen(Board b, string &turn, int player) {
    int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
    char c = b.get_piece(src_row, src_col);       // Piece to be moved
    char d = b.get_piece(dest_row, dest_col);

    // Moving vertically forward (i.e row number decreasing)
    if ( (src_col == dest_col) && (dest_row < src_row) ) { 
        char p = b.get_piece(src_row - 1,src_col);
        if ( (p != ' ') && (p != d) ) {
            return false;
        }
        for (int i = (src_row - 1); i > dest_row; i--) {
            p = b.get_piece(i,src_col);
            if (p != ' ') {     // Path is blocked by a piece.
                return false;
            }
        }
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving vertically backward (i.e row number increasing)
    if ( (src_col == dest_col) && (dest_row > src_row) ) {
        char p = b.get_piece(src_row + 1,src_col);
        if ( (p != ' ') && (p != d) ) {
            return false;
        }
        for (int i = (src_row + 1); i < dest_row; i++) {
            p = b.get_piece(i,src_col);
            if (p != ' ') {     // Path is blocked by a piece.
                return false;
            }
        }

        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving horizontally, to the right (i.e col number increasing)
    if ( (src_row == dest_row) && (dest_col > src_col) ) {
        char p = b.get_piece(src_row, src_col + 1);
        if ( (p != ' ') && (p != d) ) {
            return false;
        }
        for (int i = (src_col + 1); i < dest_col; i++) {
            p = b.get_piece(src_row, i);
            if (p != ' ') {     // Path is blocked by a piece.
                return false;
            }
        }
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving horizontally, to the left (i.e col number decreasing)
    if ( (src_row == dest_row) && (dest_col < src_col) ) { 
        char p = b.get_piece(src_row, src_col - 1);
        if ( (p != ' ') && (p != d) ) {
            return false;
        }
        for (int i = (src_col - 1); i > dest_col; i--) {
            p = b.get_piece(src_row, i);
            if (p != ' ') {     // Path is blocked by a piece.
                return false;
            }
        }
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving diagonally
    if ( abs(src_row - dest_row) == abs(src_col - dest_col) ) {
        int num = abs (src_row - dest_row);

        // Moving down, to the right diagonal
        if ( (dest_row - src_row > 0) && (dest_col - src_col > 0) ) {
            for (int i = 1; i < num; i++) {
                char p = b.get_piece(src_row + i, src_col + i); 
                if (p != ' ') {
                    return false;   // Path is blocked by a piece.
                }
            }
            if (player == 0) {    // White player.
                if ( (d != ' ') && (islower(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else {
                    return true;
                }   
            }
            if (player == 1) {    // Black player.
                if ( (d != ' ') && (isupper(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else { 
                    return true;
                }   
            }
        }

        // Moving down, to the left diagonal
        if ( (dest_row - src_row > 0) && (dest_col - src_col < 0) ) {
            for (int i = 1; i < num; i++) {
                char p = b.get_piece(src_row + i, src_col - i);
                if (p != ' ') {
                    return false;   // Path is blocked by a piece.
                }
            }
            if (player == 0) {    // White player.
                if ( (d != ' ') && (islower(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else {
                    return true;
                }   
            }
            if (player == 1) {    // Black player.
                if ( (d != ' ') && (isupper(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else { 
                    return true;
                }
            }
        }
        
        // Moving up, to the right diagonal
        if ( (dest_row - src_row < 0) && (dest_col - src_col > 0) ) {
            for (int i = 1; i < num; i++) {
                char p = b.get_piece(src_row - i, src_col + i);
                if (p != ' ') {
                    return false;   // Path is blocked by a piece.
                }
            }
            if (player == 0) {    // White player.
                if ( (d != ' ') && (islower(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else {
                    return true;
                }   
            }
            if (player == 1) {    // Black player.
                if ( (d != ' ') && (isupper(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else { 
                    return true;
                }
            }
        }

        // Moving up, to the left diagonal
        if ( (dest_row - src_row < 0) && (dest_col - src_col < 0) ) {
            for (int i = 1; i < num; i++) {
                char p = b.get_piece(src_row - i, src_col - i);
                if (p != ' ') {
                    return false;   // Path is blocked by a piece.
                }
            }
            if (player == 0) {    // White player.
                if ( (d != ' ') && (islower(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else {
                    return true;
                }   
            }
            if (player == 1) {    // Black player.
                if ( (d != ' ') && (isupper(d) == 0) ) {
                    return false;       // Trying to capture a piece of the same color.
                } else { 
                    return true;
                }
            }
        }
    }
    return false;
}

bool move_king(Board b, string &turn, int player) {
    int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
    char c = b.get_piece(src_row, src_col);       // Piece to be moved
    char d = b.get_piece(dest_row, dest_col);

    if ( (src_row == dest_row) && (dest_col == src_col + 1) ) {   // Moving one square to the right
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }   
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    if ( (src_row == dest_row) && (dest_col == src_col - 1) ) {   // Moving one square to the left
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }   
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    if ( (dest_row == src_row + 1) && (dest_col == src_col) ) {   // Moving one square backwards
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }   
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    if ( (dest_row == src_row - 1) && (dest_col == src_col) ) {     // Moving one square forward
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }   
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Diagonals:

    // Moving one square back, to the right diagonal
    if ( (dest_row == src_row + 1) && (dest_col == src_col + 1) ) {
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }   
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving one square back, to the left diagonal
    if ( (dest_row == src_row + 1) && (dest_col == src_col - 1) ) {
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }   
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving one square forward, to the right diagonal
    if ( (dest_row == src_row - 1) && (dest_col == src_col + 1) ) {
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }   
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }

    // Moving one square forward, to the left diagonal
    if ( (dest_row == src_row - 1) && (dest_col == src_col - 1) ) {
        if (player == 0) {    // White player.
            if ( (d != ' ') && (islower(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else {
                return true;
            }   
        }
        if (player == 1) {    // Black player.
            if ( (d != ' ') && (isupper(d) == 0) ) {
                return false;       // Trying to capture a piece of the same color.
            } else { 
                return true;
            }
        }
    }
    return false;       
}
