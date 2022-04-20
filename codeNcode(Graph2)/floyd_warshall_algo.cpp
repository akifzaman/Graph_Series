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
    ll dist[101][101];
    for(ll i=1;i<101;i++){
        for(ll j=1;j<101;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else{
                dist[i][j]=INF;
            }
        }
    }
    ll node, edge;
    cin>>node>>edge;
    for(ll i=0;i<edge;i++){
        ll a, b, w;
        cin>>a>>b>>w;
        dist[a][b]=w;
    }
    for(ll k=1;k<=node;k++){ /// k value represents the intermediate nodes
        for(ll i=1;i<=node;i++){ /// i value represents the source nodes
            for(ll j=1;j<=node;j++){ /// j value represents the destination nodes
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                ///you can replace the if statement with the code below
                ///dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
            }
        }
    }
    for(ll i=1;i<=node;i++){
        for(ll j=1;j<=node;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

/*
TestCase:

4 5
1 2 -1
4 1 -2
2 3 5
3 1 4
3 4 4

Output:

0 -1 4 8
7 0 5 9
2 1 0 4
-2 -3 2 0
*/
