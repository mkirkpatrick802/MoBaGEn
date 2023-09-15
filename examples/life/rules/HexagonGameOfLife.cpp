//
// Created by atolstenko on 2/9/2023.
//

#include "HexagonGameOfLife.h"
void HexagonGameOfLife::Step(World& world)
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
        else if(neighbors > 2)
          world.SetNext(point, false);
        else if(neighbors == 2)
          world.SetNext(point, true);
      }
      else
      {
        if(neighbors == 2)
          world.SetNext(point, true);
      }
    }
}

int HexagonGameOfLife::CountNeighbors(World& world, Point2D point)
{
  int num = 0;
  if(point.y % 2 == 1)
  {
    if(world.Get(point.Up()))
      num++;

    if(world.Get(point.Up().Right()))
      num++;

    if(world.Get(point.Left()))
      num++;

    if(world.Get(point.Right()))
      num++;

    if(world.Get(point.Down()))
      num++;

    if(world.Get(point.Down().Right()))
      num++;
  }
  else
  {
    if(world.Get(point.Up().Left()))
      num++;

    if(world.Get(point.Up()))
      num++;

    if(world.Get(point.Left()))
      num++;

    if(world.Get(point.Right()))
      num++;

    if(world.Get(point.Down().Left()))
      num++;

    if(world.Get(point.Down()))
      num++;
  }

  return num;
}
