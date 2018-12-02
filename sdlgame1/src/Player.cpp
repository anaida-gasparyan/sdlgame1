//
//  Player.cpp
//  sdlgame1
//
//  Created by Anaida Gasparyan on 12/2/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#include <stdio.h>
#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureID) {
    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer) {
    GameObject::draw(pRenderer);
}

void Player::update() {
    m_x -= 1;
}
