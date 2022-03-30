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
ll visited[1000001];

bool solve(ll node){
    visited[node]=1;
    for(ll child: G[node]){
        if(!visited[child]){
            if(solve(child)==true) return true;
        }
        else{
            if(child==1) return true;
        }
    }
    visited[node]=2;
    return false;
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
    }
    //cout<< solve(1) <<endl;
    for(ll i=1;i<=node;i++){
        if(!visited[i]){
            if(solve(i)){
                cout<<"Cycle found."<<endl;
                return 0;
            }
        }
    }
    cout<<"No cycle found."<<endl;
    return 0;
}
/*
NB: This algo works only for cycle detection in directed graph
    If there are more than one connected component in the graph then
    we need to run a for loop to iterate over all the nodes and run dfs
    for all the unvisited nodes.]

6 7
1 2
2 3
4 1
4 3
4 5
5 6
6 4

*/
