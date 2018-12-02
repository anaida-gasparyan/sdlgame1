//
//  main.cpp
//  game-1
//
//  Created by Anaida Gasparyan on 11/24/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#include "Game.hpp"

int main(int argc, char* argv[]) {
    Game* game = new Game();
    game->init("Version 1",
                 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                 640, 480, 0);
    
    while (game->isRunning()) {
        game->handleEvents();
        game->update();
        game->render();
        
        SDL_Delay(10); // add the delay
    }
    
    game->clean();
    return 0;
}
