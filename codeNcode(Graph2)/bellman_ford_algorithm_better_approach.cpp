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

This algorithm can be somewhat speeded up: often we already get the answer in a few phases and no useful work is done in remaining phases,
just a waste visiting all edges. So, let's keep the flag, to tell whether something changed in the current phase or not, and if any phase,
nothing changed, the algorithm can be stopped.
(This optimization does not improve the asymptotic behavior, i.e., some graphs will still need all  phases, but significantly accelerates
 the behavior of the algorithm "on an average", i.e., on random graphs.)

With this optimization, it is generally unnecessary to restrict manually the number of phases of the algorithm to  (N-1).
The algorithm will stop after the desired number of phases.

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

    while(1){
        bool any=false;
        for(ll j=0 ; j < E ; j++){
            if( dist[e[j].a] < INF ){ ///check if the current edge of the list is reachable or not
                if(dist[e[j].a] + e[j].cost < dist[e[j].b]){
                    dist[e[j].b] = dist[e[j].a] + e[j].cost; ///condition for relaxing a node
                    any=true; ///if any=true, then the edge list will be updated at least once in a particular phase hence continue, otherwise stop!
                }
            }
        }
        if(!any){
            break;
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
