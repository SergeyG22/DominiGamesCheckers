#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <deque>
#include <list>
#include "../config.h"

class Board {
	std::vector<std::vector<char>>m_matrix { FIELD_WIDTH + 2, std::vector <char>(FIELD_HEIGHT + 2, ' ')};
	std::vector<EdgePositions>m_edge_positions;
	std::map<int, std::deque<int>>m_indexes_objects;
	std::map<int, std::vector<std::pair<int, int>>>m_player_positions;
	std::map<int, std::vector<std::pair<int, int>>>m_end_player_positions;
	std::map<int, std::deque<std::pair<int, int>>>m_outer_square_positions;
	std::map<int, std::deque<std::pair<int, int>>>m_inner_square_positions;
	std::deque<std::pair<int, int>>m_backup_outer_square_positions;
	std::deque<std::pair<int, int>>m_backup_inner_sqaure_positions;
	void setIndexesObjects(int, EdgePositions);
	void setOuterSquarePositions(int, EdgePositions);
	void setInnerSquarePositions(int, EdgePositions);
	void addOuterSquarePositions(const std::vector<int>&, int);
	void addInnerSquarePositions(const std::vector<int>&, int);
public:  
	Board();
	void restoreOuterSquarePositions(int);
	void restoreInnerSquarePositions(int);
	std::vector<std::vector<char>>& getMatrix();
	std::map<int, std::deque<std::pair<int, int>>>& getInnerSquarePositions();
	std::map<int, std::deque<std::pair<int, int>>>& getOuterSquarePositions();
	std::map<int, std::vector<std::pair<int, int>>> getPlayerPositions() const;
	std::map<int, std::vector<std::pair<int, int>>> getEndPlayerPositions() const;
	std::map<int, std::deque<int>>& getIndexesOfObjects();
	std::vector<EdgePositions> getEdgePositions() const;
	void setEdgePosition(EdgePositions);
	void setFinalPlayerPositions(int, EdgePositions);
	void setStartPlayerPositions(int, int, int);
	void changePlayerPosition(int, int, int, int);
	void changeFinalPlayerPositions(int, int, int, int);
};

