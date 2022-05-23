#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "VectorClass.h"
#include "PaddleClass.h"

Ball::Ball()
{
  ballDirection.x = 2;
  ballDirection.y = 3;
}
Ball::~Ball()
{

}
void Ball::spawn(float x,float y)
{
  if (!ball_texture.loadFromFile("Data/Images/ballGrey.png"))
  {
    std::cout << "ball texture did not load \n";
  }
  ballsprite.setTexture(ball_texture);
  ballsprite.setPosition(x, y);
  ballsprite.scale(2, 2);
}

void Ball::direction(float dt )
{
  ballDirection.Normalise(ballDirection);
  speed = 100;
  ballsprite.move(ballDirection.x * speed * dt,ballDirection.y * speed * dt);
}
bool Ball::despawnPlayer(float x, float y )
{
  if (ballsprite.getPosition().x > 1025)
  {
    ballsprite.setPosition(x,y);
  }
}
bool Ball::despawnAI(float x, float y )
{
  if( ballsprite.getPosition().x < 5 )
  {
    ballsprite.setPosition(x,y);
  }
}
void Ball::collider(Paddle playerPaddle, Paddle aiPaddle)
{
  if (ballsprite.getGlobalBounds().intersects(playerPaddle.paddleSprite
                                                      .getGlobalBounds())
      ||ballsprite.getGlobalBounds().intersects(aiPaddle.paddleSprite
                                                         .getGlobalBounds()))
  //The below could also be used as a collider instead of the above

  // if(ball1.ballsprite.getPosition().x < playerPaddle.paddleSprite
  // .getPosition().x + playerPaddle.paddleSprite.getGlobalBounds().width
  //    && ball1.ballsprite.getPosition().x + ball1.ballsprite.getGlobalBounds()
  //    .width > playerPaddle.paddleSprite.getPosition().x &&
  //     ball1.ballsprite.getPosition().y < playerPaddle.paddleSprite
  //     .getPosition().y + playerPaddle.paddleSprite.getGlobalBounds().height
  //     && ball1.ballsprite.getPosition().y + ball1.ballsprite.getGlobalBounds()
  //     .height > playerPaddle.paddleSprite.getPosition().y)

  //The below could also be used as a collider for the player
  // if(ball1.ballsprite.getPosition().x < aiPaddle.paddleSprite
  // .getPosition().x + aiPaddle.paddleSprite.getGlobalBounds().width
  //    && ball1.ballsprite.getPosition().x + ball1.ballsprite.getGlobalBounds()
  //    .width > aiPaddle.paddleSprite.getPosition().x &&
  //     ball1.ballsprite.getPosition().y < aiPaddle.paddleSprite
  //     .getPosition().y + aiPaddle.paddleSprite.getGlobalBounds().height
  //     && ball1.ballsprite.getPosition().y + ball1.ballsprite.getGlobalBounds()
  //     .height > aiPaddle.paddleSprite.getPosition().y)
  {
    ballDirection.x = ballDirection.x * -1;
    // The lines below 77 - 84 fix a bug that allows the ball to
    // become stuck within the paddle.
    if (ballsprite.getGlobalBounds().intersects(playerPaddle.paddleSprite.getGlobalBounds()))
    {
      ballsprite.setPosition(ballsprite.getPosition().x - 3,ballsprite.getPosition().y);
    }
    if (ballsprite.getGlobalBounds().intersects(aiPaddle.paddleSprite.getGlobalBounds()))
    {
      ballsprite.setPosition(ballsprite.getPosition().x + 3,ballsprite.getPosition().y);
    }
  }
}
