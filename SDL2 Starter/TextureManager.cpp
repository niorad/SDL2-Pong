//
//  TextureManager.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 04.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "TextureManager.h"
#include <iostream>

TextureManager* TextureManager::instance = 0;

bool TextureManager::load(string fileName, string id, SDL_Renderer* renderer) {
    SDL_Surface* tempSurf = IMG_Load(fileName.c_str());
    
    if(tempSurf == 0) {
        cout << "Could not load image named " << fileName.c_str() << "." << endl;
        return false;
    }
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurf);
    SDL_FreeSurface(tempSurf);
    
    if(texture != 0) {
        cout << "Texture loaded successfully: " << fileName.c_str() << endl;
        textureMap[id] = texture;
        return true;
    }
    
    cout << "Could not create texture from surface: " << fileName.c_str() << endl;
    return false;
}

void TextureManager::draw(string id, int x, int y, int w, int h, double scale, double r, SDL_Renderer* renderer, SDL_RendererFlip flip) {
    
    SDL_Rect srcRect, destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = w;
    srcRect.h = destRect.h = h;
    destRect.x = x;
    destRect.y = y;
    destRect.w *= scale;
    destRect.h *= scale;
    
    SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, r, NULL, flip);

}

void TextureManager::drawFrame(string id, int x, int y, int w, int h, double scale, int currentRow, int currentFrame, double r, SDL_Renderer* renderer, SDL_RendererFlip flip) {

    SDL_Rect srcRect, destRect;
    srcRect.x = w * currentFrame;
    srcRect.y = h * currentRow;
    srcRect.w = destRect.w = w;
    srcRect.h = destRect.h = h;
    destRect.x = x;
    destRect.y = y;
    destRect.w *= scale;
    destRect.h *= scale;
    
    SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, r, NULL, flip);
}

void TextureManager::clearFromTextureMap(string id) {
    textureMap.erase(id);
}




