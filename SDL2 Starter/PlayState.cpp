#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "GameStateMachine.h"
#include <sstream>
#include <string>


const string PlayState::playID = "PLAY";


bool PlayState::onEnter() {
    cout << "Entering PlayState" << endl;
    player = new Paddle(50, 180, 15, 80, true);
    enemy = new Paddle(_Game::Instance()->getGameWidth() - 65, 180, 15, 80, false);
    ball = new Ball(_Game::Instance()->getGameWidth() / 2 - 10, _Game::Instance()->getGameHeight() / 2 - 10, 20, 20);
    results = new Results();
    fieldMiddleLine = {_Game::Instance()->getGameWidth() / 2, 0, 1, _Game::Instance()->getGameHeight()};
    fieldMiddlePoint = {_Game::Instance()->getGameWidth() / 2 - 5, _Game::Instance()->getGameHeight() / 2 - 5, 11, 11};
    collisionIsSharp = true;
    scorePlayer = 0;
    scoreEnemy = 0;
    totalCollisions = 0;
    updateResults();

    //initing items
    items[0] = new Item(10, 200, accelerate);
    items[1] = new Item(50, 200, decelerate);
    items[2] = new Item(100, 200, shrinkBall);
    items[3] = new Item(150, 200, shrinkPaddle);
    items[4] = new Item(200, 200, growBall);

    //loading sounds
    blip = NULL;
    blip = Mix_LoadWAV("assets/blip.wav");
    pickup = NULL;
    pickup = Mix_LoadWAV("assets/item.wav");
    point = NULL;
    point = Mix_LoadWAV("assets/point.wav");

    if(blip == NULL || pickup == NULL) {
        cout << "There was a probläm loading a sound" << endl;
        return false;
    }

    return true;
}


void PlayState::update() {

    //Your common gameObject updates

    player->update();
    enemy->update();
    enemy->setCenterY(ball->getCenterY());
    ball->update();
    for(int i = 0; i < ITEM_COUNT; i++) {
        items[i]->update();
    }


    //Ball out of bounds collisions

    if(ball->isOutOfFieldLeft) {
        scoreEnemy++;
        updateResults();
        resetBall();
    } else if(ball->isOutOfFieldRight) {
        scorePlayer++;
        updateResults();
        resetBall();
    }


    //Item pickups
    for(int i = 0; i < ITEM_COUNT; i++) {
        if(items[i]->checkOverlap(ball) && items[i]->isActive()) {
            cout << "Oh my god its overlapping!" << endl;
            cout << "Picked up item: " << items[i]->getKind() << endl;
            Mix_PlayChannel(-1, pickup, 0);
            items[i]->setInactive();
        }
    }


    //Paddle Collisions (Player and Enemy Paddle)

    collisionDirection ballTouchingPlayer = ball->checkCollisionDirection(player);
    collisionDirection ballTouchingEnemy = ball->checkCollisionDirection(enemy);
    collisionDirection ballTouchingDirection = NONE;

    GameObject* objectTouchingBall;

    if(ballTouchingPlayer != NONE) {
        Mix_PlayChannel(-1, blip, 0);
        objectTouchingBall = player;
        ballTouchingDirection = ballTouchingPlayer;
        ball->setColor(150, 150, 255);
        ball->changeSpeed(1.05);
        totalCollisions++;
        cout << "Total collisions: " << totalCollisions << endl;
    } else if(ballTouchingEnemy != NONE) {
        Mix_PlayChannel(-1, blip, 0);
        objectTouchingBall = enemy;
        ballTouchingDirection = ballTouchingEnemy;
        ball->setColor(255, 100, 100);
        totalCollisions++;
        cout << "Total collisions: " << totalCollisions << endl;
    } else {
        objectTouchingBall = nullptr;
    }

    if(!collisionIsSharp && ballTouchingPlayer == NONE && ballTouchingEnemy == NONE) {
        collisionIsSharp = true;
    }

    if(collisionIsSharp) {
        switch(ballTouchingDirection) {
            case NONE:
                break;
            case TOP:
            case BOTTOM:
                ball->switchYVel();
                collisionIsSharp = false;
                break;
            case LEFT:
                ball->placeBefore(objectTouchingBall);
                collisionIsSharp = false;
                handleBallCollision(objectTouchingBall);
                break;
            case RIGHT:
                ball->placeAfter(objectTouchingBall);
                collisionIsSharp = false;
                handleBallCollision(objectTouchingBall);
                break;
        }
    }
}


void PlayState::render() {

    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 133, 135, 128, 255);
    SDL_RenderClear(_Game::Instance()->getRenderer());

    drawField();
    for(int i = 0; i < ITEM_COUNT; i++) {
        items[i]->draw();
    }
    player->draw();
    enemy->draw();
    ball->draw();
    results->draw();
}


void PlayState::handleBallCollision(GameObject * paddle) {
    // if the ball is going to the right, dir is 1, to left: -1
    int dir = ball->getVel().getX() > 0 ? 1 : -1;

    // calculate the new angle, in which the ball is going to ricochet. the old angle doesn't matter
    float rotationAmount = ((paddle->getCenterY() - ball->getCenterY()) / -40);

    // get the current speed of the ball
    float currentXVel = sqrt(pow(ball->getVel().getX(), 2) + pow(ball->getVel().getY(), 2));

    // calculate the new vector for the reflected ball
    float newXVel = currentXVel * cos(rotationAmount);
    float newYVel = currentXVel * sin(rotationAmount);

    ball->receiveImpulse(newXVel, newYVel);

    if(dir == 1) {
        ball->switchXVel();
    }
}


void PlayState::drawField() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 100, 100, 100, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &fieldMiddleLine);
}

void PlayState::resetBall() {
    ball->reset(_Game::Instance()->getGameWidth() / 2 - 10, _Game::Instance()->getGameHeight() / 2 - 10);
    Mix_PlayChannel(-1, point, 0);
}

void PlayState::updateResults() {
    stringstream resultString;
    resultString << scorePlayer << "  " << scoreEnemy;
    results->updateText(resultString.str());
}


bool PlayState::onExit() {
    player->clean();
    enemy->clean();
    ball->clean();
    results->clean();
    Mix_FreeChunk(blip);
    cout << "Exiting PlayState" << endl;
    return false;
}

void PlayState::onKeyDown(SDL_Event* e) {
    const int current_key = e->key.keysym.scancode;
    if(current_key == 81) {
        player->startMovingDown();
    } else if(current_key == 82) {
        player->startMovingUp();
    }
}

void PlayState::onKeyUp(SDL_Event* e) {
    const int current_key = e->key.keysym.scancode;
    if(current_key == 81) {
        player->stopMovingDown();
    } else if(current_key == 82) {
        player->stopMovingUp();
    }
}

