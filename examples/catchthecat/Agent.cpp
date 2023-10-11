#include "Agent.h"
#include "World.h"

vector<Point2D> Agent::GetNeighbors(World* world, Point2D pos)
{
  vector<Point2D> neighbors;

  if(world->isValidPosition(World::NW(pos)))
    if(!world->getContent(World::NW(pos)))
               neighbors.push_back(World::NW(pos));

  if(world->isValidPosition(World::NE(pos)))
    if(!world->getContent(World::NE(pos)))
               neighbors.push_back(World::NE(pos));

  if(world->isValidPosition(World::W(pos)))
    if(!world->getContent(World::W(pos)))
               neighbors.push_back(World::W(pos));

  if(world->isValidPosition(World::E(pos)))
    if(!world->getContent(World::E(pos)))
               neighbors.push_back(World::E(pos));

  if(world->isValidPosition(World::SW(pos)))
    if(!world->getContent(World::SW(pos)))
               neighbors.push_back(World::SW(pos));

  if(world->isValidPosition(World::SE(pos)))
    if(!world->getContent(World::SE(pos)))
               neighbors.push_back(World::SE(pos));

  return neighbors;
}
