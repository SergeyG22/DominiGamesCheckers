#include "../../include/Controller/player.h"

Player::Player(std::string name, std::shared_ptr<Board> model_ptr) : m_name(name), m_model_ptr(model_ptr) {

}

std::string Player::getName() const {
    return m_name;
}

int Player::player_id = 0;

