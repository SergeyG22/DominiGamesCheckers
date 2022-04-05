#include "../../include/Graphics/graphic.h"

GraphicsObject::GraphicsObject() {
	for (int i = 0; i <= (NUMBER_OF_ROWS * NUMBER_OF_COLUMNS) - 1; ++i) {
		white_pawns[i] = std::make_unique<RenderingElement>("pawns/white.png");
		black_pawns[i] = std::make_unique<RenderingElement>("pawns/black.png");
	}
	board = std::make_unique<RenderingElement>("board.jpg");
}


