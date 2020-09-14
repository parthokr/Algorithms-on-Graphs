#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> adj, int v, vector<int> &c)
{
	if(c[v])
		return;

	c[v] = 1;
	for(int i: adj[v])
	{
		dfs(adj, i, c);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> c(n, 0);
	for(int i=0;i<m;++i)
	{
		int x, y; cin >> x >> y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	int count = 0;
	for(int v=0;v<n;++v)
	{
		if(!c[v])
		{
			dfs(adj, v, c);
			count++;
		}
	}
	cout << count;
}
