#include <bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
void dijkstra(vvi &adj, vvi &weight, priority_queue<pi, vector<pi>, greater<pi>> &pq, int src, vi &dist, vi &flag)
{
    dist[src] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        flag[u] = 1;
//        cout << "Checking vertices adjacent to " << u+1 << endl;
        pq.pop();
        for(int v: adj[u])
        {
//            cout << "Checking for " << v+1 << endl;
            if(dist[v]>dist[u]+weight[u][v] && !flag[v])
            {
//                cout << "Relaxing" << endl;
                dist[v] = dist[u]+weight[u][v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n, vi());
    vvi weight(n, vi(n, INT_MAX));
    vi flag(n, 0);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i=0;i<m;++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x-1].push_back(y-1);
        weight[x-1][y-1] = w;
    }
    int src, dest;
    cin >> src >> dest;
    src--; dest--;
    pq.push(make_pair(0, src));
    flag[src] = 1;
    for(int v: adj[src])
    {
        pq.push(make_pair(weight[src][v], v));
    }
    vi dist(n, INT_MAX);
    dijkstra(adj, weight, pq, src, dist, flag);
    cout << ((dist[dest]!=INT_MAX)?dist[dest]:-1);
}
