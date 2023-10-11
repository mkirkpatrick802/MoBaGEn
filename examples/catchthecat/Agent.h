#ifndef AGENT_H
#define AGENT_H
#include "math/Point2D.h"
#include <queue>

using namespace std;

class World;

class Agent {
public:
  explicit Agent() = default;
  virtual Point2D Move(World*) = 0;
  vector<Point2D> GetNeighbors(World* world, Point2D pos);
};


#endif  // AGENT_H
