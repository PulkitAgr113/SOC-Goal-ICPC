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

int timer=0;

void dfs(vvi &adj, vvi &ancestor, vi &tin, vi &tout, vi &depth, int v, int par, int l) {
    timer++;
    tin[v]=timer;
    ancestor[v][0]=par;
    f(i,1,l+1) {
        ancestor[v][i]=ancestor[ancestor[v][i-1]][i-1];
    }
    for(int u:adj[v]) {
        if(u!=par) {
            depth[u]=depth[v]+1;
            dfs(adj,ancestor,tin,tout,depth,u,v,l);
        }
    }
    timer++;
    tout[v]=timer;
}

bool isAncestor(vi &tin, vi &tout, int u, int v) {
    if(tin[u]>tin[v] || tout[u]<tout[v]) return false;
    return true;
}

int lca(vvi &ancestor, vi &tin, vi &tout, vi &depth, int a, int b, int l) {
    if(isAncestor(tin,tout,a,b)) return depth[a];
    if(isAncestor(tin,tout,b,a)) return depth[b];
    for(int i=l;i>=0;i--) {
        if(!isAncestor(tin,tout,ancestor[a][i],b)) a=ancestor[a][i];
    }
    return depth[ancestor[a][0]];
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,q,x,y,z,a,b,c,l;
    cin>>n>>q;
    l=ceil(log2(n));
    vvi adj(n+1),ancestor(n+1,vi(l+1));
    vi tin(n+1),tout(n+1),depth(n+1,0);
    f(i,2,n+1) {
        cin>>x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    dfs(adj,ancestor,tin,tout,depth,1,1,l);
    while(q--) {
        cin>>a>>b>>c;
        x=lca(ancestor,tin,tout,depth,a,b,l);
        y=lca(ancestor,tin,tout,depth,a,c,l);
        z=lca(ancestor,tin,tout,depth,b,c,l);
        a=depth[a];
        b=depth[b];
        c=depth[c];
        if(x>y) cout<<max(max(a-x,b-x),x-y+c-y)+1<<"\n";
        else if(y>x) cout<<max(max(a-y,c-y),y-x+b-x)+1<<"\n";
        else cout<<max(max(b-z,c-z),z-x+a-x)+1<<"\n";
    }
    return 0;
}
