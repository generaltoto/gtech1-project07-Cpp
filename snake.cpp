#include <iostream>
#include "snake.hpp"
#include "fruit.hpp"

using namespace std;

void HSnake::move(bool eat, int sizeOfSquare, SDL_Renderer *renderer) {

  int exposX = posX;
  int exposY = posY;

  posX += dirX; //on augmente la position du cube dans la direction choisie
  posY += dirY;

  next->follow(exposX, exposY, eat, sizeOfSquare, renderer);
}

void HSnake::keyEnter(bool *play){
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_W]) {
    dirX = 0;
    dirY = -1; 
  }

  if (keystate[SDL_SCANCODE_S]) {
    dirX = 0;
    dirY = 1; 
  }

  if (keystate[SDL_SCANCODE_A]) {
    dirX = -1;
    dirY = 0; 
  }

  if (keystate[SDL_SCANCODE_D]) {
    dirX = 1;
    dirY = 0; 
  }
  if (keystate[SDL_SCANCODE_SPACE]){
    *play = !play;
  }
}

void HSnake::drawHead(int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 20, 66, 186, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { posX * sizeOfSquare, posY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
}

bool HSnake::hcollision(int rows) {
  if (posX <0 || posX >= rows || posY < 0 || posY >= rows){ 
    return true; 
  }
  return this->next->collision(posX, posY);
}

bool HSnake::isOnApple(int appleX, int appleY) {
  if (appleX == posX && appleY == posY) { 
    return true; 
  }else { 
    return false; 
  }
}
