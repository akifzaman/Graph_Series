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

/* This is just a simple representation of path compression. but in competitive programming this code will not be enough.
as according to the given problem, we might have unique sets with different set elements. so we might need to merge them if the
problem asks. if we need to merge any sets, then we will need to find the unique sets first, right?
so in that case, we will compress the path in that findRepresentative function as we have done in this code.
and after that we will do the rest of the task as per the problem statement. simple as that!
*/

ll element, relation, query;
ll parent[100001];

ll findRepresentative(ll n){
    if(n==parent[n]){
        return n;
    }
    else{
        return parent[n] = findRepresentative(parent[n]);
    }
}

void solve(){
    cin>>element>>relation;

    for(ll i=0;i<relation;i++){
        ll x, y;
        cin>>x>>y;
        parent[y]=x;
    }
    for(ll i=1;i<=element;i++){
        findRepresentative(i);
    }
    ///after path compression we can run the query in constant time complexity!
    cin>>query;
    while(query--){
        ll x;
        cin>>x;
        cout<< findRepresentative(x) <<endl;
    }
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

/*
TestCases:

5 5
3 1
2 3
2 2
5 4
2 5

5
1
2
3
4
5

Output:
2
2
2
2
2

*/
