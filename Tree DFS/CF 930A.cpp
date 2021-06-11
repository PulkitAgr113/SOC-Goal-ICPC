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
 
void dfs(vvi &adj, vb &visited, vi &dist, int v) {
    visited[v]=true;
    for(int u:adj[v]) {
        dist[u]=min(dist[v]+1,dist[u]);
        if(!visited[u]) dfs(adj,visited,dist,u);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,p,ans=0;
    cin>>n;
    vvi adj(n+1);
    vi dist(n+1,100000);
    unordered_map<int,int> c;
    vb visited(n+1,false);
    f(i,2,n+1) {
        cin>>p;
        adj[i].pb(p);
        adj[p].pb(i);
    }
    dist[1]=0;
    dfs(adj,visited,dist,1);
    f(i,1,n+1) c[dist[i]]++;
    for(auto u:c) ans+=(u.S%2);
    cout<<ans;
    return 0;
}
