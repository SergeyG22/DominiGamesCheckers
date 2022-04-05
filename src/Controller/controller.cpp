#include "../../include/Controller/controller.h"

bool Controller::canStep(std::shared_ptr<Board> board_ptr, std::shared_ptr<Step> step_ptr) {
    return true; 
}

bool Controller::makeStep(std::shared_ptr<Board> model_ptr, std::shared_ptr<Step> step_ptr) {
    if (canStep(model_ptr, step_ptr)) {
        return true;
    }
    else {
        return false;
    }
}

bool Controller::isGameOver(std::shared_ptr<Board> model_ptr) {
    return false; 
}