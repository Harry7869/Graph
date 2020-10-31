
                #include <bits/stdc++.h>
                      #define ll long long  int
                      #define N 100000
                      #define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
                      #define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
                      #define po pop_back
                      #define pb push_back
                      #define pp pair<ll,ll>
                      #define lb lower_bound
                      #define fi first
                      #define se second
                      #define debug(x) cout << #x << " = " << x << endl
                      #define ub upper_bound
                      #define ibs ios_base::sync_with_stdio(false)
                      #define cti cin.tie(0)
                      #define all(x) x.begin(),x.end()
                      #define PI 3.14159265
                      #define cot cout.tie(0)
                      using namespace std;
                       /**
                        * @author :: Sawlani
                        *
                        *
                        **/

                        int main()
                        {
                            //freopen("input.txt","r",stdin);
                            ll t;
                             scanf("%lld",&t);
                             while(--t>=0)
                            {
                                ll n;
                                 scanf("%lld",&n);
                                 ll a[n+1],b[n+1];

                                f(i,1,n)
                                 scanf("%lld",&a[i]);
                                f(i,1,n)
                                 scanf("%lld",&b[i]);
                                ll dp1[n+1],dp2[n+1];

                                memset(dp1,0,sizeof(dp1));
                                memset(dp2,0,sizeof(dp2));

                                dp1[1]=a[1];
                                dp2[1]=b[1];
                                f(i,2,n)
                                {
                                    dp1[i]=a[i]+min(dp1[i-1],dp2[i-1]);
                                    dp2[i]=b[i]+min(dp2[i-1],dp1[i-1]);
                                }

                                ll ans=min(dp1[n],dp2[n]);
                                printf("%lld\n",ans);

                            }
                        }


