#include "Board.h"

Board::Board(SDL_Renderer* renderer): Entity(renderer) {
    SDL_Surface* surface = IMG_Load("Media/bricks.png");
    bricktexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("Media/side.png");
    sidetexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    srand((unsigned int)time(0));

    x = 16;
    y = 0;
    width = 768;
    height = 600;

    brickoffsetx = 0;
    brickoffsety = 16;
}

Board::~Board() {
    // Clean resources
    SDL_DestroyTexture(bricktexture);
    SDL_DestroyTexture(sidetexture);
}

void Board::Update(float delta) {

}

void Board::Render(float delta) {
    // Render bricks
    for (int i=0; i<BOARD_WIDTH; i++) {
        for (int j=0; j<BOARD_HEIGHT; j++) {
            Brick brick = bricks[i][j];

            // Check if the brick exists
            if (!brick.state)
                continue;

            SDL_Rect srcrect;

            srcrect.x = (brick.type % 2) * BOARD_BRWIDTH;
            srcrect.y = (brick.type / 2) * BOARD_BRHEIGHT;
            srcrect.w = BOARD_BRWIDTH;
            srcrect.h = BOARD_BRHEIGHT;

            SDL_Rect dstrect;
            dstrect.x = brickoffsetx + x + i * BOARD_BRWIDTH;
            dstrect.y = brickoffsety + y + j * BOARD_BRHEIGHT;
            dstrect.w = BOARD_BRWIDTH;
            dstrect.h = BOARD_BRHEIGHT;

            SDL_RenderCopy(renderer, bricktexture, &srcrect, &dstrect);
        }
    }

    // Render sides
    SDL_Rect dstrect;
    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = 16;
    dstrect.h = 600;
    SDL_RenderCopy(renderer, sidetexture, 0, &dstrect);

    dstrect.x = 800 - 16;
    dstrect.y = 0;
    dstrect.w = 16;
    dstrect.h = 600;
    SDL_RenderCopy(renderer, sidetexture, 0, &dstrect);
}

void Board::CreateLevel() {
    for (int i=0; i<BOARD_WIDTH; i++) {
        for (int j=0; j<BOARD_HEIGHT; j++) {
            Brick brick;

            brick.type = rand() % 4;    // Random color
            //brick.type = (i ^ j) % 4; // Example of a fixed pattern using xor
            brick.state = true;         // Brick is present
            bricks[i][j] = brick;
        }
    }
}
