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



///dijkstra's algorithm is used to calculated the single source shortest distance to all other nodes.
///it generally doesn't support negative edge weight and works in O(VlogV) time complexity.
///this algorithm can be implemented using priority queue or set.

vector<pair<ll,ll>> adj[1001];

void solve(){
    ll node, edge;
    cin>>node>>edge;
    for(ll i=0;i<edge;i++){
        ll a, b, w;
        cin>>a>>b>>w;
        adj[a].pb({b,w}); ///adjacency vector er prottekta pair er first hocche node, second hocche oi node er distance
        adj[b].pb({a,w}); /// priority queue te er ulta, means first hocche distance, second hocche node number
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq;
    ///taking min heap, by default pq works as a max heap
    ///min heap structure: priority_queue< datatype, vector<datatype>, greater<datatype> > priority queue name;
    vector<ll> dist(node+1, INF);
    pq.push({0,1}); ///distance from node 1 to node 1 is 0
    dist[1]=0;

    while(!pq.empty()){
        ll curr = pq.top().second; ///pq.top().second represents the node number
        ll curr_d = pq.top().first; ///pq.top().first represents the distance required to reach that node
        pq.pop();

        for(pair<ll,ll> child: adj[curr]){
            if(child.second + curr_d < dist[child.first]){
                dist[child.first] = (child.second + curr_d);
                pq.push({dist[child.first], child.first});
            }
        }
    }
    cout<<endl;

    for(ll i=1;i<=node;i++){
        cout<< dist[i] <<" ";
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
TestCase

6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5

*/
