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



ll element, relation, set_cnt;
ll parent[100001], Rank[100001];

ll findRepresentative(ll n){
    if(n==parent[n]){
        return n;
    }
    else{
        n=parent[n];
    }
    return findRepresentative(n);
}

void unionByRank(ll a, ll b){
    a = findRepresentative(a);
    b = findRepresentative(b);

    if(a==b) return;
    else if(Rank[a] > Rank[b]){
        parent[b]=a;
        Rank[a]+=Rank[b];
    }
    else{
        parent[a]=b;
        Rank[b]+=Rank[a];
    }
    return;
}

void solve(){
    for(ll i=1;i<=100001;i++){
        parent[i]=i;
        Rank[i]=1;
    }

    cin>>element>>relation;

    for(ll i=0;i<relation;i++){
        ll x, y; ///input represents that y is connected to x
        cin>>x>>y;
        parent[y]=x;
    }
    for(ll i=1;i<=element;i++){
        findRepresentative(i); ///finding the representative of every element
    }

    for(ll i=1;i<=element;i++){
        if(i==parent[i]){
            cout<< i <<" "; ///printing the unique set representatives
            set_cnt++; ///counting the number of set
        }
    }
    cout<<endl;
    cout<< set_cnt <<endl;
    set_cnt=0;


    ///union part
    ll a, b;
    cin>> a>> b;
    unionByRank(a, b);

    for(ll i=1;i<=element;i++){
        if(i==parent[i]){
            cout<< i <<" ";
            set_cnt++; ///we will see that after merging, the number of set will be reduced.
        }
    }
    cout<<endl;
    cout<< set_cnt <<endl;

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
6 4
1 2
4 3
4 5
5 6

Output:
1 4
2
1 4
4
1

*/
