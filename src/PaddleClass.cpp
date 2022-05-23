#include <SFML/Graphics.hpp>
#include <iostream>
#include "PaddleClass.h"

Paddle::Paddle()
{

}

Paddle::~Paddle()
{

}
void Paddle::playerSpawn(float x, float y)
{
    if (!paddleTexture.loadFromFile("Data/Images/paddleBlue.png"))
    {
      std::cout << "blue paddle did not load \n";
    }
  paddleSprite.setTexture(paddleTexture);
  paddleSprite.setPosition(x - 50, y - 450);
  paddleSprite.scale(1.5, 1.5);
  paddleSprite.setRotation(90);
}
void Paddle::aiSpawn(float x, float y)
{
  if (!paddleTexture.loadFromFile("Data/Images/paddleRed.png"))
  {
    std::cout << "red paddle did not load \n";
  }
  paddleSprite.setTexture(paddleTexture);
  paddleSprite.setPosition(x - 1000, y - 450);
  paddleSprite.scale(1.5, 1.5);
  paddleSprite.setRotation(90);
}
void  Paddle::movePaddle(float dt, float speed)
{
  paddleSprite.move(0, 5.0f * speed * dt);
}