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

/*Bicolorable Graph example
5 6

1 3
1 2
3 4
4 2
3 5
2 5

Output: 1
*/

vector<ll> G[10000];
bool bicolorability_check(){
    ll node, edge;
    cin>>node>>edge;

    while(edge--){
        ll x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    ll source=1;
    ll color[node+10]={0};
    color[source]=1;
    queue <ll> q;
    q.push(source);

    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(ll v: G[u]){
            if(color[v]==0){
                if(color[u]==1){
                    color[v]=2;
                }
                else color[v]=1;
                q.push(v);
            }
            if(color[u]==color[v]) return false;
        }
    }
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cout<< bicolorability_check() <<endl;
}
/*Non-Bicolorable Graph example
5 7

1 3
1 2
3 4
4 2
3 5
2 5
1 4

Output: 0
[Note: If a graph has a cycle of odd length, then the graph is not bicolorable.
In the above example, [1,3,4] has a cycle of odd length.]
*/
