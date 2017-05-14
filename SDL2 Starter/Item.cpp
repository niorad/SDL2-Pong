
#include "Item.h"

Item::Item(int x, int y, kindOfItem _kind) : GameObject(x, y, 20, 20){
    pos.setX(x);
    pos.setY(y);
    rect.x = x;
    rect.y = y;
    rect.w = 15;
    rect.h = 15;
    active = true;
    kind = _kind;
}

void Item::update() {

}

void Item::draw() {
    if(!active) return;
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 0, 100, 0, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &rect);
}

void Item::setInactive() {
    active = false;
}

void Item::clean() {
    GameObject::clean();
}
