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

vector <ll> G[100001];
bool visited[100001];
ll dist[100001];

void solve(ll n, ll dis){
    if(!visited[n]){
        visited[n]=1;
        dist[n]=dis;
        for(ll v:G[n]){
            if(!visited[v]){
                solve(v, dist[n]+1);
            }
        }
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
        ll x, y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    solve(1,0);
    for(ll i=1;i<=node;i++){
        if(!visited[i]){
            visited[i]=1;
            solve(i, dist[i]+1);
        }
    }
    ll g, ans=0,mini=INT_MAX;
    cin>>g;
    ll girls[g];
    for(ll i=0;i<g;i++) cin>>girls[i];
    sort(girls, girls+g);
    for(ll i=0;i<g;i++){
        if(dist[girls[i]]<mini){
            mini=dist[girls[i]];
            ans=girls[i];
        }
    }
    cout<<ans<<endl;
    return 0;

}
