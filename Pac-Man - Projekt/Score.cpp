
#include "Score.h"
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
Score::Score(Player &p):p1(p) {
    actualScore=p.getScore();
}

void Score::saveScore() {
    std::ifstream read("hscore.txt");
    std::vector<int> bufor;
    int score;
    while(!read.eof()){
        read>>score;
        bufor.push_back(score);
    }
    read.close();
    std::sort(bufor.begin(),bufor.end(),std::greater<int>());
    for(int i=0;i<bufor.size()-1;i++){
        if(bufor[i]<actualScore){
            bufor.at(bufor.size()-1)=actualScore;
            break;
        }
    }
    std::sort(bufor.begin(),bufor.end(),std::greater<int>());
    std::ofstream write("hscore.txt");
    if(write.is_open()){
        for(int i=0;i<bufor.size()-1;i++){
            write<<bufor.at(i)<<std::endl;
        }
    }
    write.close();
}
