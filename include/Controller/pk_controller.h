#pragma once
#include "../Controller/controller.h"
#include "../Controller/player_user.h"
#include "../Model/board.h"
#include <iostream>

class PersonalComputerController: public Controller {
	std::shared_ptr<Player>m_player_ptr_one;
	std::shared_ptr<Player>m_player_ptr_two;
	std::shared_ptr<Board>m_model_ptr;
public:
	PersonalComputerController(std::shared_ptr<Player>, std::shared_ptr<Player>, std::shared_ptr<Board>);
};

