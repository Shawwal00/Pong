
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "Ball.h"
#include <SFML/Graphics.hpp>
class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event, float dt);
  void keyReleased(sf::Event event);
  bool multiple_balls;
 private:
  sf::RenderWindow& window;
  sf::Text enter_text;
  sf::Font font;
  sf::Text more_balls;
  sf::Text score_text_player;
  sf::Text score_text_ai;
  int player_score;
  int ai_score;
  bool in_menu;

};

#endif // PONG_GAME_H
