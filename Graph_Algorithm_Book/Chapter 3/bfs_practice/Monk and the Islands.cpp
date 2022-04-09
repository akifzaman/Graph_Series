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

ll solve(){
    ll n,m,x,y;
    cin>>n>>m;

    for(ll i=0;i<100001;i++){
        G[i].clear();
    }
    for(ll i=0;i<100001;i++){
        visited[i]=0;
    }

    for(ll i=0;i<m;i++){
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    ll level[100001]={0};
    queue<ll> q;
    visited[1]=1;
    q.push(1);
    level[1]=0;

    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(ll v: G[u]){
            if(!visited[v]){
                q.push(v);
                visited[v]=1;
                level[v]=level[u]+1;
                if(v==n){
                    return level[v];
                }
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll test;
    cin>>test;
    while(test--){
        cout<< solve() <<endl;
    }
}
