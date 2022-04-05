#include "../../include/Model/player_user.h"

PlayerUser::PlayerUser(std::string name) : Player("USER " + name) {

}

void PlayerUser::setWindow(std::shared_ptr<Display> window_ptr) {
    PlayerUser::m_window_ptr = window_ptr;
}

std::shared_ptr<Step> PlayerUser::nextStep(std::shared_ptr<Board>& model_ptr) {
    waitEvent();
    std::cout << "Player user step: \n";
    model_ptr->printModel();
    std::cout << '\n';
    std::cout << '\n';
    std::shared_ptr<Step> step = std::make_unique<Step>();
    step->from_x = 1;
    step->from_y = 1;
    step->to_x = 2;
    step->to_y = 2;
    return step;
}

void PlayerUser::waitEvent() {
    sf::Event event;
    m_window_ptr->getWindowPtr()->display();

    while (m_window_ptr->getWindowPtr()->waitEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window_ptr->getWindowPtr()->close();
        }
        if (isEventMouseClick(event)) {
            break;
        }
    }
   
}

void PlayerUser::createPlayer(std::shared_ptr<Board>& model_ptr, const Position& position) {

    std::vector<int>current_positions = model_ptr->getPosition();
    auto iterator = std::find(current_positions.begin(), current_positions.end(), static_cast<int>(position));

    if (iterator != current_positions.end()) {
        std::cerr << "Location error! The positions of the players conflict with each other!\n";
        return;
    }

    switch (position) {

    case Position::TOP_LEFT: {

        for (int i = 1; i < NUMBER_OF_ROWS + 1; ++i) {
            for (int j = 1; j < NUMBER_OF_COLUMNS + 1; ++j) {
                model_ptr->getMatrix()[i][j] = m_label;
            }
        }

        model_ptr->setPosition(static_cast<int>(position));
        model_ptr->setEndPoints(static_cast<int>(position));
        break;
    }
    case Position::TOP_RIGHT: {
        for (int i = 1; i < NUMBER_OF_ROWS + 1; ++i) {
            for (int j = model_ptr->getMatrix().size() - (NUMBER_OF_COLUMNS + 1); j < model_ptr->getMatrix().size() - 1; ++j) {
                model_ptr->getMatrix()[i][j] = m_label;
            }
        }

        model_ptr->setPosition(static_cast<int>(position));
        model_ptr->setEndPoints(static_cast<int>(position));
        break;
    }
    case Position::BOTTOM_LEFT: {
        for (int i = model_ptr->getMatrix().size() - (NUMBER_OF_ROWS + 1); i < model_ptr->getMatrix().size() - 1; ++i) {
            for (int j = 1; j < NUMBER_OF_COLUMNS + 1; ++j) {
                model_ptr->getMatrix()[i][j] = m_label;
            }
        }

        model_ptr->setPosition(static_cast<int>(position));
        model_ptr->setEndPoints(static_cast<int>(position));
        break;
    }
    case Position::BOTTOM_RIGHT: {
        for (int i = model_ptr->getMatrix().size() - (NUMBER_OF_ROWS + 1); i < model_ptr->getMatrix().size() - 1; ++i) {
            for (int j = model_ptr->getMatrix().size() - (NUMBER_OF_COLUMNS + 1); j < model_ptr->getMatrix().size() - 1; ++j) {
                model_ptr->getMatrix()[i][j] = m_label;
            }
        }

        model_ptr->setPosition(static_cast<int>(position));
        model_ptr->setEndPoints(static_cast<int>(position));
        break;
    }
    }
}

bool PlayerUser::isEventMouseClick(sf::Event& event) {
    return event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left;
}





