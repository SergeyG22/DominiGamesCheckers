#pragma once
#include "../Controller/player.h"
#include "../Controller/player_ai.h"
#include "../Controller/player_user.h"
#include "../View/display.h"
#include "../Controller/controller.h"

class Game {
    std::shared_ptr<Board> m_board_ptr;
    std::shared_ptr<Display> m_display_ptr;
    std::shared_ptr<Controller> m_controller_ptr;
    std::shared_ptr<PlayerAi> m_player_two_ptr;
    std::shared_ptr<PlayerUser> m_player_one_ptr;
public:
    Game();
    void gameLoop();
};