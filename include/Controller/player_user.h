#pragma once
#include "player.h"
#include "../../include/Model/board.h"
#include "../View/display.h"
#include "../View/window.h"

class PlayerUser : public Player {
    std::shared_ptr<Display> m_window_ptr;
    sf::Vector2f m_position_realtive_to_world_coordinates;
    int m_player_id;
    char m_current_label;
    const char m_label = 'p';
    int m_current_selected_position_x = 0;
    int m_current_selected_position_y = 0;
    void waitEvent();
    bool isEventMouseClick(sf::Event&);
    bool isKeyboardEvent(sf::Event&);
public:
    PlayerUser(std::string, std::shared_ptr<Board>);
    std::shared_ptr<Step> nextStep(std::shared_ptr<Board>&) override;
    void createPlayer(const EdgePositions&);
    void setWindow(std::shared_ptr<Display>);
};