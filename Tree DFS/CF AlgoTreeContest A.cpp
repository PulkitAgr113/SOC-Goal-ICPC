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
 
int M=0,ver=1;
 
void dfs(vvi &adj, vb &visited, vi &dist, int v) {
    visited[v]=true;
    if(M<dist[v]) {
        M=dist[v];
        ver=v;
    } 
    for(auto u:adj[v]) {
        if(!visited[u]) {
            dist[u]=dist[v]+1;
            dfs(adj,visited,dist,u);
        }
    }
}
 
int main() {
    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,v=1,x,y;
    cin>>n;
    vvi adj(n+1);
    f(i,0,n-1) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi dist(n+1,0);
    vb visited(n+1,false);
    dfs(adj,visited,dist,v);
    v=ver;
    M=0;
    f(i,1,n+1) {
        dist[i]=0;
        visited[i]=false;
    }
    dfs(adj,visited,dist,v);
    cout<<3*M;;
    return 0;
}
