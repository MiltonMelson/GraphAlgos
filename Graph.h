#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
using namespace std;

// Data structure for Edges
struct Edge {
   int src, dst, weight;
   Edge(int s, int d, int w) {
      src = s;
      dst = d;
      weight = w;
   }
};

typedef pair<int, int> Pair;
 
class Graph {

   public: 
      vector<vector<Pair>> adjList;

      Graph(vector<Edge> const &edges, int n);
      int getNodeCount();
      void setNodeCount(int n);
      void printGraph(Graph const &graph);
   
   private:
      int nodes;
}; 

#endif