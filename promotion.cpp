// promotion.cpp
// chess

#include <iostream>
#include <string>
#include "promotion.h"
#include "board.h"

bool can_promote(Board board, string &turn, int player) {
	int src_row = turn[0]-'0', src_col = turn[1]-'0', dest_row = turn[2]-'0', dest_col = turn[3]-'0';
	char c = board.get_piece(src_row, src_col);
	player = player%2;

	if (c == 'P' || c == 'p') {
		if (player == 0) { // White plays
			return (dest_row == 0);
		} else {  // Black plays
			return (dest_row == 7); 
		}
	} else {
		return false;
	}	
}

void make_promotion(Board &board, string &turn, char piece) {
	int src_row = turn[0]-'0', src_col = turn[1]-'0';
	board.set_piece(src_row, src_col, piece);
}
