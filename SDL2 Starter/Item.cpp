
#include "Item.h"

Item::Item(kindOfItem _kind) : GameObject(0, 0, 20, 20){
    pos.setX(0);
    pos.setY(0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 15;
    rect.h = 15;
    active = false;
    kind = _kind;

    updateLines();

    switch (kind) {
        case item_growBall:
            itemColor.r = itemColor.g = itemColor.b = 10;
            break;
        case item_shrinkBall:
            itemColor.r = itemColor.g = itemColor.b = 10;
            break;
        case item_accelerate:
            itemColor.r = itemColor.g = 0;
            itemColor.b = 200;
            break;
        case item_decelerate:
            itemColor.b = itemColor.g = 0;
            itemColor.r = 200;
            break;
        case item_growPaddle:
            itemColor.r = itemColor.g = itemColor.b = 10;
            break;
        case item_shrinkPaddle:
            itemColor.r = itemColor.g = itemColor.b = 10;
            break;
    }
}

void Item::update() {
    rect.x = pos.getX();
    rect.y = pos.getY();
}

void Item::draw() {
    if(!active) return;
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), itemColor.r, itemColor.g, itemColor.b, 255);
    SDL_RenderDrawLines(_Game::Instance()->getRenderer(), trigPoints, 4);
//    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &rect);
}

void Item::setActive(float x, float y) {
    pos.setX(x);
    pos.setY(y);
    updateLines();
    active = true;
}

void Item::setInactive() {
    active = false;
}

void Item::updateLines() {
    trigPoints[0].x = pos.getX();
    trigPoints[0].y = pos.getY();

    trigPoints[1].x = pos.getX() + rect.w;
    trigPoints[1].y = pos.getY() + (rect.h / 2);

    trigPoints[2].x = pos.getX();
    trigPoints[2].y = pos.getY() + rect.h;

    trigPoints[3].x = pos.getX();
    trigPoints[3].y = pos.getY();
}

void Item::clean() {
    GameObject::clean();
}
