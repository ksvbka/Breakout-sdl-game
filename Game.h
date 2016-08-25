#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>

#include "Board.h"
#include "Paddle.h"
#include "Ball.h"


#define FPS_DELAY 500

class Game {
public:
    Game();
    ~Game();

    bool Init();
    void Run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* texture;

    // Timing
    unsigned int lasttick, fpstick, fps, framecount;

    // Test
    float testx, testy;

    Board* board;
    Paddle* paddle;
    Ball* ball;
    bool paddlestick;

    // SoVGA keep track to optimize update parameter
    int oldBrickCount = -1;

    void Clean();
    void Update(float delta);
    void Render(float delta);

    void NewGame();
    void ResetPaddle();
    void StickBall();

    void SetPaddleX(float x);
    void CheckBoardCollisions();
    float GetReflection(float hitx);
    void CheckPaddleCollisions();
    void CheckBrickCollisions();
    void CheckBrickCollisions2();
    void BallBrickResponse(int dirindex);
    int GetBrickCount();

    // void PlayOneShotSound(const char* name);
};

#endif
