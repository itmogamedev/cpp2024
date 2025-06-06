#include "GameController.h"

GameController::GameController()  {
    model = new GameModel();

    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            setCellHiden(x, y);
            setCellFood(x, y);

            setCellType(x, y);
        }
    }
}

bool GameController::isWinOfGame() {
    bool winCondition = true;
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            if (isHidden(x, y)) {
                winCondition = false;
                break;
            }
        }
    }
    return winCondition;
}

void GameController::clickTile(const int& mouseX, const int& mouseY,
    int& x, int& y) {


    model->energyRemove(1);

    x = mouseX < 0 ?
        0 :
        mouseX> CELLSIZE_SCREEN * CELLSIZE_M ?
        CELLSIZE_M :
        mouseX / CELLSIZE_SCREEN;

    y = mouseY < 0 ?
        0 :
        mouseY > CELLSIZE_SCREEN * CELLSIZE_N ?
        CELLSIZE_N :
        mouseY / CELLSIZE_SCREEN;

    setCellHiden(x, y);

    if (isFood(x,y)) {
        model->energySetMax();
    }
}