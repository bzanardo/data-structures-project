//  board.h
//  chess


#ifndef board_h
#define board_h

#include <utility>
#include <string>

class Board {
public:
    // constructor
    Board();
    
    // getters and setters
    char get_piece(int, int);
    void set_piece(int, int, char);
    
    // other functions
    void print();
    void make_move(string&);
    
private:
    char** grid;
    pair<int, int> kingW;
    pair<int, int> kingB;
};

#endif
