#ifndef ENTITY_H_
#define ENTITY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
public:
    Entity(SDL_Renderer* renderer);
    virtual ~Entity();

    float x, y, width, height;

    virtual void Update(float delta);
    virtual void Render(float delta);

    bool Collides(Entity* other);
protected:
    SDL_Renderer* renderer;

};

#endif
