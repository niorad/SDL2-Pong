#include "Results.h"
//http://www.sdltutorials.com/sdl-ttf
Results::Results() : GameObject(0, 0, 0, 0) {
    uni = TTF_OpenFont("assets/uni.ttf", 64);
    updateText("Pongy Pongface");
}

void Results::draw() {
    SDL_RenderCopy(_Game::Instance()->getRenderer(), textTexture, nullptr, &srcRect);
}

void Results::update() {
}

void Results::updateText(string newText) {
    SDL_Surface* number = TTF_RenderText_Solid(uni, newText.c_str(), {0, 0, 0, 255});
    textTexture = SDL_CreateTextureFromSurface(_Game::Instance()->getRenderer(), number);
    SDL_QueryTexture(textTexture, NULL, NULL, &srcRect.w, &srcRect.h);
    srcRect.x = _Game::Instance()->getGameWidth() / 2 - 68;
    srcRect.y = 0;
    SDL_FreeSurface(number);
}

void Results::clean() {
    TTF_CloseFont(uni);
}
