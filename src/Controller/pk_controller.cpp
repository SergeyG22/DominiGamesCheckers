#include "../../include/Controller/pk_controller.h"


PersonalComputerController::PersonalComputerController(std::shared_ptr<Player> player_ptr_one, 
													   std::shared_ptr<Player> player_ptr_two, std::shared_ptr<Board> model_ptr)
													   : m_player_ptr_one(player_ptr_one), m_player_ptr_two(player_ptr_two), m_model_ptr(model_ptr) {

}



