#include "Graph.h"
#include <queue>


void printTable(vector<vector<int>> &distanceTable);

int main(int argc, char* argv[]) {

   // preset graph edges and weights
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

   // distance table for each node
   vector<vector<int>> distanceTable(n, vector<int>(n, 1e9));

   // Find the shortest path for all nodes
   for (int node = 0; node < graph.getNodeCount(); node++) {

      // min heap to store {distance, node}
      priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

      // starting nodes distance is always 0
      distanceTable[node][node] = 0;

      // distance, node
      pq.push({0, node});

      while(!pq.empty()) {
         // grab smallest distance node from min heap
         int currNode = pq.top().second;
         int currDistance = pq.top().first;
         pq.pop();

         for (auto edge: graph.adjList[currNode]) {
            int neighborNode = edge.first;
            int weight = edge.second;
            int newPath = currDistance + weight;

            // if new path is less than current stored path to this node
            if (newPath < distanceTable[node][neighborNode]) {
               distanceTable[node][neighborNode] = newPath;
               pq.push({weight, neighborNode});
            }
         }
      }
   }
   printTable(distanceTable);
   return 0;
}

void printTable(vector<vector<int>> &distanceTable) {
   cout << "\nDistance Table:\n" << endl;
   for (int i = 0; i < distanceTable.size(); i++) {
      cout << "Node " << i << ":  ";
      for (int j = 0; j < distanceTable[0].size(); j++) {
         cout << distanceTable[i][j] << " ";
      }
      cout << endl;
   }
}