#include "Graph.h"
 
// Graph Constructor
Graph::Graph(vector<Edge> const &edges, int n) {
   // resize the vector to hold `n` elements of type vector<Edge>
   adjList.resize(n);
   setNodeCount(n);
   // add edges to the directed graph
   for (auto &edge: edges) {
      int src = edge.src;
      int dst = edge.dst;
      int weight = edge.weight;

      // insert at the end
      adjList[src].push_back(make_pair(dst, weight));

      // uncomment the following code for undirected graph
      adjList[dst].push_back(make_pair(src, weight));
   }
}

// getter
int Graph::getNodeCount() {
   return nodes;
}

// setter
void Graph::setNodeCount(int n) {
   nodes = n;
}
 
// Function to print adjacency list representation of a graph
void Graph::printGraph(Graph const &graph) {
   cout << "Printed Graph: (src, dst, weight)" << endl;
   for (int i = 0; i < nodes; i++){
      // Function to print all neighboring vertices of a given vertex
      for (Pair v: graph.adjList[i]) {
         cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
      }
      cout << endl;
   }
}
 