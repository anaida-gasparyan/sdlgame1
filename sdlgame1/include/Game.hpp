//
//  Game.hpp
//  sdlgame1
//
//  Created by Anaida Gasparyan on 11/24/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

//#ifndef Game_hpp
//#define Game_hpp

#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <string>
#include <vector>
#include "GameObject.h"

class Game {
public:
    Game() {}
    ~Game() {}
    
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    
    // a function to access the private running variable
    bool isRunning() { return m_bRunning; }
    
private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    GameObject* m_player1;
    GameObject* m_player2;
    
    std::vector<GameObject*> m_gameObjects;
    
    bool m_bRunning;
};

//#endif /* Game_hpp */
#endif /* defined(__Game__) */
