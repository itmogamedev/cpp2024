#pragma once
#include "model.h"

class GameController {
public:

    GameController();

    bool isWinOfGame();

    bool isLoseOfGame() { return model->getEnergy() <= 0; };

    void clickTile(const int& mouseX, const int& mouseY,
        int& x, int& y);

    const int getEnergy() const { return model->getEnergy(); }
    bool isHidden(int x, int y) const { return model->getCell(x,y)->isHidden;}
    bool isFood(int x, int y) const { return model->getCell(x, y)->isFood; }
    CellType getCellType(int x, int y) const { return model->getCell(x, y)->cellType; }
    void setCellHiden(int x, int y) { model->setCellHiden(x, y); };
    void setCellFood(int x, int y) { model->setCellFood(x, y); };
    void setCellType(int x, int y) { model->setCellType(x, y); };

private:
    GameModel* model;
};