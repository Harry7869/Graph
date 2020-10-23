#include <bits/stdc++.h>
#define ll long long int
#define N 1000
#define M 1000000007
#define f(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define rf(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define fi first
#define se second
#define mp make_pair
#define bs binary_search
#define debug(x) cout << #x << " = " << x << endl
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define all(x) x.begin(), x.end()
#define PI 3.14159265
#define cot cout.tie(0)
using namespace std;
/**
  * @author :: Rishabh
  *
  */

// A bipartite graph is a graph whose edges can be seperated in 2 sets such that 
// there is no edge that connects vertices of same set.
// Thus when a graph has cycle and the cycle length is even then it is bipartite graph
// Here visited array has 3 values
// 0 = not visited
// 1 = visited and has color 1
// 2 = visited and has color 2
// Here we use 2 colors to detect the odd_cycle length of the graph
// The adjacent vertices are colored in different colors.
// If the adjacent vertices is of same color then cycle is of odd length
// So, (3 - color) shows that when color is 1, then adjacent vertex color is made 2 (3-1) and 
// when color is 2, then adjacent vertix color is made 1 (3-2); 



bool odd_cycle;
void dfs(int node,int parent,int color,int *visited,vector<int>g[])
{
    visited[node]=color;
    for(auto nbr:g[node])
    {
        if(visited[nbr]==0)
        {
            dfs(nbr,node,3-color,visited,g);

        }
        else if(nbr!=parent && visited[nbr]==color)
        {
            odd_cycle=1;
        }
    }
}
bool isbipartite(int v,vector<int>g[])
{
    odd_cycle=0;
    int* visited=new int[v+1];
    for(int i=0;i<v;i++)
        visited[i]=0;
    dfs(1,0,1,visited,g);
    if(odd_cycle)
        return false;
    return true;
}
int main()
{
    ibs;
    cti;
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        vector<int>g[v+1];
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        if(isbipartite(v,g))
            cout<<"Bipartite\n";
        else
            cout<<"Not Bipartite\n";
    }
    return 0;
}