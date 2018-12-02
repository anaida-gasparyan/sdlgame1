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

class Game {
public:
    Game() {}
    ~Game() {}
    
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    
    void texture(const std::string asset, int srcRectW, int srcRectH);
    
    // a function to access the private running variable
    bool isRunning() { return m_bRunning; }
    
private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    SDL_Texture* m_pTexture; // the new SDL_Texture variable
    SDL_Rect m_sourceRectangle; // the first rectangle
    SDL_Rect m_destinationRectangle; // another rectangle
    
    bool m_bRunning;
};

//#endif /* Game_hpp */
#endif /* defined(__Game__) */
