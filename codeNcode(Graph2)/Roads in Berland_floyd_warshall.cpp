#include <bits/stdc++.h>
using namespace std;

#define         nl                  "\n"
#define         mod                 1000000007
#define         sz(c)               (int)c.size()
#define         pb                  push_back
#define         ff                  first
#define         ss                  second
#define         mkp                 make_pair
#define         ll                  long long
#define         pii                 pair<int, int>
#define         pll                 pair<ll, ll>
#define         vll                 vector<ll>
#define         vi                  vector<int>
#define         no                  cout<<"NO\n"
#define         yes                 cout<<"YES\n"
#define         one                 cout<<"1\n"
#define         mone                cout<<"-1\n"
#define         lcm(a, b)           ((a)*((b)/gcd(a,b)))
#define         all(p)              p.begin(),p.end()
#define         mem(ar,val)         memset(ar, val, sizeof(ar))
#define         forn(n)             for(int i=0;i<n;i++)
#define         UNIQUE(a)           sort(all(a)); a.erase(unique(all(a)), a.end())
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
const double pi = acos(-1.0);
const ll INF = 1000000000000000000;
long long M = 1e9+7;
const ll N = 1e6 + 1;


///floyd-warshall algorithm is used to calculate all pair shortest distance.
///it supports negative edge weight and works in O(N^3) time complexity
///Bellman-ford algorithm does the same job but O(VE) time complexity, so that is much better!

void solve(){
    ll n;
    vector <ll> p;
    cin>>n;
    ll dist[n+1][n+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }

    ll k; ///k represents the intermediate edges
    cin>>k;

    for(ll i=1;i<=k;i++){
        ll a, b, w;
        cin>>a>>b>>w;
        ll ans=0;
        for(ll i=1;i<=n;i++){ /// i value represents the source nodes
            for(ll j=1;j<=n;j++){ /// j value represents the destination nodes
                ll d = dist[i][a] + w + dist[b][j];
                if(d < dist[i][j]){
                    dist[i][j] = d;
                    dist[j][i] = d;
                }
                d = dist[i][b] + w + dist[a][j];
                if(d < dist[i][j]){
                    dist[i][j] = d;
                    dist[j][i] = d;
                }
                ans+=dist[i][j];
            }
        }
        p.push_back(ans/2); ///we are adding both dist[i][j] and dist[j][i] in the sum but we only need to do it once, so dividing by 2.
    }
    for(ll i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
///in some questions, intermediate edges could be given/ need to be used instead of intermediate nodes.
///if the intermediate edges (k edges) are taken as input then we don't need to run a loop for k=1 to k=n-1 anymore.
///we will take k intermediate edges as input, and run the i and j loops as before and check the conditions.

/*
Testcases:

3
0 4 5
4 0 9
5 9 0
2
2 3 8
1 2 1

Output:
17 12

*/
