#pragma once

constexpr int minWidth(const int width) {
	if (width <= 6) {
		return 6;
	}
	return width;
}
constexpr int minHeight(int height) {
	if (height <= 6) {
		return 6;
	}
	return height;
}

constexpr int FIELD_WIDTH =  minWidth(8);
constexpr int FIELD_HEIGHT = minHeight(8);
constexpr int NUMBER_OF_ROWS = 3;
constexpr int NUMBER_OF_COLUMNS = 3;
constexpr unsigned int WINDOW_WIDTH = 800;
constexpr unsigned int WINDOW_HEIGHT = 800;
constexpr int CELL_WIDTH = WINDOW_WIDTH / FIELD_WIDTH;
constexpr int CELL_HEIGHT = WINDOW_HEIGHT / FIELD_HEIGHT;
enum class EdgePositions { TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT };
