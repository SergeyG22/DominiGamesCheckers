#pragma once
#include <list>
#include <memory>
#include "../../include/Graphics/graphic.h"
#include "../../include/Model/board.h"
#include "../../include/Model/step.h"
#include "../config.h"

class Player {
    std::string m_name;
public:
    std::string getName() const;
    Player(std::string, std::shared_ptr<Board>);
    virtual ~Player() = default;
	virtual std::shared_ptr<Step> nextStep(std::shared_ptr<Board>&) = 0;
protected:
    static int player_id;
    EdgePositions m_edge_position;
    std::shared_ptr<Board> m_model_ptr;
};



