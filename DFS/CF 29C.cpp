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
 
void dfs(unordered_map<int,vi> &adj, unordered_map<int,bool> &visited, vi &ans, int v) {
    visited[v]=true;
    for(auto u:adj[v]) {
        if(!visited[u]) {
            ans.pb(u);
            dfs(adj,visited,ans,u);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,a,b;
    cin>>n;
    unordered_map<int,vi> adj;
    unordered_map<int,bool> visited;
    vi ans;
    f(i,0,n) {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        visited[a]=visited[b]=false;
    }
    for(auto u:adj) {
        if(u.S.size()==1) {
            ans.pb(u.F);
            dfs(adj,visited,ans,u.F);
            break;
        }
    }
    for(auto u:ans) cout<<u<<" ";
    return 0;
}
