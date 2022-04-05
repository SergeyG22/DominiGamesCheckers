#pragma once
#include <SFML/Graphics.hpp>
#include "../Model/board.h"

class Display {

public:
    virtual ~Display() = default;
    virtual sf::RenderWindow *getWindowPtr() = 0;
    virtual void render(std::shared_ptr<Board>);
    virtual bool isOpen() = 0;
};