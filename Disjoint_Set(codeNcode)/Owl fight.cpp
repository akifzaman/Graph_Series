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
https://assessment.hackerearth.com/challenges/college/codemania-20/algorithm/owl-fight/
*/

ll ar[100001];
ll find(ll a)
{
    if(ar[a] < 0) return a;

    return ar[a] = find(ar[a]);
}

void Union(ll a , ll b)
{
    ar[a] = min(ar[a] , ar[b]); ///we want the strongest owl
    ar[b] = a;
}

int main()
{
    ll n , m , q , a , b , x , y;
    cin>>n>>m;

    for(ll i=1;i<=n;i++)
        ar[i] = -i; ///most important to understand

    for(ll i=1;i<=m;i++){
        cin>>a>>b;
        a = find(a);
        b = find(b);
        if(a != b) Union(a , b);
    }

    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        x = a, y = b;
        a = find(a) , b = find(b);
        if(a == b)
        cout<<"TIE\n";

        else
        {
            if(ar[a] < ar[b]) ///as we took the negative value so which owl has less negative value, will win!
            cout<<x<<endl;
            else
            cout<<y<<endl;
        }
    }
}
