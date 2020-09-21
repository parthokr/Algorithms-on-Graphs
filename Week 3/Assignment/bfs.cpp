#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define qi queue<int>
void bfs(vvi adj, int s, vi &dist)
{
    dist[s] = 0;
    qi q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i: adj[u])
        {
            if(dist[i]==-1)
            {
                q.push(i);
                dist[i] = dist[u]+1;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for(int i=0;i<m;++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    int s, d; cin >> s >> d; s--; d--;
    vi dist(n, -1);
    bfs(adj, s, dist);
    cout << dist[d];
}
