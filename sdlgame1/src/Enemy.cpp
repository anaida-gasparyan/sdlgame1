//
//  Enemy.cpp
//  sdlgame1
//
//  Created by Anaida Gasparyan on 12/2/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#include <stdio.h>
#include "Enemy.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID) {
    GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer) {
    GameObject::draw(pRenderer);
}

void Enemy::update() {
    m_y += 1;
    m_x += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
