#include "../../include/View/display.h"

void Display::render(std::shared_ptr<Board> board) {
    const std::vector<std::vector<char>>& m_matrix = board->getMatrix();
    for (int i = 0; i < m_matrix.size(); ++i) {
        for (int j = 0; j < m_matrix[i].size(); ++j) {
            std::cout << m_matrix[j][i] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
};