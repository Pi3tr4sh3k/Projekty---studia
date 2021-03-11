//
// Created by pfrei on 26.03.2020.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H


enum GameMode {easy, medium, hard, debug};
enum GameState {RUNNING,WIN,LOSE};
struct Field{
    bool flaga;
    bool bomba;
    bool odkryte;
};
class MinesweeperBoard{
    Field board[100][100];
    int width;
    int height;
    GameState state;
    GameMode mode;

public:
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display()const;
    int getBoardWidth()const;
    int getBoardHeight()const;
    int getMineCount()const;
    bool isRevealed(int x, int y) const;
    bool isOutside(int x, int y) const;
    bool hasFlag(int x, int y) const;
    int countMines(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    bool hasBomb(int x, int y) const;
    char getFieldInfo(int x, int y) const;
    GameState getGameState() const;
};


#endif //SAPER_MINESWEEPERBOARD_H
