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
#include "Player.h"
#include "Enemy.h"

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
    
    // load textures
    TextureManager::Instance().load("assets/animate.bmp", "animate", m_pRenderer);
    
    m_player1 = new Player();
    m_player1->load(100, 100, 128, 82, "animate");
    m_gameObjects.push_back(m_player1);
    
    m_player2 = new Enemy();
    m_player2->load(0, 0, 128, 82, "animate");
    m_gameObjects.push_back(m_player2);
    
    m_bRunning = true;
    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
    
    for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw(m_pRenderer);
    }
    
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean(){
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::update() {
    for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
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
