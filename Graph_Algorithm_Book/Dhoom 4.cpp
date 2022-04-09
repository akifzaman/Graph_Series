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

void solve(){
    ll x, target, n;
    cin>>x>>target>>n;
    queue <ll> q;
    vector <ll> s;
    vector <ll> visited(1000001,-1);
    q.push(x);
    visited[x]=0;
    for(ll i=0;i<n;i++){
        ll y;
        cin>>y;
        s.push_back(y);
    }
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        if(u==target) break;
        for(auto v: s){
            ll m=(u*v)%100000;
            if( visited[m]==-1 ){
                q.push(m);
                visited[m]=visited[u]+1;
            }
        }
    }
    cout<<visited[target]<<endl;
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
