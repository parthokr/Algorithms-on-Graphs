#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define vsi vector<set<int>>
#define pb push_back
double dist(pii p1, pii p2)
{
    return pow(
               pow((p1.first-p2.first),2) +
               pow(p1.second-p2.second,2)
               , 0.5);
}
int _find(int x, vsi &sets)
{
    for(int s=0;s<sets.size();++s)
    {
        for(int i: sets[s])
        {
            if(i==x)
                return s;
        }
    }
    return -1;
}
void _union(int a, int b, vsi &sets)
{
    sets[a].insert(sets[b].begin(), sets[b].end());
    sets.erase(sets.begin()+b);
}
int main()
{
    int n; cin >> n;
    vector<pii> points;
    vsi sets;
    vector<pair<double, pii>> edges;
    for(int i=0;i<n;++i)
    {
        int x, y; cin >> x >> y;
        points.pb({x,y});
        sets.pb({i});
    }
    int k; cin >> k;
    // generate edges
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            edges.pb({dist(points[i], points[j]), {i,j}});
        }
    }
    sort(edges.begin(), edges.end(), [](auto e1, auto e2){
         return e1.first <= e2.first;
         });
    int union_num = 0;
    for(auto e: edges)
    {
        if(_find(e.second.first, sets)!=_find(e.second.second, sets))
        {
            _union(_find(e.second.first, sets), _find(e.second.second, sets), sets);
            union_num++;
        }
        if(union_num>n-k)
        {
            printf("%6f", e.first);
            break;
        }
    }
//    cout << sum << endl;
//    for(auto v: edges)
//    {
//        cout << v.first << " ";
//    }
//    double sum = 0.0;
//    for(int i=0;i<n-1;++i)
//    {
//        sum += dist(points[i], points[i+1]);
//    }
//    cout << sum;
}
