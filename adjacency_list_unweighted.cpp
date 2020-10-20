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
        vector<int>adj[v];
        for(int i=0;i<e;i++)
        {
            int v1,v2;
            cin>>v1>>v2;
            adj[v1].pb(v2);
            adj[v2].pb(v1);
        }
        for(int i=0;i<v;i++)
        {
            cout<<i;
            for(auto x:adj[i])
            cout<<"-> "<<x;
            cout<<"\n";
        }
        adj[v].clear();
    }
    return 0;
}