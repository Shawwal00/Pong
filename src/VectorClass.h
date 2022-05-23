#ifndef PONGSFML_VECTORCLASS_H
#define PONGSFML_VECTORCLASS_H

#include <SFML/Graphics.hpp>

class Vector
{
 public:
  Vector();
 ~Vector();
  Vector Normalise(Vector ballDirection);
  Vector vectorOperator(float  scalar, Vector ballDirection);
  float  x = 0;//has to accessed in other scripts
  float  y = 0;//has to accessed in other scripts
 private:
  float magnitude = 0;
};



#endif // PONGSFML_VECTORCLASS_H
