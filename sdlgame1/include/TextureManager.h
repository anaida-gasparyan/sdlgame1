//
//  TextureManager.h
//  sdlgame1
//
//  Created by Anaida Gasparyan on 12/2/18.
//  Copyright © 2018 Anaida Gasparyan. All rights reserved.
//

#ifndef TextureManager_h
#define TextureManager_h

#include <SDL.h>
#include <string>
#include <map>

class TextureManager {
    
// Start Singleton
public:
    static TextureManager& Instance() {
        static TextureManager instance;
        return instance;
    }
    TextureManager(TextureManager const&) = delete;
    TextureManager& operator=(TextureManager const&) = delete;
private:
    TextureManager(){}
// End Singleton
    
public:
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    
    void draw(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
              SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif /* TextureManager_h */
