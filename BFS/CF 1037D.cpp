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
 
void bfs(vvi &adj, vb &visited, qi &q, vi &dist, vi &par) {
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        for(int u:adj[v]) {
            if(!visited[u]) {
                visited[u]=true;
                q.push(u);
                par[u]=v;
                dist[u]=dist[v]+1;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,x,y;
    bool ans=true;
    cin>>n;
    vvi adj(n+1);
    vb visited(n+1,false);
    qi q;
    vi dist(n+1,0),a(n+1),par(n+1,0),pos(n+1);
    f(i,1,n) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    f(i,1,n+1) {
        cin>>a[i];
        pos[a[i]]=i;
    }
    pos[0]=0;
    q.push(1);
    visited[1]=true;
    bfs(adj,visited,q,dist,par);
    if(a[1]!=1) ans=false;
    f(i,2,n+1) {
        if(dist[a[i]]<dist[a[i-1]] || pos[par[a[i]]]<pos[par[a[i-1]]]) {
            ans=false;
            break;
        }
    }
    if(ans) cout<<"Yes";
    else cout<<"No";
    return 0;
}
