#ifndef AGENT_H
#define AGENT_H
#include "math/Point2D.h"
#include <queue>

using namespace std;
class World;

struct Node
{

  Node(Point2D currentPosition = Point2D(0, 0), Point2D lastPosition = Point2D(0, 0), int distance = -1, bool isVisitable = false)
  {
    pos = currentPosition;
    lastPos = lastPosition;
    this->distance = distance;
    this->isVisitable = isVisitable;
  }

  Point2D pos;
  int distance;
  Point2D lastPos;
  bool isVisitable;
};

class Agent
{
public:
  explicit Agent() = default;
  virtual Point2D Move(World*) = 0;
  vector<Point2D> GetNeighbors(World* world, Point2D pos);
  int GetWorldIndex(int sideSize, Point2D pos) { return (pos.y + sideSize / 2) * (sideSize) + pos.x + sideSize / 2; };
};


#endif  // AGENT_H
