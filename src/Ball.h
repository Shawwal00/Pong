#ifndef PONGSFML_BALL_H
#define PONGSFML_BALL_H

#include <SFML/Graphics.hpp>
#include "VectorClass.h"
#include "PaddleClass.h"
class Ball
{
 public:
  Ball();
 ~Ball();
 void spawn(float x, float y);
 bool despawnPlayer(float x, float y);
 bool despawnAI(float x, float y);
 void collider (Paddle playerPaddle, Paddle aiPaddle);
 void direction(float dt);
 sf::Sprite ballsprite; // public as it has to be accesssible in Game.cpp script
 Vector ballDirection; // public as it has to be accesssible in Game.cpp script
 private:
  sf::Texture ball_texture;
  float speed = 0;


};


#endif // PONGSFML_BALL_H
