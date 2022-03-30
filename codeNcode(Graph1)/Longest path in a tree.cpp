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

vector <ll> G[10001];
bool visited[10001];

ll maxLen, maxNode;
ll dfs(ll n, ll d){
    visited[n]=1;
    if(d>maxLen){
        maxLen=d;
        maxNode=n;
    }
    for(ll v: G[n]){
        if(!visited[v]){
            dfs(v, d+1);
        }
    }
    return 0;
}

void solve(){
    ll node, edge;
    cin>>node;
    for(ll i=1;i<=(node-1);i++){
        ll x, y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    maxLen=-1;
    dfs(1, 0);
    for(ll i=0;i<10001;i++) visited[i]=0;
    dfs(maxNode, 0);
    cout<<maxLen<<endl;
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

/*
    1
    2
   3 6
  4 7 8
 5     9
        10
ans=7
*/

/*
[N.B.: This problem is about finding the longest path of a given tree.
       We can use 2-DFS concept to acquire the maximum length of a given tree.
       First, we can start the DFS from any arbitrary node which will give us a final node/ max node.
       Using that max node we will start the DFS again by which we will get the ultimate result which is the
       longest path of that given tree.]
*/
