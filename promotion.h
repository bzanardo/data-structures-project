// promotion.h
// chess

#ifndef promotion_h
#define promotion_h

#include <string>
#include "board.h"

bool can_promote(Board, string&, int);
void make_promotion(Board&, string&, char);

#endif
