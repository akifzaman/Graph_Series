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


///findRepresentative() function returns the representative of a set.
///element that returns the same representative, belongs to the same set.
///by finding the representative of the elements, we can actually know how many different sets are there.
///we can perform merge/union on the different sets after that.

///Importance of Path Compression:
/*we are finding representative for each and every element by the same recursive formula, so we are actually doing some calculations
again and again. It is because we are not really changing anything in the relation section(in the parent[] array i mean).
we are just finding which set an particular element belongs to. But doing so, we are wasting time and resources.
We could apply path compression which could perform faster. Path compression means decreasing the depth of the given tree.
Suppose A is a friend of B, B is a friend of C and C is a friend of D [provided that, mutual friends are also friends of each other.]
If we represent their friendship as a tree then the depth of the tree will be 3 (A->B->C->D).
But as we can see, they belong to the same set, they all will have the same representative.
Suppose their representative is A. So, by doing path compression, we will not calculate/find the representative of B, C and D again and again.
We will change the parent[] array and we will put A as the parent of all the other elements.
By doing that, we actually decreased the depth of the tree and now we can find the representative of an element in O(1) time complexity.
*/

///Importance of Union by Rank:
/*by using union by rank method, we can also improve the runtime of the find function hence improving the overall program performance.
*/

ll element, relation;
ll parent[100001];

ll findRepresentative(ll n){
    if(n==parent[n]){
        return n;
    }
    else{
        n=parent[n];
    }
    return findRepresentative(n);
}


void solve(){
    cin>>element>>relation;

    for(ll i=0;i<relation;i++){
        ll x, y; ///input represents that y is connected to x
        cin>>x>>y;
        parent[y]=x;
    }
    cout<< findRepresentative(5) <<endl;
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

5 5
3 1
2 3
2 2
5 4
2 5

Output: 2
*/
