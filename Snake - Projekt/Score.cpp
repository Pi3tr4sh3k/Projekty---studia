#include <fstream>
#include "Score.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
Score::Score(Snake &s): snake(s){
    actualScore=s.getScore();
}

void Score::saveScore() {
    std::ifstream read("score.txt");
    std::vector<int> bufor1;
    int sc=actualScore;
    int highScore;

    while(!read.eof()){                                                 //odczytywanie wartości i wciskanie ich do vectora
        read >> highScore;
        bufor1.push_back(highScore);
    }
    read.close();                                                       //zamykanie odczytu

    std::sort(bufor1.begin(),bufor1.end(), std::greater<int>()); //sortowanie od najwyższego do najmniejszego

    for(int i = 0;i<bufor1.size()-1;i++){                                 //szukam pierwszego mniejszego elementu od najnowszego wyniku
        if(bufor1[i]<sc) {
            bufor1.at(bufor1.size()-1) = sc;                                          //zapisywanie na miejsce 'i' wartości
            break;
        }
    }
    std::sort(bufor1.begin(),bufor1.end(), std::greater<int>());
    std::ofstream write("score.txt");
    if(write.is_open()){
        for(int i=0;i<bufor1.size()-1;i++){
            write << bufor1.at(i)<<std::endl;
        }

    }

    write.close();

}


