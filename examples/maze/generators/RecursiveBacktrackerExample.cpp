#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>

bool RecursiveBacktrackerExample::Step(World* w)
{
  auto sideOver2 = w->GetSize() / 2;
  if(!hasRun)
  {
    stack.push_back(Point2D(-sideOver2, -sideOver2));
    hasRun = true;
  }

  if(!stack.empty())
  {
    Point2D current = stack.back();
    visited[current.y][current.x] = true;
    w->SetNodeColor(current, Color::Green);

    Point2D target;
    std::vector<Point2D> neighbors = getVisitables(w, current);
    if(neighbors.size() == 1)
    {
      target = neighbors.front();
    }
    else if(neighbors.size() > 1)
    {
      target = neighbors[rand() % neighbors.size()];
    }
    else
    {
      w->SetNodeColor(stack.back(), Color::Black);
      stack.erase(stack.end());
      return true;
    }
    if(stack.size() > 1)
      w->SetNodeColor(stack.end()[-2], Color::Red);
    
    stack.push_back(target);
    return true;
  }
  return false;
}

void RecursiveBacktrackerExample::Clear(World* world)
{
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }

  hasRun = false;
}
Point2D RecursiveBacktrackerExample::randomStartPoint(World* world)
{
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p)
{
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;
  if(p.y - 1 >= -sideOver2)
  {
    if(!visited[p.y - 1][p.x])
    {
      Point2D northPoint(p.x, p.y - 1);
      visitables.push_back(northPoint);
    }
  }

  if( p.x + 1 <= sideOver2)
  {
    if(!visited[p.y][p.x + 1])
    {
      Point2D eastPoint(p.x + 1, p.y);
      visitables.push_back(eastPoint);
    }
  }

  if(p.y + 1 <= sideOver2)
  {
    if(!visited[p.y + 1][p.x])
    {
      Point2D southPoint(p.x, p.y + 1);
      visitables.push_back(southPoint);
    }
  }

  if(p.x - 1 >= -sideOver2)
  {
    if(!visited[p.y][p.x - 1])
    {
      Point2D westPoint(p.x - 1, p.y);
      visitables.push_back(westPoint);
    }
  }

  return visitables;
}
