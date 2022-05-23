#include "Game.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PaddleClass.h"


Ball ball1;// has to be accessed by multiple functions
Ball ball2;// has to be accessed by multiple functions
Ball ball3;// has to be accessed by multiple functions
Paddle playerPaddle;// has to be accessed by multiple functions
Paddle aiPaddle;// has to be accessed by multiple functions

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}
bool Game::init()
{
  in_menu = true;
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
    enter_text.setString("Press enter to start or q to quit");
    enter_text.setFont(font);
    enter_text.setCharacterSize(40);
    enter_text.setFillColor(sf::Color(255, 255, 255, 255));
    enter_text.setPosition(225, 50);

    more_balls.setString("Press M to play with multiple balls");
    more_balls.setFont(font);
    more_balls.setCharacterSize(40);
    more_balls.setFillColor(sf::Color(255, 255, 255, 255));
    more_balls.setPosition(225, 100);


    player_score = 0;
    score_text_player.setString(std::to_string(player_score));
    score_text_player.setFont(font);
    score_text_player.setCharacterSize(60);
    score_text_player.setFillColor(sf::Color(255, 255, 255, 255));
    score_text_player.setPosition(990, 50);

    ai_score = 0;
    score_text_ai.setString(std::to_string(ai_score));
    score_text_ai.setFont(font);
    score_text_ai.setCharacterSize(60);
    score_text_ai.setFillColor(sf::Color(255, 255, 255, 255));
    score_text_ai.setPosition(50, 50);
    ball1.spawn(525,300);


    playerPaddle.playerSpawn(window.getSize().x, window.getSize().y);
    aiPaddle.aiSpawn(window.getSize().x, window.getSize().y);

  return true;
}
void Game::update(float dt)
{
  ball1.direction(dt);
  // making the ball move below
  if (
    (ball1.ballsprite.getPosition().y >
     (window.getSize().y - ball1.ballsprite.getGlobalBounds().height)) ||
    (ball1.ballsprite.getPosition().y < 0))
  {
    ball1.ballDirection.y = ball1.ballDirection.y * -1;
  }
  if (
    (ball1.ballsprite.getPosition().x >
     (window.getSize().x - ball1.ballsprite.getGlobalBounds().width)) ||
    (ball1.ballsprite.getPosition().x < 0))
  {
    ball1.ballDirection.x = ball1.ballDirection.x * -1;
  }

  ball1.collider(playerPaddle, aiPaddle);

  if (ball1.despawnPlayer(525, 300))
  {
    player_score = player_score + 1;
    score_text_player.setString(std::to_string(player_score));
  }
  if (ball1.despawnAI(525, 300))
  {
    ai_score = ai_score + 1;
    score_text_ai.setString(std::to_string(ai_score));
  }
#pragma region more_balls
  if (multiple_balls == true)
  {
    ball2.direction(dt);
    ball2.collider(playerPaddle, aiPaddle);
    if (
      (ball2.ballsprite.getPosition().y >
       (window.getSize().y - ball2.ballsprite.getGlobalBounds().height)) ||
      (ball2.ballsprite.getPosition().y < 0))
    {
      ball2.ballDirection.y = ball2.ballDirection.y * -1;
    }
    if (
      (ball2.ballsprite.getPosition().x >
       (window.getSize().x - ball2.ballsprite.getGlobalBounds().width)) ||
      (ball2.ballsprite.getPosition().x < 0))
    {
      ball2.ballDirection.x = ball2.ballDirection.x * -1;
    }

    if (ball2.despawnPlayer(525, 200))
    {
      player_score = player_score + 1;
      score_text_player.setString(std::to_string(player_score));
    }
    if (ball2.despawnAI(525, 200))
    {
      ai_score = ai_score + 1;
      score_text_ai.setString(std::to_string(ai_score));
    }


    ball3.direction(dt);
    ball3.collider(playerPaddle, aiPaddle);
    if (
      (ball3.ballsprite.getPosition().y >
       (window.getSize().y - ball3.ballsprite.getGlobalBounds().height)) ||
      (ball3.ballsprite.getPosition().y < 0))
    {
      ball3.ballDirection.y = ball3.ballDirection.y * -1;
    }
    if (
      (ball3.ballsprite.getPosition().x >
       (window.getSize().x - ball3.ballsprite.getGlobalBounds().width)) ||
      (ball3.ballsprite.getPosition().x < 0))
    {
      ball3.ballDirection.x = ball3.ballDirection.x * -1;
    }

    if (ball3.despawnPlayer(525, 400))
    {
      player_score = player_score + 1;
      score_text_player.setString(std::to_string(player_score));
    }
    if (ball3.despawnAI(525, 400))
    {
      ai_score = ai_score + 1;
      score_text_ai.setString(std::to_string(ai_score));
    }
  }
#pragma endregion
    // Paddle movement
    if (
      playerPaddle.down == true &&
      playerPaddle.paddleSprite.getPosition().y <
        (window.getSize().y -
         playerPaddle.paddleSprite.getGlobalBounds().height))
    {
      playerPaddle.speed = 100;
      playerPaddle.movePaddle(dt, playerPaddle.speed);
    }

    if (playerPaddle.up == true && playerPaddle.paddleSprite.getPosition().y > 0)
    {
      playerPaddle.speed = -100;
      playerPaddle.movePaddle(dt, playerPaddle.speed);
    }

    if (aiPaddle.up == true && aiPaddle.paddleSprite.getPosition().y > 0)
    {
      aiPaddle.speed = -100;
      aiPaddle.movePaddle(dt, aiPaddle.speed);
    }

    if (
      aiPaddle.down == true &&
      aiPaddle.paddleSprite.getPosition().y <
        (window.getSize().y - aiPaddle.paddleSprite.getGlobalBounds().height))
    {
      aiPaddle.speed = 100;
      aiPaddle.movePaddle(dt, aiPaddle.speed);
    }
  }

void Game::render()
{
  if (in_menu == true)
  {
  window.draw(enter_text);
  window.draw(more_balls);
  }
  else if (in_menu == false)
  {
    window.draw(ball1.ballsprite);
    window.draw(playerPaddle.paddleSprite);
    window.draw(aiPaddle.paddleSprite);
    window.draw(score_text_player);
    window.draw(score_text_ai);

    if(multiple_balls == true)
    {
      window.draw(ball2.ballsprite);
      window.draw(ball3.ballsprite);
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

}

void Game::keyPressed(sf::Event event, float  dt)
{
   if (event.key.code == sf::Keyboard::Enter)
   {
     in_menu = false;
   }
   if (event.key.code == sf::Keyboard::Q)
   {
     window.close();
   }
   if (event.key.code == sf::Keyboard::M)
   {
     multiple_balls = true;
     ball2.spawn(525,200);
     ball3.spawn(525,400);
     in_menu = false;
   }
   // The below is used so that simultaneous movement can occur
   if (event.key.code == sf::Keyboard::Down)
   {
     playerPaddle.down = true;
   }
   if (event.key.code == sf::Keyboard::Up)
   {
     playerPaddle.up = true;
   }
   if (event.key.code == sf::Keyboard::S)
   {
     aiPaddle.down = true;
   }
   if (event.key.code == sf::Keyboard::W)
   {
     aiPaddle.up = true;
   }
}

void Game::keyReleased(sf::Event event)
{
  // The below is used so that simultaneous movement can occur
  if (event.key.code == sf::Keyboard::Down)
  {
    playerPaddle.down = false;
  }
  if (event.key.code == sf::Keyboard::Up)
  {
    playerPaddle.up = false;
  }
  if (event.key.code == sf::Keyboard::S)
  {
    aiPaddle.down = false;
  }
  if (event.key.code == sf::Keyboard::W)
  {
    aiPaddle.up = false;
  }
}