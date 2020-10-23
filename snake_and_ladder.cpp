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
map<int,vector<int>>m;
void bfs(int s,int n) {
    queue<int>q;
    map<int,int>dist;
    for(int i=1;i<=n;i++)
    {
        dist[i]=INT_MAX;
    }
    // for(auto x:m)
    // {
    // 	int g=x.first;
    // 	cout<<g<<" ";
    // 	for(auto y:m[g])
    // 		cout<<y<<" - ";
    // 	cout<<"\n";
    // }
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto x:m[t])
        {
            if(dist[x]==INT_MAX)
            {
                q.push(x);
                dist[x]=dist[t]+1;
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Distance of "<<i<<" from source is "<<dist[i]<<"\n";
    // }
    cout<<dist[n]<<"\n";
}
int main()
{
	ibs;
	cti;
	int t;
	cin>>t;
	while(t--)
	{
		m.clear();
		int n;
		cin>>n;
		int board[31]={0};
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			y=y-x;
			board[x]=y;
		}
        
		for(int i=1;i<=30;i++)
		{
			for(int j=1;j<=6;j++)
			{
				int h=i+j;
				h=h+board[h];
				if(h<=30)
				m[i].pb(h);
			}
		}
		m[30].pb(30);
		bfs(1,30);
	}
	return 0;
}