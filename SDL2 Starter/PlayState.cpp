#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "GameStateMachine.h"


const string PlayState::playID = "PLAY";


bool PlayState::onEnter() {
    cout << "Entering PlayState" << endl;
    player = new Paddle(50, 180, 15, 80, true);
    enemy = new Paddle(_Game::Instance()->getGameWidth() - 65, 180, 15, 80, false);
    ball = new Ball(100, 300, 20, 20);
    results = new Results();
    fieldMiddleLine = {_Game::Instance()->getGameWidth() / 2, 0, 1, _Game::Instance()->getGameHeight()};
    fieldMiddlePoint = {_Game::Instance()->getGameWidth() / 2 - 5, _Game::Instance()->getGameHeight() / 2 - 5, 11, 11};
    collisionIsSharp = true;
    return true;
}


void PlayState::update() {
    player->update();
    enemy->update();
    enemy->setCenterY(ball->getCenterY());
    ball->update();
}


void PlayState::render() {

    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 133, 135, 128, 255);
    SDL_RenderClear(_Game::Instance()->getRenderer());

    collisionDirection ballTouchingPlayer = ball->checkCollisionDirection(player);
    collisionDirection ballTouchingEnemy = ball->checkCollisionDirection(enemy);
    collisionDirection ballTouchingDirection = NONE;

    GameObject* objectTouchingBall;

    if(ballTouchingPlayer != NONE) {
        objectTouchingBall = player;
        ballTouchingDirection = ballTouchingPlayer;
        results->updateText("Player has touched ball");
    } else if(ballTouchingEnemy != NONE) {
        objectTouchingBall = enemy;
        ballTouchingDirection = ballTouchingEnemy;
        results->updateText("Enemy has touched ball");
    } else {
        objectTouchingBall = nullptr;
    }

    if(!collisionIsSharp && !ball->checkOverlap(player) && !ball->checkOverlap(enemy)) {
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
            case RIGHT:
                collisionIsSharp = false;
                handleBallCollision(objectTouchingBall);
                break;
        }
    }
    drawField();
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
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &fieldMiddlePoint);

}


bool PlayState::onExit() {

    player->clean();
    enemy->clean();
    ball->clean();
    results->clean();

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

