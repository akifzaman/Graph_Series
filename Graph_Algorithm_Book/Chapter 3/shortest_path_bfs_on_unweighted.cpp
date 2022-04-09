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
Graph example:
6 6

0 1
0 2
0 3
2 4
4 5
3 4
*/



vector <ll> G[10000];///adjacency list

void solve(){
    ll node, edge;
    cin>>node>>edge;

    ll distance[node], previous[node];
    vector <ll> path;

    ll source=0;
    distance[source]=0, previous[source]=-1;

    queue <ll> q;
    q.push(source);

    while(edge--){
        ll x,y;
        cin>>x>>y;
        G[x].push_back(y); ///use only this line for directed graph
        G[y].push_back(x); ///remove this line for directed graph
    }

    ll visited[node]={0};
    visited[0]=1;

    ///BFS starts from here
    while(!q.empty()){
        ll v=q.front();
        q.pop();
        for(ll u: G[v]){
            if(!visited[u]){
                visited[u]=1;
                q.push(u);
                distance[u]=distance[v]+1;
                previous[u]=v;
            }
        }
    }

    for(ll i=0;i<node;i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;

    ll destination=5;

    if(visited[destination]==0){
        cout<<"No path"<<endl;
        return;
    }
    else{
        ll x=destination;
        while(x!=-1){
            path.push_back(x);
            x=previous[x];
        }
    }
    reverse(path.begin(), path.end());
    for(ll i=0;i<path.size();i++){
        cout<<path[i]<<" ";
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
///this code works for directed graph as well if modified
///weight of every edge has to be 1 if considered for undirected graph
