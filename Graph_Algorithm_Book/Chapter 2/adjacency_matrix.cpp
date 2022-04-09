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

/* Graph Example
6 6

1 2
1 4
2 4
2 5
4 5
5 3
3 6
6 6
-1 -1
*/

///unweighted-undirected adjacency matrix representation
void adj_mat_unweighted(){
    ll r, c;
    cin>>r>>c;
    ll adjMat[r+1][c+1];
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            adjMat[i][j]=0;
        }
    }
    for(ll i=0;i<(r*c);i++){
        ll x, y;
        cin>>x>>y;
        if(x==-1 && y==-1) break;
        adjMat[x][y]=1;
        adjMat[y][x]=1;
    }
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

///unweighted-undirected adjacency matrix optimization(using bool instead of numeric decreases the required memory)
void adj_mat_unweighted_opt(){
    ll r, c;
    cin>>r>>c;
    bool adjMatOpt[r+1][c+1];
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            adjMatOpt[i][j]=false;
        }
    }
    for(ll i=0;i<(r*c);i++){
        ll x, y;
        cin>>x>>y;
        if(x==-1 && y==-1) break;
        adjMatOpt[x][y]=true;
        adjMatOpt[y][x]=true;
    }
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cout<<adjMatOpt[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

///weighted-directed adjacency matrix representation
void adj_mat_weighted_directed(){
    ll r, c;
    cin>>r>>c;
    ll adjMatW[r+1][c+1];
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            adjMatW[i][j]=INT_MAX;
        }
    }
    for(ll i=0;i<(r*c);i++){
        ll x, y, weight;
        cin>>x>>y>>weight;
        if(x==-1 && y==-1) break;
        adjMatW[x][y]=weight;
    }
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cout<<adjMatW[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    adj_mat_unweighted();
    //adj_mat_unweighted_opt();
    //adj_mat_weighted_directed();
}

/*
Disadvantage of adjacency matrix:
If there are more than one edge between any two nodes then adjacency matrix can not be used to represent
that graph.
Memory complexity O(N^2)

Advantage of adjacency matrix:
To check if there is an edge between any two nodes.
*/

