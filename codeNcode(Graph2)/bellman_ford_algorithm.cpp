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


/*

Bellman-ford algorithm is used to find the SSSP(Single Source Shortest Path), which means shortest distance of every other node
from a given root node.
This algorithm support negative edge weight unlike dijkstra's algorithm. We know that Floyd-Warshal algorithm also supports
negative edge weight but it works in O(N^3) time complexity where Bellman-ford algorithm works in O(VE) time complexity.
It requires (N-1) phases (where N is the number of nodes) to calculate the SSSP.

Use of Bellman-ford algorithm:
1) to find SSSP
2) to find the presence of cycle with negative weight
3) to find the cycle with negative weight

*/

ll V, E, x, y, c;
struct edge{
    ll a, b, cost;
};

void solve(){
    cin >> V >> E; ///V=vertices, E=edges

    vector <edge> e(E); ///creating a list of edges
    vector<ll> dist(V+1, INF); ///creating a distance vector and initiate all values as Infinity
    dist[1]=0; ///if 1 is the root node

    for(ll i=0;i<E;i++){
        cin>>x>>y>>c;
        e[i].a = x;
        e[i].b = y;
        e[i].cost = c;
    }

    for(ll i=0 ; i < V-1 ; i++){
        for(ll j=0 ; j < E ; j++){
            if( dist[e[j].a] < INF ){ ///check if the current edge of the list is reachable or not
                dist[e[j].b] = min( dist[e[j].b], dist[e[j].a] + e[j].cost ); ///condition for relaxing a node
            }
        }
    }
    ///printing the SSSP
    for(ll i=1 ; i <= V ; i++){
        cout<<dist[i]<<" ";
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


/*
Testcase:

5 8
5 4 -3
2 5 2
2 4 2
4 2 1
4 3 5
2 3 3
1 3 4
1 2 -1

Output:
0 -1 2 -2 1

*/
