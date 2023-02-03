#include "Graph.h"
#include <queue>

int main(void) {
   const vector<Edge> edges = {
      // (x, y, w) —> edge from `x` to `y` having weight `w`
      {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
   };

   // total number of nodes in the graph (labelled from 0 to 5)
   int n = 6;

   // construct graph
   Graph graph(edges, n);

   // print adjacency list representation of a graph
   graph.printGraph(graph);

   // Dijkstra starts here !!!

   // create a shortest path table for each node in graph 0-5
   for (int node = 0; node < graph.getNodeCount(); node++) {

      // min heap to store {distance, node}
      priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
      // distance vector to update shorted path
      // set each not to infinity or very large number first
      vector<int> distanceVec(graph.getNodeCount(), 1e9);

      // starting nodes distance is always 0
      distanceVec[node] = 0;
      cout << "Current Node ( " << node << " ): ";
      // distance, node
      pq.push({0, node});

      while(!pq.empty()) {
         // grab min distance node
         int dis = pq.top().first;
         int src = pq.top().second;
         pq.pop();

         for (auto edge: graph.adjList[src]) {
            int w = edge.second;
            int dst = edge.first;

            // if new distance is less than currently stored distance to this node
            if (dis + w < distanceVec[dst]) {
               distanceVec[dst] = dis + w;
               pq.push({w, dst});
            }
         }
      }
      for (int i = 0; i < distanceVec.size(); i++) {
         cout << distanceVec[i] << " ";
      }
      cout << endl;
   }
   return 0;
}