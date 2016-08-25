#include "Paddle.h"

Paddle::Paddle(SDL_Renderer* renderer): Entity(renderer) {
    SDL_Surface* surface = IMG_Load("Media/paddle.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    width = 128;
    height = 32;

    y = 560;
}

Paddle::~Paddle() {
    // Clean resources
    SDL_DestroyTexture(texture);
}


void Paddle::Update(float delta) {

}

void Paddle::Render(float delta) {
    SDL_Rect rect;
    rect.x = (int)(x + 0.5f);
    rect.y = (int)(y + 0.5f);
    rect.w = width;
    rect.h = height;
    SDL_RenderCopy(renderer, texture, 0, &rect);
}
