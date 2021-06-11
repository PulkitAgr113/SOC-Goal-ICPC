#include<bits/stdc++.h>
using namespace std;

#define f(i,x,n) for (int i=x;i<n;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long int ll ;
typedef vector<int> vi ;
typedef queue<int> qi ;
typedef vector<vector<int>> vvi ;
typedef vector<vector<ll>> vvll ;
typedef vector<vector<pair<int,int>>> vvp ;
typedef vector<bool> vb ;
typedef vector<double> vd ;
typedef vector<vector<char>> vvc ;
typedef vector<char> vc ;
typedef pair<int,int> pii ;
typedef vector<pair<int,int>> vpi ;
typedef vector<pair<ll,ll>> vpll ;
typedef pair<ll,ll> pll ;
typedef vector<ll> vll ;
typedef stack<int> si ;
typedef map<int,int> mii ;
typedef set<int> seti ;
typedef double db ;

int mod1 = 998244353 ;
int mod2 = 1000000007 ;

ll cost=0;

pii dfs(vvi &adj, vll &a, vi &b, vi &c, int v, int par) {
    int zero=0,one=0;
    if(b[v]==1 && c[v]==0) zero++;
    else if(b[v]==0 && c[v]==1) one++;
    for(int u:adj[v]) {
        if(u!=par) {
            a[u]=min(a[u],a[v]);
            pii p=dfs(adj,a,b,c,u,v);
            zero+=p.F;
            one+=p.S;
        }
    }
    ll pairs=min(zero,one);
    zero-=pairs;
    one-=pairs;
    cost+=2*pairs*a[v];
    return mp(zero,one);
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int t,n,x,y,sum=0,zero=0,one=0;
    cin>>n;
    vvi adj(n+1);
    vll a(n+1);
    vi b(n+1),c(n+1);
    f(i,1,n+1) {
        cin>>a[i]>>b[i]>>c[i];
        sum+=b[i]-c[i];
    }
    f(i,1,n) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if(sum!=0) cout<<"-1";
    else {
        dfs(adj,a,b,c,1,1);
        cout<<cost;
    }
    return 0;
}
