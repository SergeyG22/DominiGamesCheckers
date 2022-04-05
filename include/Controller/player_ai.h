#pragma once
#include "player.h"
#include "../../include/Model/board.h"
#include <random>
#include <chrono>

class PlayerAi : public Player {
    int m_player_id;
    int m_number_of_active_object = 0;
    bool m_current_active_object = false;
    const char m_label = 'a';     
    bool move(int);
    void isFormAvailable();
    int activateRandomForm();
    void deactivateObject(int);
    bool findFreePosition(int, int);
    void swapEndPoints(int, std::pair<int,int>);
    std::vector<int>numbers_of_objects_touched_square;
public:
    PlayerAi(std::string, std::shared_ptr<Board>);
    std::shared_ptr<Step> nextStep(std::shared_ptr<Board>&) override;
    void createPlayer(const EdgePositions & position);
};