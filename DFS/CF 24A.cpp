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
 
int cost1=0,cost2=0;
 
void dfs(vvp &adj, vb &visited, int v) {
    visited[v]=true;
    for(auto u:adj[v]) {
        if(v==1 && visited[u.F]) {
            if(u.S>0) cost2+=u.S;
            else {
                if(adj[u.F][0].F==v) cost1+=adj[u.F][0].S;
                else cost1+=adj[u.F][1].S;
            }
        }
        if(!visited[u.F]) {
            if(u.S>0) cost1+=u.S;
            else {
                if(adj[u.F][0].F==v) cost2+=adj[u.F][0].S;
                else cost2+=adj[u.F][1].S;
            }
            dfs(adj,visited,u.F);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,a,b,c;
    cin>>n;
    vvp adj(n+1);
    vb visited(n+1,false);
    vi orientation(n+1,0);
    f(i,0,n) {
        cin>>a>>b>>c;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,0));
    }
    dfs(adj,visited,1);
    cout<<min(cost1,cost2);
    return 0;
}
