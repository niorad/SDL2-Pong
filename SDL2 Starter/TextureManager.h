//
//  TextureManager.hpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 04.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp
#pragma once

#include <stdio.h>
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

using namespace std;

class TextureManager {

public:

    static TextureManager* Instance() {
        if(instance == 0) {
            instance = new TextureManager();
        }
        return instance;
    }
    
    bool load(string fileName, string id, SDL_Renderer* renderer);
    
    void draw(string id, int x, int y, int w, int h, double scale, double r, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void drawFrame(string id, int x, int y, int w, int h, double scale, int currentRow, int currentFrame, double r, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void clearFromTextureMap(string id);
    
    map<string, SDL_Texture*> textureMap;
    
private:
    static TextureManager* instance;
    
    TextureManager() {}
    ~TextureManager() {}
    
};

typedef TextureManager _TextureManager;

#endif /* TextureManager_hpp */
