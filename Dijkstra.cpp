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

   // create a shortest path table for each node in graph 0-5
   for (int node = 0; node < graph.getNodeCount(); node++) {

      // min heap to store {distance, node}
      priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

      // starting nodes distance is always 0
      distanceTable[node][node] = 0;

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
            if (dis + w < distanceTable[node][dst]) {
               distanceTable[node][dst] = dis + w;
               pq.push({w, dst});
            }
         }
      }
   }
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