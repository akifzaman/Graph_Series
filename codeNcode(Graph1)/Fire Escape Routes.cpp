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
ll cc=0, ccs=1, ccss=1;

void solve(ll node){
    if(!visited[node]){
        visited[node]=1;
        for(ll child: G[node]){
            if(!visited[child]){
                ccs++;
                solve(child);
            }
        }
    }
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll test;
    cin>>test;
    while(test--){
        ll node, edge;
        cin>>node>>edge;
        for(ll i=0;i<edge;i++){
            ll x, y;
            cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
        for(ll i=1;i<=node;i++){
            if(!visited[i]){
                solve(i);
                cc++;
                ccss = ((ccss%M)*(ccs%M))%M;
                ccs=1;
            }
        }
        cout<< cc <<" "<< (ccss%M) <<endl;
        cc=0;
        ccs=1;
        ccss=1;
        for(ll i=0;i<1000001;i++) G[i].clear();
        for(ll i=0;i<1000001;i++) visited[i]=0;
    }
}
