#include "../../include/Model/player_ai.h"

PlayerAi::PlayerAi(std::string name) : Player("AI " + name) {

}

std::shared_ptr<Step> PlayerAi::nextStep(std::shared_ptr<Board>& model_ptr) {
    std::cout << "Player ai step: \n";
    model_ptr->printModel();
    std::cout << '\n';
    std::cout << '\n';
    std::shared_ptr<Step> step = std::make_unique<Step>();
    step->from_x = 2;
    step->from_y = 2;
    step->to_x = 1;
    step->to_y = 1;
    return step;
}

void PlayerAi::createPlayer(std::shared_ptr<Board>& model_ptr, const Position& position) {

    std::vector<int>current_positions = model_ptr->getPosition();
    auto iterator = std::find(current_positions.begin(), current_positions.end(), static_cast<int>(position));

    if (iterator != current_positions.end()) {
        std::cerr << "Location error! The positions of the players conflict with each other!\n";
        return;
    }

 //   std::cout <<"model size " << model_ptr->getMatrix().size() <<'\n';

    switch (position) {

    case Position::TOP_LEFT: {
        for (int i = 1; i < NUMBER_OF_ROWS + 1; ++i) {
            for (int j = 1; j < NUMBER_OF_COLUMNS + 1; ++j) {
                model_ptr->getMatrix()[i][j] = m_label;
            }
        }
        
        model_ptr->setPosition(static_cast<int>(position));
        break;
    }
    case Position::TOP_RIGHT: {
        for (int i = 1; i < NUMBER_OF_ROWS + 1; ++i) {
            for (int j = model_ptr->getMatrix().size() - (NUMBER_OF_COLUMNS + 1); j < model_ptr->getMatrix().size() - 1; ++j) {
                model_ptr->getMatrix()[i][j] = m_label;
            }
        }

        model_ptr->setPosition(static_cast<int>(position));
        break;
    }
    case Position::BOTTOM_LEFT: {
        for (int i = model_ptr->getMatrix().size() - (NUMBER_OF_ROWS + 1); i < model_ptr->getMatrix().size() - 1; ++i) {
            for (int j = 1; j < NUMBER_OF_COLUMNS + 1; ++j) {
                model_ptr->getMatrix()[i][j] = m_label;
            }
        }

        model_ptr->setPosition(static_cast<int>(position));
        break;
    }
    case Position::BOTTOM_RIGHT: {
        for (int i = model_ptr->getMatrix().size() - (NUMBER_OF_ROWS + 1); i < model_ptr->getMatrix().size() - 1; ++i) {
            for (int j = model_ptr->getMatrix().size() - (NUMBER_OF_COLUMNS + 1); j < model_ptr->getMatrix().size() - 1; ++j) {
                model_ptr->getMatrix()[i][j] = m_label;
            }
        }

        model_ptr->setPosition(static_cast<int>(position));
        break;
    }
    }
}






