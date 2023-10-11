#include "Cat.h"
#include "World.h"
#include <stdexcept>

Point2D Cat::Move(World* world)
{
  const Point2D currentPos = world->getCat();
  int sideSize = world->getWorldSideSize();
  int distance = 0;

  //Distance
  vector<int> dist(sideSize * sideSize, -1);

  //Visited
  vector<bool> visited(sideSize * sideSize, false);

  //Queue
  queue<Point2D> queue;
  queue.push(currentPos);

  while(!queue.empty())
  {
    Point2D front = queue.front();
    queue.pop();

    visited[(front.y + sideSize / 2) * (sideSize) + front.x + sideSize / 2] = true;
    distance++;
    for (auto neighbor : GetNeighbors(world, front))
    {
      int worldIndex = (neighbor.y + sideSize / 2) * (sideSize) + neighbor.x + sideSize / 2;

      if(visited[worldIndex]) continue;
      dist[worldIndex] = distance;

      queue.push(neighbor);
    }
  }

  return Point2D(0, 0);
}
