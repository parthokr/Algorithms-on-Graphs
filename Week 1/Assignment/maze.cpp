#include <bits/stdc++.h>
using namespace std;
int explore(vector<vector<int>> g, vector<int> marker, int v, int d)
{
    if(v==d)
    {
        return 1;
    }
    marker[v] = 1;
    for(int i: g[v])
    {
        if(marker[i]==0)
        {
            if(explore(g, marker, i, d))
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> marker(n, 0);
    vector<vector<int>> g(n);
    for(int i=0;i<m;++i)
    {
        int x, y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
    int s,d; cin >> s >> d;
    int r = explore(g, marker, s-1, d-1);
    cout << r;
}
