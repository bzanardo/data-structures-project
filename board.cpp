//  board.cpp
//  chess

#include <iostream>
#include "board.h"
using namespace std;

// Constructor

Board::Board() {
    // allocate 2d array
    grid = new char*[8];
    for (int i=0; i < 8; i++) {
        grid[i] = new char[8];
    }
    
    // initial board state
    set_piece(0,0,'r');
    set_piece(0,1,'n');
    set_piece(0,2,'b');
    set_piece(0,3,'q');
    set_piece(0,4,'k');
    set_piece(0,5,'b');
    set_piece(0,6,'n');
    set_piece(0,7,'r');
    
    for (int j=0; j < 8; j++) {
        set_piece(1,j,'p');
    }
    
    for (int i=2; i <= 5; i++) {
        for (int j=0; j < 8; j++) {
            set_piece(i,j,' ');
        }
    }
    
    for (int j=0; j < 8; j++) {
        set_piece(6,j,'P');
    }
    
    set_piece(7,0,'R');
    set_piece(7,1,'N');
    set_piece(7,2,'B');
    set_piece(7,3,'Q');
    set_piece(7,4,'K');
    set_piece(7,5,'B');
    set_piece(7,6,'N');
    set_piece(7,7,'R');
}

char Board::get_piece(int row, int col) {return grid[row][col];}

void Board::set_piece(int row, int col, char c) {grid[row][col] = c;}

void Board::print() {
    cout << endl;
    // print col numbers above board
    for (int i=0; i < 9; i++) {
        if (i == 0)
            cout << "   ";
        else
            cout << i-1 << ' ';
    }
    cout << '\n' << endl;
    // print board with row numbers
    for (int i=0; i < 8; i++) {
        for (int j=0; j < 9; j++) {
            if (j == 0) {
                cout << i << "  ";
            } else {
                if (grid[i][j-1] != ' ')
                    cout << grid[i][j-1] << ' ';
                else
                    cout << "- ";
            }
        }
        cout << endl;
    }
}

void Board::make_move(int src_row, int src_col, int dest_row, int dest_col) {
    char c = get_piece(src_row, src_col);
    set_piece(src_row, src_col, ' ');
    set_piece(dest_row, dest_col, c);
}
