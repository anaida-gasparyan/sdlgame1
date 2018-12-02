//
//  GameObject.h
//  sdlgame1
//
//  Created by Anaida Gasparyan on 12/2/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h
#include <SDL.h>
#include <string>

class GameObject {
    
public:
    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();
    
protected:
    std::string m_textureID;

    int m_currentFrame;
    int m_currentRow;

    int m_x;
    int m_y;

    int m_width;
    int m_height;
};

#endif /* GameObject_h */
