#include "VectorClass.h"
#include "math.h"

Vector::Vector()
{

}
Vector::~Vector()
{

}
Vector Vector::Normalise(Vector ballDirection)
{
  ballDirection.magnitude = ballDirection.x*ballDirection.x +
                            ballDirection.y*ballDirection.y;
  ballDirection.magnitude = sqrt(ballDirection.magnitude);
  ballDirection.x = ballDirection.x/ballDirection.magnitude;
  ballDirection.y = ballDirection.y/ballDirection.magnitude;
  return ballDirection;
}
Vector Vector::vectorOperator(float scalar, Vector ballDirection)
{
 ballDirection.x = ballDirection.x * scalar;
 ballDirection.y = ballDirection.y * scalar;
 return ballDirection;
}