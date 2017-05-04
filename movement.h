// movement.h
// chess

#ifndef movement_h
#define movement_h

#include "board.h"
#include <string>
using namespace std;

bool move_pawn(Board, string&, int);
bool move_knight(Board, string&, int);
bool move_rook(Board, string&, int);
bool move_bishop(Board, string&, int);
bool move_queen(Board, string&, int);
bool move_king(Board, string&, int);

#endif
