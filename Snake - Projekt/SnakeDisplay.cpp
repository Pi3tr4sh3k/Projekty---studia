
#include "SnakeDisplay.h"
#include <iostream>
SnakeDisplay::SnakeDisplay(SBoard &b, Snake &s):board(b),snake(s){
    wys=board.getHeight();
    szer=board.getWidth();

}

void SnakeDisplay::display() {
    len=snake.getSnakeSize()-2;
    int len2=snake.getSnakeSize()-1;
    char board_temp[10][10];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            board_temp[i][j]=' ';


    do {

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (snake.getFirstSnakeCords(len)==i && snake.getSecondSnakeCords(len)==j)
                    board_temp[i][j]='W';
                else if(snake.getFirstFoodCords(0)==i && snake.getSecondFoodCords(0)==j)
                    board_temp[i][j]='A';
                else if(snake.getFirstSnakeCords(len2)==i && snake.getSecondSnakeCords(len2)==j)
                    board_temp[i][j]='G';
            }
        }


        --len;
    }while(len>=0);

    if(snake.isColliding()){
        std::cout<<"PRZEGRANA!"<<std::endl<<"-----------------------------"<<std::endl;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){

            if(board_temp[i][j]==' ')
                std::cout<<"[ ]";
            else if(board_temp[i][j]=='W')
                std::cout<<"[X]";
            else if(board_temp[i][j]=='A')
                std::cout<<"[A]";
            else if(board_temp[i][j]=='G')
                std::cout<<"[G]";
        }
        std::cout<<std::endl;
    }
    std::cout<<"----------------------"<<std::endl;
}



