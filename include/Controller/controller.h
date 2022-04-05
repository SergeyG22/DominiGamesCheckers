#pragma once
#include <SFML/Graphics.hpp>
#include "../Model/board.h"
#include "../Model/step.h"

class Controller {
    bool canStep(std::shared_ptr<Board>, std::shared_ptr<Step>);
public:
    virtual ~Controller() = default;
    bool makeStep(std::shared_ptr<Board>, std::shared_ptr<Step>);
    bool isGameOver(std::shared_ptr<Board>);
};
