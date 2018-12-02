//
//  Player.h
//  sdlgame1
//
//  Created by Anaida Gasparyan on 12/2/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "GameObject.h"

class Player : public GameObject { // inherit from GameObject
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
};

#endif /* Player_h */
