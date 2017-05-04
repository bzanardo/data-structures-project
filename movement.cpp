// movement.cpp
// chess

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "board.h"
#include "movement.h"
using namespace std;

/*** PAWN MOVEMENT ***/
bool move_pawn(Board b, string &turn, int player) {
    int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
    char c = b.get_piece(src_row, src_col);       // Piece to be moved
    char d = b.get_piece(dest_row, dest_col);
    if (player == 0) {      // White piece
	if ( (dest_row == src_row - 2) && (src_col == dest_col) ) {	// Moving two squares on first move
		return (src_row == 6);
	}
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
    if (player == 1) {	// Black piece
	if ( (dest_row == src_row + 2) && (src_col == dest_col) ) {	// Moving two squares on first move
		return (src_row == 1);
	}
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

/*** KNIGHT MOVEMENT ***/
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

/*** ROOK MOVEMENT ***/
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

/*** BISHOP MOVEMENT ***/
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

/*** QUEEN MOVEMENT ***/
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

/*** KING MOVEMENT ***/
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
