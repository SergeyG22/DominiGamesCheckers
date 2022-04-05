#include "../../include/Facades/game.h"

Game::Game() {
    m_board_ptr = std::make_unique<Board>();
    m_player_one_ptr = std::make_unique<PlayerUser>("player_user", m_board_ptr);
    m_player_two_ptr = std::make_unique<PlayerAi>("player ai", m_board_ptr);
    m_controller_ptr = std::make_unique<PersonalComputerController>(m_player_one_ptr, m_player_two_ptr, m_board_ptr);
    m_display_ptr = std::make_unique<Window>();
    m_player_one_ptr->createPlayer(EdgePositions::TOP_LEFT);
    m_player_two_ptr->createPlayer(EdgePositions::BOTTOM_RIGHT);
    m_player_one_ptr->setWindow(m_display_ptr);
}

void Game::gameLoop() {
    std::shared_ptr<Player> previous = m_player_one_ptr;
    std::shared_ptr<Player> next = m_player_two_ptr;
    while (!m_controller_ptr->isGameOver(m_board_ptr) && m_display_ptr->isOpen()) { 
        m_display_ptr->render(m_board_ptr);
        while (!m_controller_ptr->makeStep(m_board_ptr, next->nextStep(m_board_ptr)));   
        std::shared_ptr<Player> tmp = previous;
        previous = next;
        next = tmp;
    } 
}

