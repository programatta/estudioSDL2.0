#ifndef GAME_H
#define GAME_H

#include<SDL2/SDL.h>

class Game
{
public:
    Game();
    ~Game();
    int start();

private:
    void loop();
    void render();
    void input();
    void update();
    SDL_Renderer *mRenderer;
    SDL_Window *mWindow;
    bool mIsRunning;
    Uint32 mLastFrame;
};

#endif // GAME_H
