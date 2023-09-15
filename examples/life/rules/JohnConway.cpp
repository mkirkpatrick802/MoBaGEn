#include "JohnConway.h"
#include <iostream>

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world)
{
  for (int i = 0; i < world.SideSize(); ++i)
    for (int j = 0; j < world.SideSize(); ++j)
    {
      Point2D point = Point2D(i, j);
      int neighbors = CountNeighbors(world, point);
      if(world.Get(point))
      {
        if(neighbors < 2)
          world.SetNext(point, false);
        else if(neighbors == 2 || neighbors == 3)
          world.SetNext(point, true);
        else if(neighbors > 3)
          world.SetNext(point, false);
      }
      else
      {
        if(neighbors == 3)
          world.SetNext(point, true);
      }
    }
}

int JohnConway::CountNeighbors(World& world, Point2D point)
{
  int num = 0;
  if(world.Get(point.Up().Left()))
    num++;

  if(world.Get(point.Up()))
    num++;

  if(world.Get(point.Up().Right()))
    num++;

  if(world.Get(point.Left()))
    num++;

  if(world.Get(point.Right()))
    num++;

  if(world.Get(point.Down().Left()))
    num++;

  if(world.Get(point.Down()))
    num++;

  if(world.Get(point.Down().Right()))
    num++;

  return num;
}
