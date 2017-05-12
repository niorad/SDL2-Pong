#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "GameStateMachine.h"


const string PlayState::playID = "PLAY";


bool PlayState::onEnter() {
    cout << "Entering PlayState" << endl;
    player = new Paddle(50, 180, 15, 80);
    enemy = new Paddle(_Game::Instance()->getGameWidth() - 65, 180, 15, 80);
    ball = new Ball(100, 300, 10, 10);
    results = new Results();
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
    } else if(ballTouchingEnemy != NONE) {
        objectTouchingBall = enemy;
        ballTouchingDirection = ballTouchingEnemy;
    } else {
        objectTouchingBall = nullptr;
    }

    if(!collisionIsSharp && ballTouchingDirection == NONE) {
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

