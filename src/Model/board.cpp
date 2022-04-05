#include "../../include/Model/board.h"

Board::Board() {
	for (int i = 0; i < m_matrix.size(); ++i) {  m_matrix[i][0] = '0'; }
	for (int i = 0; i < m_matrix.size(); ++i) {  m_matrix[0][i] = '0'; }
	for (int i = 0; i < m_matrix.size(); ++i) {  m_matrix[i][m_matrix.size() - 1] = '0'; }
	for (int i = 0; i < m_matrix.size(); ++i) {  m_matrix[m_matrix.size() - 1][i] = '0'; }
}

std::map<int, std::deque<std::pair<int, int>>>& Board::getInnerSquarePositions() {
	return m_inner_square_positions;
}

std::map<int, std::deque<std::pair<int, int>>>& Board::getOuterSquarePositions() {
	return m_outer_square_positions;
}

void Board::setEdgePosition(EdgePositions edge_position) {
	m_edge_positions.emplace_back(edge_position);
}

void Board::setFinalPlayerPositions(int player_id, EdgePositions edge_position) {

	switch (edge_position) {
		
	case EdgePositions::BOTTOM_RIGHT: { 
		for (int i = 1; i < NUMBER_OF_ROWS + 1; ++i) {
			for (int j = 1; j < NUMBER_OF_COLUMNS + 1; ++j) {
				m_end_player_positions[player_id].emplace_back(std::make_pair(i, j));
			}
		}
		setOuterSquarePositions(player_id, edge_position);
		setInnerSquarePositions(player_id, edge_position);
		setIndexesObjects(player_id, edge_position);
		break;
	}

	case EdgePositions::TOP_RIGHT: {

		for (int i = 1; i < NUMBER_OF_ROWS + 1; ++i) {
			for (int j = (FIELD_WIDTH + 2) - (NUMBER_OF_COLUMNS + 1); j < (FIELD_WIDTH + 2) - 1; ++j) {
				m_end_player_positions[player_id].emplace_back(std::make_pair(i, j));
				
			}
		}
		setOuterSquarePositions(player_id, edge_position);
		setInnerSquarePositions(player_id, edge_position);
		setIndexesObjects(player_id, edge_position);
		break;
	}

	case EdgePositions::BOTTOM_LEFT: {

		for ( int i = (FIELD_WIDTH + 2) - (NUMBER_OF_ROWS + 1); i < (FIELD_WIDTH + 2) - 1; ++i) {
			for (int j = 1; j < NUMBER_OF_COLUMNS + 1; ++j) {
				m_end_player_positions[player_id].emplace_back(std::make_pair(i, j));
			}
		}
		setOuterSquarePositions(player_id, edge_position);
		setInnerSquarePositions(player_id, edge_position);
		setIndexesObjects(player_id, edge_position);
		break;
	}

	case EdgePositions::TOP_LEFT: { 
		for ( int i = (FIELD_WIDTH + 2) - (NUMBER_OF_ROWS + 1); i < (FIELD_WIDTH + 2) - 1; ++i) {
			for ( int j = (FIELD_WIDTH + 2) - (NUMBER_OF_COLUMNS + 1); j < (FIELD_WIDTH + 2) - 1; ++j) {
				m_end_player_positions[player_id].emplace_back(std::make_pair(i, j));
			}
		}
		setOuterSquarePositions(player_id, edge_position);
		setInnerSquarePositions(player_id, edge_position);
		setIndexesObjects(player_id, edge_position);
		break;
	}

	}

}

void Board::setStartPlayerPositions(int pos_x, int pos_y, int player_id) {
	m_player_positions[player_id].emplace_back(std::make_pair(pos_x, pos_y));
}

void Board::changePlayerPosition(int player_id, int number_object, int pos_x, int pos_y) {
	m_player_positions[player_id][number_object].first = pos_x;
	m_player_positions[player_id][number_object].second = pos_y;
}

void Board::changeFinalPlayerPositions(int player_id, int number_object, int pos_x, int pos_y) {
	m_end_player_positions[player_id][number_object].first = pos_x;
	m_end_player_positions[player_id][number_object].second = pos_y;
}

std::map<int, std::vector<std::pair<int, int>>> Board::getPlayerPositions() const {
	return m_player_positions;
}

std::map<int, std::vector<std::pair<int, int>>> Board::getEndPlayerPositions() const {
	return m_end_player_positions;
}

std::map<int, std::deque<int>>& Board::getIndexesOfObjects() {
	return m_indexes_objects;
}

std::vector<EdgePositions> Board::getEdgePositions() const {
	return m_edge_positions;
}

void Board::setOuterSquarePositions(int player_id, EdgePositions edge_position) {
	switch (edge_position) {

	case EdgePositions::BOTTOM_RIGHT: {
		std::vector<int>indexes_outer{ 2,6,5,7,8 };
		addOuterSquarePositions(indexes_outer, player_id);
		break;
		}
	case EdgePositions::TOP_RIGHT: {

		std::vector<int>indexes_outer{ 0,8,3,7,6 };
		addOuterSquarePositions(indexes_outer, player_id);
		break;
	}
	case EdgePositions::BOTTOM_LEFT: {

		std::vector<int>indexes_outer{ 0,8,1,5,2 };
		addOuterSquarePositions(indexes_outer, player_id);
		break;
	}
	case EdgePositions::TOP_LEFT: {
		std::vector<int>indexes_outer{ 2,6,1,3,0 };
		addOuterSquarePositions(indexes_outer,player_id);
		break;
	}

	}
}

void Board::setInnerSquarePositions(int player_id, EdgePositions edge_position) {

	switch (edge_position) {

	case EdgePositions::BOTTOM_RIGHT: {
		 std::vector<int>indexes_inner{ 0,3,1,4 };
		 addInnerSquarePositions(indexes_inner, player_id);
		 break;
	}

	case EdgePositions::TOP_RIGHT: {
		std::vector<int>indexes_inner{ 2,5,1,4 };
		addInnerSquarePositions(indexes_inner, player_id);
		break;
	}

	case EdgePositions::BOTTOM_LEFT: {
		std::vector<int>indexes_inner{ 6,3,7,4 };
		addInnerSquarePositions(indexes_inner, player_id);
		break;
	}

	case EdgePositions::TOP_LEFT: {
		std::vector<int>indexes_inner{ 8,5,7,4 };
		addInnerSquarePositions(indexes_inner, player_id);
		break;
	}

	}
}

void Board::restoreOuterSquarePositions(int player_id) {
	m_outer_square_positions[player_id] = m_backup_outer_square_positions;
}

void Board::restoreInnerSquarePositions(int player_id) {
	m_inner_square_positions[player_id] = m_backup_inner_sqaure_positions;
}

void Board::setIndexesObjects(int player_id, EdgePositions edge_position) {

	switch (edge_position) {

	case EdgePositions::BOTTOM_RIGHT: {
		std::deque<int>indexes_objects{ 0,1,3,4,2,6,5,7,8 };
		m_indexes_objects[player_id] = indexes_objects;
		break;
	}

	case EdgePositions::TOP_RIGHT: {
		std::deque<int>indexes_objects{ 2,5,1,4,0,8,3,7,6 };
		m_indexes_objects[player_id] = indexes_objects;
		break;
	}

	case EdgePositions::BOTTOM_LEFT: {
		std::deque<int>indexes_objects{ 6,3,7,4,0,8,1,5,2 };
		m_indexes_objects[player_id] = indexes_objects;
		break;
	}

	case EdgePositions::TOP_LEFT: {
		std::deque<int>indexes_objects{ 8,5,7,4,2,6,1,3,0 };
		m_indexes_objects[player_id] = indexes_objects;
		break;
	}

	}
}

void Board::addOuterSquarePositions(const std::vector<int>& indexes_outer, int player_id) {
	for (int i = 0; i < indexes_outer.size(); ++i) {
		int x = m_end_player_positions[player_id][indexes_outer[i]].first;
		int y = m_end_player_positions[player_id][indexes_outer[i]].second;
		m_outer_square_positions[player_id].emplace_back(x, y);
	}
	m_backup_outer_square_positions = m_outer_square_positions[player_id];
}

void Board::addInnerSquarePositions(const std::vector<int>& indexes_inner, int player_id) {
	for (int i = 0; i < indexes_inner.size(); ++i) {
		int x = m_end_player_positions[player_id][indexes_inner[i]].first;
		int y = m_end_player_positions[player_id][indexes_inner[i]].second;
		m_inner_square_positions[player_id].emplace_back(x, y);
	}
	m_backup_inner_sqaure_positions = m_inner_square_positions[player_id];
}

std::vector<std::vector<char>> &Board::getMatrix() {
    return m_matrix;
}



