

#include "MinesweeperBoard.h"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;

int MinesweeperBoard::getBoardWidth()const{
    return width;
}
int MinesweeperBoard::getBoardHeight()const{
    return height;
}

int MinesweeperBoard::getMineCount()const{
    if(mode==easy)
        return width*height*0.1;
    if(mode==medium)
        return width*height*0.2;
    if(mode==hard)
        return width*height*0.3;

    return 0;



}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode){
    float poziom_trudnosci=0;
    state=RUNNING;
    this->width = width;
    this->height = height;
    int ileMin=0;
    int board_area=0;
    board_area=height*width;

    for(int i = 0; i<height; i++){
        for(int j = 0; j<width;j++){
            board[i][j]={0,0,0};
        }
    }
    if(mode==easy) {
        poziom_trudnosci = 0.1;
        ileMin=board_area*poziom_trudnosci;
    }
    if(mode==medium) {
        poziom_trudnosci = 0.2;
        ileMin=board_area*poziom_trudnosci;
    }
    if(mode==hard) {
        poziom_trudnosci = 0.3;
        ileMin=board_area*poziom_trudnosci;

    }

    int wspx;
    int wspy;
    while(ileMin!=0){
        wspx=rand()%height;
        wspy=rand()%width;
        if(board[wspx][wspy].bomba==0){
            board[wspx][wspy].bomba=1;
            ileMin--;

        }
    }

    if(mode==debug){

        for(int i=0;i<width;i++){
            board[0][i].bomba=true;

            for(int j=0;j<height;j++){
                if(i==j)
                    board[i][j].bomba=true;
                board[j*2][0].bomba=true;

            }
        }
    }


    debug_display();
}
void MinesweeperBoard::debug_display() const {
    for(int x=0;x<height;x++){
        for(int y=0;y<width;y++){
            cout<<"[";
            if(board[x][y].bomba==1)
                cout<<"M";
            else
                cout<<".";
            if(board[x][y].flaga==1)
                cout<<"f";
            else
                cout<<".";
            if(board[x][y].odkryte==1)
                cout<<"o";
            else
                cout<<".";
            cout<<"]";

        }
        cout<<endl;
    }
}
bool MinesweeperBoard::isRevealed(int x, int y) const {
    if(board[x][y].odkryte==true)
        return true;
    else
        return false;
}
bool MinesweeperBoard::isOutside(int x, int y) const {
    if((x>height || y>width) || (x<0 || y<0))
        return true;
    else
        return false;
}
bool MinesweeperBoard::hasFlag(int x, int y) const {

    if(board[x][y].flaga==true && !isOutside(x,y) && !isRevealed(x,y))
        return true;
    return false;
}
int MinesweeperBoard::countMines(int x, int y) const {
    int counter=0;
    if(isRevealed(x,y)== false || isOutside(x,y)==true)
        return -1;
   if(board[x-1][y-1].bomba==true && !isOutside(x-1,y-1))
        counter++;
     if(board[x-1][y].bomba== true && !isOutside(x-1,y))
        counter++;
    if(board[x-1][y+1].bomba== true && !isOutside(x-1,y+1))
        counter++;
    if(board[x][y-1].bomba==true && !isOutside(x,y-1))
        counter++;
    if(board[x][y].bomba==true && !isOutside(x,y))
        counter++;
    if(board[x][y+1].bomba==true && !isOutside(x,y+1))
        counter++;
    if(board[x+1][y-1].bomba==true && !isOutside(x+1,y-1))
        counter++;
    if(board[x+1][y].bomba==true && !isOutside(x+1,y))
        counter++;
    if(board[x+1][y+1].bomba==true && !isOutside(x+1,y+1))
        counter++;
    return counter;

}
void MinesweeperBoard::toggleFlag(int x, int y) {
    if(board[x][y].odkryte==false && isOutside(x,y)==false && state==RUNNING) {
        board[x][y].flaga=true;
    }
}
void MinesweeperBoard::revealField(int x, int y) {
    bool pom = true;
    if(!isRevealed(x,y) && hasFlag(x,y) && !hasBomb(x,y)){
        board[x][y].flaga=0;
        board[x][y].odkryte=0;
    }
    else if (!isRevealed(x,y) && hasFlag(x,y) && hasBomb(x,y)){
        board[x][y].flaga=0;
        board[x][y].odkryte=1;
        state=LOSE;
    }

    if (isRevealed(x, y) || isOutside(x, y) || state == LOSE || state == WIN || hasFlag(x, y))
        return;

    else {
        if (!isRevealed(x, y) && !hasBomb(x, y))
            board[x][y].odkryte = 1;
        if (countMines(x, y) == 0) {                    // Flood fill zaciągnięty ze stackoverflow
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    revealField(x - 1 + row, y + col - 1);
                }
            }
        } else if (hasBomb(x, y)) {
            if (mode != debug) {
                for (int i = 0; i < getBoardHeight(); i++) {
                    for (int j = 0; j < getBoardWidth(); j++) {
                        if (board[i][j].odkryte == 1) {
                            board[x][y].odkryte = 1;
                            state = LOSE;
                            pom = false;
                            break;
                        }
                    }
                }
                if (pom) {
                    int a, b;
                    bool warunek = false;
                    while (!warunek) {
                        a = rand() % getBoardHeight();
                        b = rand() % getBoardWidth();
                        if (board[a][b].bomba == 0) {
                            board[x][y].bomba = 0;
                            board[x][y].odkryte = 1;
                            board[a][b].bomba = 1;
                        }
                            if (countMines(x, y) == 0) {                    // Flood fill zaciągnięty ze stackoverflow
                                for (int row = 0; row < 3; row++) {
                                    for (int col = 0; col < 3; col++) {
                                        revealField(x - 1 + row, y + col - 1);
                                    }
                                }
                            }
                            warunek = true;
                    }
                }
            }
        }
    }
}




    bool MinesweeperBoard::hasBomb(int x,int y) const{
        if(board[x][y].bomba==true)
            return true;
        else
            return false;
    }
    char MinesweeperBoard::getFieldInfo(int x, int y) const{
        if(!isRevealed(x,y) && !hasFlag(x,y))
            return '_';
        else if(isRevealed(x,y) && countMines(x,y)==0)
            return ' ';
        else if(isOutside(x,y))
            return '#';
        else if(hasFlag(x,y) && !isRevealed(x,y))
            return 'F';
        else if(isRevealed(x,y) && hasBomb(x,y))
            return 'x';
        else if(isRevealed(x,y) && countMines(x,y)>0){
            char pom;
            int conv=0;
            conv=countMines(x,y);
            pom=conv+48;
            return pom;
        }
        return 'E';
    }
    GameState MinesweeperBoard::getGameState() const {
        int cmon=0;
        for(int he=0;he<height;he++){
            for(int wi=0;wi<width;wi++){
                if(hasBomb(he,wi) && isRevealed(he,wi)) {
                    return LOSE;
                    break;
                }
                else if ((hasBomb(he,wi) && hasFlag(he,wi) && !isRevealed(he,wi)) || (!hasBomb(he,wi) && !hasFlag(he,wi) && isRevealed(he, wi)))
                    cmon++;
            }
        }
        if(width*height==cmon)
            return WIN;
        else
            return RUNNING;
    }
