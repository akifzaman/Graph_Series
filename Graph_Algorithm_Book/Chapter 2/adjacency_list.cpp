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
5 6

0 1
0 2
1 2
1 3
1 4
3 4
*/

///unweighted-undirected adjacency list representation
void adj_list_unweighted(){

    ll node, edge, x, y;
    cin>>node>>edge;

    vector <ll> v[5]; /// v[x] means array of vectors, where v(x) means a vector with size=5
    for(ll i=0;i<edge;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout<<endl;

    for(ll i=0;i<node;i++){
        cout<<i<<" -> ";
        for(ll j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}

///weighted-undirected adjacency list representation
/* Graph example(weighted-undirected graph)
5 6

0 1 8
0 2 8
1 2 8
1 3 8
1 4 8
3 4 8
*/
void adj_list_weighted(){
    ll node, edge, x, y, weight;
    vector <pair<ll,ll>> v[5];
    cin>>node>>edge;

    for(ll i=0;i<edge;i++){
        cin>>x>>y>>weight;
        v[x].push_back(make_pair(y, weight));
        v[y].push_back(make_pair(x, weight));
    }

    for(ll i=0;i<node;i++){
        cout<<i<<" ->";
        for(ll j=0;j<v[i].size();j++){
            cout<<"("<<v[i][j].first<<","<<v[i][j].second<<")"<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    //adj_list_unweighted();
    adj_list_weighted();
}

/*
Disadvantage of adjacency list:
If there is an edge between any two nodes, it can not be check in O(1) time as it could be done in case of
adjacency matrix.

Advantage of adjacency list:
Memory complexity: O(E)
If you want to know all the adjacent node to any particular node then use adjacency list because it wont require
to traverse over the whole adjacency list to show you the adjacent nodes as it was required in case of adjacency
matrix.
*/
