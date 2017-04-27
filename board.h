//  board.h
//  chess


#ifndef board_h
#define board_h

class Board {
public:
    // constructor
    Board();
    
    // getters and setters
    char get_piece(int, int);
    void set_piece(int, int, char);
    
    // other functions
    void print();
    void make_move(int, int, int, int);
    
private:
    char** grid;
};

#endif
