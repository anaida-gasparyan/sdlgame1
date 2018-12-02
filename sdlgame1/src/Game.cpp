//
//  Game.cpp
//  sdlgame1
//
//  Created by Anaida Gasparyan on 11/24/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
#include "TextureManager.h"

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
    
    TextureManager::Instance().load("assets/animate.bmp", "animate", m_pRenderer);
    
    m_bRunning = true; // everything inited successfully, start the main loop
    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
    
    TextureManager::Instance().draw("animate", 0, 0, 128, 82, 0, 0, m_pRenderer);
    TextureManager::Instance().draw("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
    
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean(){
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::update() {
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
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
