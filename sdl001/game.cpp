#include "game.h"
#include <iostream>

Game::Game()
{
    mRenderer = nullptr;
    mWindow = nullptr;
    mIsRunning = false;
    mLastFrame = 0;
}

Game::~Game()
{
    //Liberamos renderer y la ventana.
    SDL_DestroyRenderer( mRenderer );
    SDL_DestroyWindow( mWindow );

    //Cerramos los subsistemas abiertos.
    SDL_Quit();
}

int Game::start()
{
    //Inicializamos SDL2.
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) != 0 )
    {
        printf( "SDL: Could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    //Creamos la venana.
    mWindow = SDL_CreateWindow(
        "SDL001",                //Title
        SDL_WINDOWPOS_UNDEFINED,    //x Window Position at start
        SDL_WINDOWPOS_UNDEFINED,    //y Window Position at start
        640,                        //initial screen width
        480,                        //Initial screen height
        SDL_WINDOW_SHOWN            //flags (show window).
    );
    if(mWindow == nullptr )
    {
        printf( "SDL: Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    //Cramos el renderer para pintar cosas sobre la ventana.
    mRenderer = SDL_CreateRenderer(
        mWindow,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if( mRenderer == nullptr )
    {
        printf( "SDL: Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    mIsRunning = true;
    loop();

    return 0;
}

void Game::loop()
{
    int count = 0;
    Uint32 lastTime = 0;

    while( mIsRunning )
    {
        mLastFrame = SDL_GetTicks();
        if( mLastFrame >= (lastTime+1000))
        {
            lastTime = mLastFrame;
            count++;
        }

        render();
        input();
        update();

        if( count > 3 )
            mIsRunning = false;
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(mRenderer, 255,0,0,255);
    SDL_RenderFillRect(mRenderer, nullptr);

    Uint32 timerFPS = SDL_GetTicks() - mLastFrame;
    if( timerFPS<(1000/60))
        SDL_Delay((1000/60)-timerFPS);
    SDL_RenderPresent( mRenderer );
}

void Game::input()
{
    //TODO
}

void Game::update()
{
    //TODO
}
