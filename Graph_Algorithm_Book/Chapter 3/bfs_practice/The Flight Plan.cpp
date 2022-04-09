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
vector <ll> path;
ll pr[10001];
bool visited[10001];

ll n, m, t, c;
void solve(){
    cin>>n>>m>>t>>c;

    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll x,y;
    cin>>x>>y;
    visited[x]=1;
    pr[x]=-1;
    queue<ll> q;
    q.push(x);

    while(!q.empty()){
        ll u=q.front();
        totalTime+=(t*((t+c)/t));
        q.pop();
        sort(G[u].begin(), G[u].end());
        for(ll v: G[u]){
            if(!visited[v]){
                visited[v]=1;
                q.push(v);
                pr[v]=u;
            }
        }
    }
    ll i=y;
    while(i!=-1){
        path.push_back(i);
        i=pr[i];
    }
    reverse(path.begin(), path.end());
    cout<<path.size()<<endl;
    for(ll j=0;j<path.size();j++){
        cout<<path[j]<<" ";
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
