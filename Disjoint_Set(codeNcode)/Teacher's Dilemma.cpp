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
Problem Link:
https://www.hackerearth.com/problem/algorithm/teachers-dilemma-3-00955296/?msclkid=ce94a374c30611ec87de9744cd9d42b6
*/


ll element, relation;
ll parent[100001];

ll findRepresentative(ll n){
    if(parent[n]<0){
        return n;
    }
    else{
        return findRepresentative(parent[n]);
        //return parent[n] = findRepresentative(parent[n]); ///applying path compression
    }
}

void Union(ll a, ll b){
    parent[a]+=parent[b];
    parent[b]=a;
}

void solve(){
    for(ll i=0;i<100001;i++){
        parent[i]=-1;
    }
    cin>>element>>relation;

    for(ll i=0;i<relation;i++){
        ll x, y;
        cin>>x>>y;
        x = findRepresentative(x);
        y = findRepresentative(y);
        if(x!=y){
            Union(min(x,y), max(x,y));
        }
    }
    /*for(ll i=1;i<=element;i++){
        cout<< abs(parent[i]) <<" "; ///we can check how many students form each group
    }
    cout<<endl;*/

    ll ans=1;
    for(ll i=0;i<element;i++){
        if(parent[i]<0){
            ans=( (ans%M) * ((abs(parent[i]))%M) ) % M;
        }
    }
    cout<< ans <<endl;
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

/*
TestCase:

8 5
1 2
2 3
1 3
4 5
5 3

Output:
5

*/
