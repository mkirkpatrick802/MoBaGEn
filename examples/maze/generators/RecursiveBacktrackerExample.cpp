#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>

bool RecursiveBacktrackerExample::Step(World* w)
{
  /*Point2D startingPoint = Point2D(0, 0);
  stack.push_back(startingPoint);
  while(!stack.empty())
  {
    Point2D currentPoint = stack.front();
    w->SetNodeColor(currentPoint, Color::Red);
    std::vector<Point2D> neighbors = getVisitables(w, currentPoint);
    if(!neighbors.empty())
    {
      Point2D targetPoint;
      if(neighbors.size() == 1)
      {
        targetPoint = neighbors.front();
      }
      else
      {
        targetPoint = neighbors[rand() % neighbors.size()];
      }
      stack.push_back(targetPoint);
    }
    else
    {
      stack.erase(stack.begin());
    }
  }*/
}

void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}
Point2D RecursiveBacktrackerExample::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;
  if(w->GetNorth(p))
  {
    Point2D northPoint(p.x, p.y + 1);
    visitables.push_back(northPoint);
  }

  if(w->GetEast(p))
  {
    Point2D eastPoint(p.x + 1, p.y);
    visitables.push_back(eastPoint);
  }

  if(w->GetSouth(p))
  {
    Point2D southPoint(p.x, p.y - 1);
    visitables.push_back(southPoint);
  }

  if(w->GetWest(p))
  {
    Point2D westPoint(p.x - 1, p.y);
    visitables.push_back(westPoint);
  }

  return visitables;
}
