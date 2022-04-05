#include "../../include/Controller/player_ai.h"

int PlayerAi::activateRandomForm() {
    int object_number = 0;
    std::random_device device;
    std::mt19937 mt(device());
    std::uniform_int_distribution<std::mt19937::result_type>object(0, m_model_ptr->getIndexesOfObjects()[player_id].size() - 1);
    object_number = object(mt);
    return object_number;
}

void PlayerAi::isFormAvailable(){
    
    switch (m_current_active_object) {
    case true: {
        if (move(m_number_of_active_object)) {
            return;
        }
        break;
     }
    case false: {
        if (move(m_model_ptr->getIndexesOfObjects()[player_id][activateRandomForm()])) {
            return;
        }
        break;
        }
    }
    
    for (int index = 0; index <= m_model_ptr->getIndexesOfObjects()[player_id].size() - 1; ++index) {   //try to move each object
        int object_number = m_model_ptr->getIndexesOfObjects()[player_id][index];

        if (move(object_number)) {
            return;
        }
    }
    
    m_model_ptr->restoreInnerSquarePositions(player_id);
    m_model_ptr->restoreOuterSquarePositions(player_id);

    std::cout << "\n";
    std::cout << "фигуры не могут двигаться!\n" << '\n';
}

bool PlayerAi::move(int object_number) {

   int current_pos_x = m_model_ptr->getPlayerPositions()[player_id][object_number].first;
   int current_pos_y = m_model_ptr->getPlayerPositions()[player_id][object_number].second - 1;

       if (m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != '0' &&
           m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'p' &&
           m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'a'
           )  {
                   if (m_model_ptr->getPlayerPositions()[player_id][object_number].second > m_model_ptr->getEndPlayerPositions()[m_player_id][object_number].second) {
                        m_model_ptr->getMatrix()[m_model_ptr->getPlayerPositions()[player_id][object_number].first][m_model_ptr->getPlayerPositions()[player_id][object_number].second] = ' ';
                        m_model_ptr->changePlayerPosition(player_id, object_number, current_pos_x, current_pos_y--);
                        m_model_ptr->getMatrix()[m_model_ptr->getPlayerPositions()[player_id][object_number].first][m_model_ptr->getPlayerPositions()[player_id][object_number].second] = 'a';
                        findFreePosition(player_id, object_number);
                        deactivateObject(object_number);
                        return true;
                   }
       }
                                                                              
       current_pos_x = m_model_ptr->getPlayerPositions()[player_id][object_number].first;
       current_pos_y = m_model_ptr->getPlayerPositions()[player_id][object_number].second + 1;
           if (m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != '0' &&
               m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'p' &&
               m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'a'
               ) {

                   if (m_model_ptr->getPlayerPositions()[player_id][object_number].second < m_model_ptr->getEndPlayerPositions()[m_player_id][object_number].second) {
                       m_model_ptr->getMatrix()[m_model_ptr->getPlayerPositions()[player_id][object_number].first][m_model_ptr->getPlayerPositions()[player_id][object_number].second] = ' ';
                       m_model_ptr->changePlayerPosition(player_id, object_number, current_pos_x, current_pos_y++);
                       m_model_ptr->getMatrix()[m_model_ptr->getPlayerPositions()[player_id][object_number].first][m_model_ptr->getPlayerPositions()[player_id][object_number].second] = 'a';
                       findFreePosition(player_id, object_number);
                       deactivateObject(object_number);
                       return true;
                   }

           }
                                                                                    
        current_pos_x = m_model_ptr->getPlayerPositions()[player_id][object_number].first - 1;
        current_pos_y = m_model_ptr->getPlayerPositions()[player_id][object_number].second;

            if (m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != '0' &&
                m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'p' &&
                m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'a'
                ) {                                           
                
                    if (m_model_ptr->getPlayerPositions()[player_id][object_number].first > m_model_ptr->getEndPlayerPositions()[m_player_id][object_number].first) {
                        m_model_ptr->getMatrix()[m_model_ptr->getPlayerPositions()[player_id][object_number].first][m_model_ptr->getPlayerPositions()[player_id][object_number].second] = ' ';
                        m_model_ptr->changePlayerPosition(player_id, object_number, current_pos_x--, current_pos_y);
                        m_model_ptr->getMatrix()[m_model_ptr->getPlayerPositions()[player_id][object_number].first][m_model_ptr->getPlayerPositions()[player_id][object_number].second] = 'a';
                        findFreePosition(player_id, object_number);
                        deactivateObject(object_number);
                        return true;
                    }

            }
                                                                                        
            current_pos_x = m_model_ptr->getPlayerPositions()[player_id][object_number].first + 1;
            current_pos_y = m_model_ptr->getPlayerPositions()[player_id][object_number].second;
         
            if (m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != '0' &&
                m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'p' &&
                m_model_ptr->getMatrix()[current_pos_x][current_pos_y] != 'a'
                )  {
                    if (m_model_ptr->getPlayerPositions()[player_id][object_number].first < m_model_ptr->getEndPlayerPositions()[m_player_id][object_number].first) {
                        m_model_ptr->getMatrix()[m_model_ptr->getPlayerPositions()[player_id][object_number].first][m_model_ptr->getPlayerPositions()[player_id][object_number].second] = ' ';
                        m_model_ptr->changePlayerPosition(player_id, object_number, current_pos_x++, current_pos_y);
                        m_model_ptr->getMatrix()[m_model_ptr->getPlayerPositions()[player_id][object_number].first][m_model_ptr->getPlayerPositions()[player_id][object_number].second] = 'a';
                        findFreePosition(player_id, object_number);
                        deactivateObject(object_number);
                        return true;
                    }
            }
          
    return false;
}

bool PlayerAi::findFreePosition(int player_id, int object_number) {

      std::pair<int,int>current_position = m_model_ptr->getPlayerPositions()[player_id][object_number];
      auto iterator = m_model_ptr->getOuterSquarePositions()[m_player_id];

      auto entry_to_square = std::find(iterator.begin(), iterator.end(), current_position);
      if (entry_to_square != std::end(iterator)) {
         
          for (int i = 0; i < m_model_ptr->getInnerSquarePositions()[m_player_id].size(); ++i) {
              
              int free_pos_x = m_model_ptr->getInnerSquarePositions()[m_player_id][i].first;
              int free_pos_y = m_model_ptr->getInnerSquarePositions()[m_player_id][i].second;

              if (m_model_ptr->getMatrix()[free_pos_x][free_pos_y] != '0' &&
                  m_model_ptr->getMatrix()[free_pos_x][free_pos_y] != 'p' &&
                  m_model_ptr->getMatrix()[free_pos_x][free_pos_y] != 'a'
                  ) {
                  auto iterator = std::find(numbers_of_objects_touched_square.begin(), numbers_of_objects_touched_square.end(), object_number);
                  if (iterator == numbers_of_objects_touched_square.end()) {
                      std::pair<int, int>free_pos = m_model_ptr->getInnerSquarePositions()[m_player_id][i];
                      swapEndPoints(object_number, free_pos);

                      m_number_of_active_object = object_number;
                      m_current_active_object = true;

                      if (!m_model_ptr->getInnerSquarePositions()[m_player_id].empty()) {
                           m_model_ptr->getInnerSquarePositions()[m_player_id].erase(m_model_ptr->getInnerSquarePositions()[m_player_id].begin() + i);
                      }

                      numbers_of_objects_touched_square.emplace_back(object_number);
                      break;
                    }
                      return true;
                  
              }
          }
          
          for (int index = 0; index < m_model_ptr->getOuterSquarePositions()[m_player_id].size(); ++index) {

              int free_pos_x = m_model_ptr->getOuterSquarePositions()[m_player_id][index].first;
              int free_pos_y = m_model_ptr->getOuterSquarePositions()[m_player_id][index].second;

              if (m_model_ptr->getMatrix()[free_pos_x][free_pos_y] != '0' &&
                  m_model_ptr->getMatrix()[free_pos_x][free_pos_y] != 'p' &&
                  m_model_ptr->getMatrix()[free_pos_x][free_pos_y] != 'a'
                  ) {

                 auto iterator =  std::find(numbers_of_objects_touched_square.begin(), numbers_of_objects_touched_square.end(), object_number);
                 if (iterator == numbers_of_objects_touched_square.end()) {
                     std::pair<int, int>free_pos = m_model_ptr->getOuterSquarePositions()[m_player_id][index];
                     swapEndPoints(object_number, free_pos);

                     m_number_of_active_object = object_number;
                     m_current_active_object = true;

                     if (!m_model_ptr->getOuterSquarePositions()[m_player_id].empty()) {
                         m_model_ptr->getOuterSquarePositions()[m_player_id].pop_front();
                     }

                    numbers_of_objects_touched_square.emplace_back(object_number);
                    break;
                 }
                  
                  return true;
              }
          }
      }
      return false;
}

void PlayerAi::swapEndPoints(int object_number, std::pair<int,int>free_pos) {
                                                                 
    for (int index = 0; index < m_model_ptr->getPlayerPositions()[player_id].size(); ++index) {  
        if (m_model_ptr->getEndPlayerPositions()[player_id][index] == free_pos) {        
            std::pair<int,int>final_coordinate = m_model_ptr->getEndPlayerPositions()[player_id][object_number];
            m_model_ptr->changeFinalPlayerPositions(player_id, index, final_coordinate.first, final_coordinate.second);
            m_model_ptr->changeFinalPlayerPositions(player_id, object_number, free_pos.first, free_pos.second);
            break;
        }
   }   
}

void PlayerAi::deactivateObject(int object_number) {  
    if (m_model_ptr->getPlayerPositions()[player_id][object_number] == m_model_ptr->getEndPlayerPositions()[player_id][object_number]) {
        auto iterator = m_model_ptr->getIndexesOfObjects()[player_id];
        auto number_of_object_to_be_deleted = std::find(iterator.begin(), iterator.end(), object_number);
        if (number_of_object_to_be_deleted != iterator.end()) {
            iterator.erase(number_of_object_to_be_deleted);
        }
            m_current_active_object = false;
       }
}


PlayerAi::PlayerAi(std::string name, std::shared_ptr<Board> model_ptr) : Player("AI " + name, model_ptr), m_player_id(++Player::player_id) {

}

std::shared_ptr<Step> PlayerAi::nextStep(std::shared_ptr<Board>& model_ptr) {
    std::cout << "Player ai step: \n";
    std::shared_ptr<Step> step = std::make_unique<Step>();
    isFormAvailable(); 
    return step;
}


void PlayerAi::createPlayer(const EdgePositions& edge_position) {

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





