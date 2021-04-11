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
 
int cats=0, max_cats=0, ans=0;
 
void dfs(vvi &adj, vi &a, vb &visited, int v, int m) {
    visited[v]=true;
    if(a[v]==1) cats++;
    max_cats=max(max_cats,cats);
    if(a[v]==0) cats=0;
    int mc=max_cats,c=cats;
    if(v!=1 && adj[v].size()==1 && mc<=m) ans++;
    for(auto u:adj[v]) {
        cats=c;
        max_cats=mc;
        if(!visited[u]) dfs(adj,a,visited,u,m);
    }
}
 
int main() {
    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,m,x,y,v=1;
    cin>>n>>m;
    vi a(n+1);
    vvi adj(n+1);
    f(i,1,n+1) cin>>a[i];
    f(i,0,n-1) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vb visited(n+1,false);
    dfs(adj,a,visited,v,m);
    cout<<ans;
    return 0;
}
