
#ifndef PONGSFML_PADDLECLASS_H
#define PONGSFML_PADDLECLASS_H
class Paddle
{
 public:
Paddle();
~Paddle();
void playerSpawn(float x, float y);
void aiSpawn(float x, float y);
void movePaddle(float dt, float speed);
sf::Sprite paddleSprite; // public as it has to be accesssible in Game.cpp script
float speed = 0;// public as it has to be accesssible in Game.cpp script
bool up = false;// public as it has to be accesssible in Game.cpp script
bool down = false;// public as it has to be accesssible in Game.cpp script
 private:
  sf::Texture paddleTexture;

};
#endif // PONGSFML_PADDLECLASS_H
