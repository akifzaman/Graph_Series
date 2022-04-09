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


ll r, c, cx, cy;
ll dx[8]={-1,-1,-1,0,0,1,1,1};
ll dy[8]={-1,0,1,-1,1,-1,0,1};
struct node{
    ll x, y, d;
    node(ll a, ll b, ll c){
        x=a, y=b, d=c;
    }
};

bool visited[1001][1001];
ll path[1001][1001];

bool check(ll pp, ll qq){
    if( pp<0 || pp>=r || qq<0 || qq>=c || visited[pp][qq]==true){
        return false;
    }
    return true;
}

void solve(){
    cin>>r>>c;
    cin>>cx>>cy;

    node n(cx, cy, 0);
    visited[cx][cy]=1;
    path[cx][cy]=0;
    queue <node> qn;
    qn.push(n);

    while(!qn.empty()){
        node u=qn.front();
        ll t=u.x;
        ll s=u.y;
        ll v=u.d;
        qn.pop();
        for(ll i=0;i<8;i++){
            ll X = t + dx[i];
            ll Y = s + dy[i];
            if(check(X, Y)){
                node A(X, Y, v+1);
                visited[X][Y]=1;
                path[X][Y]=A.d;
                qn.push(A);
            }
        }
    }
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cout<<path[i][j]<<" ";
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
    solve();
}
