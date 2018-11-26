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
    
    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
    if (pTempSurface == 0) {
        std::cout << "surface creation fail\n";
        return false; // renderer init fail
    }
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    if (m_pTexture == 0) {
        std::cout << "m_pTexture fail\n";
        return false; // renderer init fail
    }
    SDL_FreeSurface(pTempSurface);
//    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
//    m_sourceRectangle.w = 50;
//    m_sourceRectangle.h = 50;
//
//    m_destinationRectangle.x = m_sourceRectangle.x = 0;
//    m_destinationRectangle.y = m_sourceRectangle.y = 0;
//    m_destinationRectangle.w = m_sourceRectangle.w;
//    m_destinationRectangle.h = m_sourceRectangle.h;
    
    m_bRunning = true; // everything inited successfully, start the main loop
    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
    
//    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderCopy(m_pRenderer, m_pTexture, 0, 0);
    
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean(){
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
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
