#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../include/config.h"
#include "../../include/Graphics/rendering_element.h"

class GraphicsObject {

public:
	GraphicsObject();
	std::map<int,std::unique_ptr<RenderingElement>> white_pawns;
	std::map<int,std::unique_ptr<RenderingElement>> black_pawns;
	std::unique_ptr<RenderingElement> board;
};

