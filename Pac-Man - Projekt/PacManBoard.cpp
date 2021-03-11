
#include "PacManBoard.h"
#include <deque>
#include <fstream>

PacManBoard::PacManBoard() {
    std::ifstream read("../map.txt");
    char pom;
    std::deque<char>temp;
    while(!read.eof()){
        read >> pom;
        temp.push_back(pom);

    }
    int k=0;

    for(int i = 0; i<getHeight(); i++){
        for(int j = 0; j<getWidth(); j++){
            board[j][i]=temp[k];
            ++k;
        }
    }
    read.close();

}

int PacManBoard::getWidth() const {
    return width;
}

int PacManBoard::getHeight() const {
    return height;
}
char PacManBoard::getFieldInfo(int x, int y) const {
    if(board[x][y]=='W')
        return 'W';
    else if(board[x][y]=='O')
        return '.';
    else if(board[x][y]=='B')
        return '*';
    else if(board[x][y]=='S')
        return 'S';
    else if(board[x][y]=='C')
        return ' ';
    else if(board[x][y]=='P')
        return 'P';
    else if(board[x][y]=='E')
        return 'E';
    return 'e';
}


void PacManBoard::setFieldStatus(int x, int y, char s) {
    board[x][y]=s;
}




