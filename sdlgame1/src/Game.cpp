//
//  Game.cpp
//  sdlgame1
//
//  Created by Anaida Gasparyan on 11/24/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width,
                int height, int flags) {
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }

    // init the window;
    if ((m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags)) == 0) {
        std::cout << "window init fail\n";
        return false; // window init fail
    }

    if ((m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0)) == 0) { // renderer init success
        std::cout << "renderer init fail\n";
        return false; // renderer init fail
    }
    
//    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    
//    texture("assets/rider.bmp", 50, 50);
    texture("assets/animate.bmp", 128, 82);
    
    m_bRunning = true; // everything inited successfully, start the main loop
    return true;
}

void Game::texture(const std::string asset, int srcRectW, int srcRectH) {
    SDL_Surface* pTempSurface = SDL_LoadBMP(asset.c_str());
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    
    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
    m_sourceRectangle.w = srcRectW;
    m_sourceRectangle.h = srcRectH;
    
    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
    
//    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
//    SDL_Point center = {20, 20};
    SDL_RenderCopyEx(m_pRenderer, m_pTexture,
                     &m_sourceRectangle, &m_destinationRectangle,
                     45, 0, SDL_FLIP_NONE);
//    SDL_RenderCopy(m_pRenderer, m_pTexture, 0, 0);
    
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean(){
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::update() {
    /*
     This code will (every 100 ms) shift the x value of our source rectangle by 128 pixels,
     multiplied by the current frame we want, giving us the correct position
     SDL_GetTicks() - to find out the amount of ms since SDL was initialized
     100 - amount of time (in ms) we want between frames
     128 - the width of frame
     6 - amount of frames in animation
     */
    m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
    }
}
