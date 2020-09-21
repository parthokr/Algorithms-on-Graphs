#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> colour(adj.size(), -1);
  queue<int> q;
  q.push(0);
  colour[0] = 1;
  while(q.empty()==false){    // Iterating over the queue
    int current = q.front();
    q.pop();

    for(int neighbour: adj[current]){   // Iterating over each neighbour
      if(colour[neighbour] == -1){     // If the node is unvisited
        colour[neighbour] = 1 - colour[current];  // Assign the opposite colour
        q.push(neighbour);              // Push in the queue
      }
      else if(colour[neighbour] == colour[current]){  // If the colour of neighbour is same as current node return false
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
