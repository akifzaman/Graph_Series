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

vector <ll> G[1000001];
bool visited[1000001];
ll in[1000001];
ll out[1000001];
ll timer=1;

void solve(ll node){
    if(!visited[node]){
        visited[node]=1;
        in[node] = timer++;
        for(ll child: G[node]){
            if(!visited[child]){
                solve(child);
            }
        }
        out[node] = timer++;
    }
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll node, edge;
    cin>>node>>edge;
    for(ll i=0;i<edge;i++){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    for(ll i=1;i<=node;i++){
        if(!visited[i]){
            solve(i);
        }
    }
    for(ll i=1;i<=node;i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
    for(ll i=1;i<=node;i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;

    ///check if two given nodes share the same subtree
    ///by precalculating the in and out time, we can answer the query in O(1) time now!
    ll x , y;
    cin>>x>>y;
    if( (in[x]<in[y] && out[x]>out[y])||(in[x]<in[y] && out[x]>out[y]) ){
        cout<<"same subtree"<<endl;
    }
    else{
        cout<<"different subtree"<<endl;
    }
}


/*
[NB: In-Out time concept is very important for the articulation and bridge related problems.
     Also, you can check if two given nodes are part of a subtree of each other or not using
     this concept. for example:
5 4
1 2
2 3
2 4
4 5
     for this tree, if we calculate the in and out time array, we can see that for any two given
     nodes, the nodes will be part of a subtree of each other if we consider one of them as the root
     node and it has less in time than the other node which we will consider as the child node. Also, the
     root node will have greater out time than the child node[and vice-versa]. The in time of root node is
     lesser than the child because we start traversing the root node before the child node and the out time of
     root node is greater than the child because we finish traversing the root node after we finish traversing
     all of its child nodes.
     ]
*/
