#include "../../include/Controller/player_user.h"

PlayerUser::PlayerUser(std::string name, std::shared_ptr<Board> model_ptr) : Player("USER " + name, model_ptr), m_player_id(++Player::player_id){
     
}

void PlayerUser::setWindow(std::shared_ptr<Display> window_ptr) {
    PlayerUser::m_window_ptr = window_ptr;
}

std::shared_ptr<Step> PlayerUser::nextStep(std::shared_ptr<Board>& model_ptr) {
    waitEvent();
    std::cout << "Player user step: \n";
    std::shared_ptr<Step> step = std::make_unique<Step>();
    return step;
}  


void PlayerUser::waitEvent() {
    sf::Event event;

    while (m_window_ptr->getWindowPtr()->waitEvent(event)) {

        sf::Vector2i position_relative_to_window = sf::Mouse::getPosition(*m_window_ptr->getWindowPtr());
        m_position_realtive_to_world_coordinates = (m_window_ptr->getWindowPtr())->mapPixelToCoords(position_relative_to_window);

        if (event.type == sf::Event::Closed) {
            m_window_ptr->getWindowPtr()->close();
        }
           isEventMouseClick(event);
        
        if (isKeyboardEvent(event)) {
            break;
        }
    }
}

bool PlayerUser::isKeyboardEvent(sf::Event& event) {

    if (m_current_label == 'p') {

        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {

            case sf::Keyboard::Key::W: {

                int current_pos_x = m_current_selected_position_x;
                int current_pos_y = m_current_selected_position_y - 1;
                
                if (m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != '0' &&
                    m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'p' &&
                    m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'a'
                    ) {
                    m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y] = '1';
                    m_current_selected_position_y--;
                    m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y] = 'p';
                }
                
                return true;
            }
            case sf::Keyboard::Key::S: {
                int current_pos_x = m_current_selected_position_x;
                int current_pos_y = m_current_selected_position_y + 1;
                
                if (m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != '0' &&
                    m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'p' &&
                    m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'a'
                    ) {
                    m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y] = '1';
                    m_current_selected_position_y++;
                    m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y] = 'p';
                }
                
                return true;
            }
            case sf::Keyboard::Key::A: {
                int current_pos_x = m_current_selected_position_x - 1;
                int current_pos_y = m_current_selected_position_y;
                
                if (m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != '0' &&
                    m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'p' &&
                    m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'a'
                    ) {
                    m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y] = '1';
                    m_current_selected_position_x--;
                    m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y] = 'p';
                }
                
                return true;
            }
            case sf::Keyboard::Key::D: {
                int current_pos_x = m_current_selected_position_x + 1;
                int current_pos_y = m_current_selected_position_y;
                
                if (m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != '0' &&
                    m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'p' &&
                    m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'a'
                    ) {
                    m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y] = '1';
                    m_current_selected_position_x++;
                    m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y] = 'p';
                }
                
                return true;
            }

            }
        }
    }

    return false;
}

bool PlayerUser::isEventMouseClick(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.key.code == sf::Mouse::Left) { 
            m_current_selected_position_x = (((int)m_position_realtive_to_world_coordinates.x / CELL_WIDTH)) + 1;
            m_current_selected_position_y = (((int)m_position_realtive_to_world_coordinates.y / CELL_HEIGHT)) + 1;
            m_current_label = m_model_ptr->getMatrix()[m_current_selected_position_x][m_current_selected_position_y];
        }
    }
    return true;
}

void PlayerUser::createPlayer(const EdgePositions& edge_position) {
    
    m_edge_position = edge_position;

    std::vector<EdgePositions>current_positions = m_model_ptr->getEdgePositions();
    auto iterator = std::find(current_positions.begin(), current_positions.end(), edge_position);

    if (iterator != current_positions.end()) {
        std::cerr << "Location error! The positions of the players conflict with each other!\n";
        return;
    }
    
    switch (edge_position) {

    case EdgePositions::TOP_LEFT: {

        for (int i = 1; i < NUMBER_OF_ROWS + 1; ++i) {
            for (int j = 1; j < NUMBER_OF_COLUMNS + 1; ++j) {
                m_model_ptr->getMatrix()[i][j] = m_label;
                m_model_ptr->setStartPlayerPositions(i, j, m_player_id);
            }
        }
        
        m_model_ptr->setEdgePosition(edge_position);
        m_model_ptr->setFinalPlayerPositions(m_player_id, edge_position);
        break;
    }

    case EdgePositions::BOTTOM_LEFT: {
        for (int i = 1; i < NUMBER_OF_ROWS + 1; ++i) {
            for (int j = m_model_ptr->getMatrix().size() - (NUMBER_OF_COLUMNS + 1); j < m_model_ptr->getMatrix().size() - 1; ++j) {
                m_model_ptr->getMatrix()[i][j] = m_label;
                m_model_ptr->setStartPlayerPositions(i, j, m_player_id);
            }
        }

        m_model_ptr->setEdgePosition(edge_position);
        m_model_ptr->setFinalPlayerPositions(m_player_id, edge_position);
        break;
    }

      case EdgePositions::TOP_RIGHT: {
        for (int i = m_model_ptr->getMatrix().size() - (NUMBER_OF_ROWS + 1); i < m_model_ptr->getMatrix().size() - 1; ++i) {
            for (int j = 1; j < NUMBER_OF_COLUMNS + 1; ++j) {
                m_model_ptr->getMatrix()[i][j] = m_label;
                m_model_ptr->setStartPlayerPositions(i, j, m_player_id);
            }
        }
  
        m_model_ptr->setEdgePosition(edge_position);
        m_model_ptr->setFinalPlayerPositions(m_player_id, edge_position);
        break;
    }

    case EdgePositions::BOTTOM_RIGHT: {
        for (int i = m_model_ptr->getMatrix().size() - (NUMBER_OF_ROWS + 1); i < m_model_ptr->getMatrix().size() - 1; ++i) {
            for (int j = m_model_ptr->getMatrix().size() - (NUMBER_OF_COLUMNS + 1); j < m_model_ptr->getMatrix().size() - 1; ++j) {
                m_model_ptr->getMatrix()[i][j] = m_label;
                m_model_ptr->setStartPlayerPositions(i, j, m_player_id);
            }
        }

        m_model_ptr->setEdgePosition(edge_position);
        m_model_ptr->setFinalPlayerPositions(m_player_id, edge_position);
        break;
    } 
    }
   
}






