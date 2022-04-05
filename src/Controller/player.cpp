#include "../../include/Model/player.h"

Player::Player(std::string name) : m_name(name) {

}


std::string Player::getName() const {
    return m_name;
}
