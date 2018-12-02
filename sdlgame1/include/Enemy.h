//
//  Enemy.h
//  sdlgame1
//
//  Created by Anaida Gasparyan on 12/2/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#include "GameObject.h"

class Enemy : public GameObject { // inherit from GameObject
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
};

#endif /* Enemy_h */
