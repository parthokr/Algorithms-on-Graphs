#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define qi queue<int>
int bfs(vvi &adj, int s, vi &disc, vi &dist)
{
    disc[s] = 1; dist[s] = 0;
    qi q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i: adj[u])
        {
            if(!disc[i])
            {
                disc[i] = 1;
                q.push(i);
                dist[i] = dist[u]+1;
            }else if(dist[u]==dist[i])
            {
                return 0;
            }
        }
    }
    return 1;
}
bool isBipartite(vvi &adj, vi &disc, vi &dist)
{
    for(int i=0;i<adj.size();++i)
    {
        if(!disc[i])
        {
            if(!bfs(adj, i, disc, dist))
            {
                return 0;
            }
        }
    }
    return 1;
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
    vi dist(n);
    vi disc(n, 0);
    cout << isBipartite(adj, disc, dist);

}
