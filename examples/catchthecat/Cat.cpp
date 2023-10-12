#include "Cat.h"
#include "World.h"

Point2D Cat::Move(World* world)
{
  const Point2D currentPos = world->getCat();
  int sideSize = world->getWorldSideSize();

  //Visited
  vector<bool> visited(sideSize * sideSize, false);

  //World Nodes
  vector<Node> nodes(sideSize * sideSize, Node());

  //Queue
  queue<Point2D> queue;
  queue.push(currentPos);
  int frontIndex = GetWorldIndex(sideSize, currentPos);
  visited[frontIndex] = true;
  nodes[frontIndex] = Node(currentPos, currentPos, 0, false);

  //BFS
  //TODO: Create a list of all the nodes in the world, each node has a distance value, a previous node,
  //      and a bool on whether or not it is traversable.
  while(!queue.empty())
  {
    Point2D front = queue.front();
    queue.pop();

    for (auto neighbor : GetNeighbors(world, front))
    {
      int worldIndex = GetWorldIndex(sideSize, neighbor);

      if(visited[worldIndex]) continue;
      else visited[worldIndex] = true;

      nodes[worldIndex] = Node(neighbor, front, nodes[GetWorldIndex(sideSize, front)].distance + 1, true);

      queue.push(neighbor);
    }
  }

  //Pathfinding
  //TODO: Find the border node with the smallest weight, then backtrack from that node to the cat position.
  //      Add all these backtracks to a vector. Then return the last node in that vector.
  //      This would find the best path to the cat.
  Node smallestWeightNode;
  for (auto node : nodes)
  {
    if(!node.isVisitable) continue;

    if(world->catWinsOnSpace(node.pos))
    {
      if(smallestWeightNode.distance == -1) smallestWeightNode = node;

      if(node.distance < smallestWeightNode.distance)
        smallestWeightNode = node;
    }
  }

  vector<Node> path;
  Node nextNode = smallestWeightNode;
  path.push_back(nextNode);
  while (nextNode.pos != nextNode.lastPos)
  {
    nextNode = nodes[GetWorldIndex(sideSize, nextNode.lastPos)];
    path.push_back(nextNode);
  }

  path.pop_back();

  cout << "CAT: " << path.back().pos.x << " " << path.back().pos.y << '\n';

  return path.back().pos;
}
