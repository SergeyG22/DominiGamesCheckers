#include "../include/View/window.h"
#include "../include/Controller/pk_controller.h"
#include "../include/Controller/player_user.h"
#include "../include/Controller/player_ai.h"
#include "../include/Model/board.h"
#include "../include/Facades/game.h"

int main() {
	setlocale(LC_ALL,"russian");   
    std::shared_ptr<Game> game = std::make_unique<Game>();
    game->gameLoop();    
	return 0;
}


