#include <bits/stdc++.h>
using namespace std;
//void print(vector<int>& rec)
//{
//    for(auto i: rec)
//    {
//        cout << i << " ";
//    }
//}
void dfs(vector<vector<int>> adj, int i, vector<int> &marker, vector<int> &rec, bool &circle)
{
    if(rec[i])
    {
//        cout << " -> " << i << " ";
        circle = 1;
        return;
    }
    if(marker[i]|circle)
    {
        rec[i] = 0;
        return;
    }
    marker[i]=1;
    rec[i]=1;
    for(int v: adj[i])
    {
//        cout << "DFS : " << i << " -> "  << v << " rec: "; print(rec); cout << "Circle: " << circle <<      endl;
//        cout << "Calling for dfs" << v << endl;
        dfs(adj, v, marker, rec, circle);
    }
    rec[i] = 0;
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> marker(n,0);
    vector<int> rec(n,0);
    for(int i=0;i<m;++i)
    {
        int x,y; cin >> x >> y;
        adj[x-1].push_back(y-1);
    }
    bool circle = 0;
    for(int i=0;i<n;++i)
    {
        dfs(adj, i, marker, rec, circle);
    }
//    for(int i=1;i<=m;++i)
//    {
//        cout << i << " : ";
//        for(auto j: adj[i])
//        {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
    cout << circle;
}
