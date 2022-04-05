#include "../../include/View/window.h"

Window::Window() {

}

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

void Window::render(std::shared_ptr<Board> board) {
    int index_one = 0;
    int index_two = 0;

    for (int i = 1; i < board->getMatrix().size() - 1; ++i) {
        for (int j = 1; j < board->getMatrix()[i].size() - 1; ++j) {
            int x = (i * 100) - 100; 
            int y = (j * 100) - 100;
            if (board->getMatrix()[i][j] == 'p') {                
                 m_graphics_object.white_pawns[index_one]->sprite.setPosition(x, y);
                 index_one += 1;
            }
            if (board->getMatrix()[i][j] == 'a') {
                 m_graphics_object.black_pawns[index_two]->sprite.setPosition(x, y);
                 index_two += 1;
            }
        }
    }

    m_window.clear();
    m_window.draw(m_graphics_object.board->sprite);
  
    for (int i = 0; i < (NUMBER_OF_ROWS * NUMBER_OF_COLUMNS); ++i) {
        m_window.draw(m_graphics_object.white_pawns[i]->sprite);
        m_window.draw(m_graphics_object.black_pawns[i]->sprite);
    }

    m_window.display();
    Display::render(board);
}

bool Window::isOpen() {
    return m_window.isOpen();
}


