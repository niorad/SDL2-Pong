#include "Game.h"


const int FPS = 60;
const float DELAY_TIME = 1000.0f / FPS;

int main(int argc, char **agv) {

    Uint32 frameStart;
    Uint32 frameTime;
    
    if(_Game::Instance()->init("SDL2-Starter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN)) {
    
        cout << "Game Init Succeeded" << endl;
        
        while(_Game::Instance()->isRunning()) {
        
            frameStart = SDL_GetTicks();
            
            _Game::Instance()->update();
            _Game::Instance()->handleEvents();
            _Game::Instance()->render();
            
            frameTime = SDL_GetTicks() - frameStart;
            
            if(frameTime < DELAY_TIME) {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            } else {
                SDL_Delay((int)DELAY_TIME);
            }
        
        }
    
    
    } else {
        cout << "Game Init Failed: " << SDL_GetError() << endl;
        return -1;
    }
    
    _Game::Instance()->clean();
    
    return 0;

}




