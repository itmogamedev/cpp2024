#pragma once

#include "cell.h"
#include <stdlib.h>

class GameModel {
public:
    const int getEnergy() const { return energy; }
    void energyRemove(int _energy) { energy -= _energy; };
    void energySetMax() { energy = ENERGY_MAX; };

    Cell * getCell(int x, int y) {
        return cells[x][y];
    };

    void setCellHiden(int x, int y) {
        cells[x][y]->isHidden = true;
    };
    void setCellFood(int x, int y) {
        cells[x][y]->isFood = rand() % 100 < CHANCE_FOOD;
    };
    void setCellType(int x, int y) {
        cells[x][y]->cellType =
            static_cast<CellType> (rand() % (CellType::Type_End - 1));
    };

    GameModel() {
        for (int x = 0; x < CELLSIZE_M; x++) {
            for (int y = 0; y < CELLSIZE_N; y++) {
                cells[x][y] = new Cell();                
            }
        }
    }
private:
    int energy = ENERGY_MAX;
    Cell * cells[CELLSIZE_M][CELLSIZE_N];
};