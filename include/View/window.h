#pragma once
#include "display.h"
#include "../Controller/pk_controller.h"
#include "../Model/board.h"
#include "../Graphics/graphic.h"

class Window : public Display {
	sf::RenderWindow m_window{ sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"SmartCheckers",sf::Style::Close | sf::Style::Titlebar };
	GraphicsObject m_graphics_object;
public:
	Window();
	sf::RenderWindow* getWindowPtr() override;
	bool isOpen() override;
    void render(std::shared_ptr<Board>) override;
};