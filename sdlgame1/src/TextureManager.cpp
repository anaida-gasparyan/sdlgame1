//
//  TextureManager.cpp
//  sdlgame1
//
//  Created by Anaida Gasparyan on 12/2/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#include <stdio.h>
#include "TextureManager.h"

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer) {
    
//    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    SDL_Surface* pTempSurface = SDL_LoadBMP(fileName.c_str());
    if (pTempSurface == 0) {
        return false;
    }
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    
    if (pTexture == 0) {
        return false;
    }

    m_textureMap[id] = pTexture;
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
                               SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    
    SDL_Rect srcRect{width * currentFrame, height * currentRow, width, height};
    SDL_Rect destRect{x, y, width, height};

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
