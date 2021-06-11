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
 
void dfs(vvp &adj, vb &visited, vi &cost, int v) {
    visited[v]=true;
    for(auto u:adj[v]) {
        if(!visited[u.F]) {
            cost[u.F]=cost[v]+u.S;
            dfs(adj,visited,cost,u.F);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,x,y,z,v=0;
    cin>>n;
    vvp adj(n);
    vi cost(n,0);
    vb visited(n,false);
    f(i,0,n-1) {
        cin>>x>>y>>z;
        adj[x].pb(mp(y,z));
        adj[y].pb(mp(x,z));
    }
    dfs(adj,visited,cost,v);
    cout<<*max_element(cost.begin(),cost.end());
    return 0;
}
