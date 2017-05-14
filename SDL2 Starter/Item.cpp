
#include "Item.h"

Item::Item(int x, int y, kindOfItem kind) : GameObject(x, y, 20, 20){
    pos.setX(x);
    pos.setY(y);
    rect.x = x;
    rect.y = y;
    rect.w = 5;
    rect.h = 5;
}

void Item::update() {

}

void Item::draw() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 0, 100, 0, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &rect);
}

void Item::clean() {
    GameObject::clean();
}
