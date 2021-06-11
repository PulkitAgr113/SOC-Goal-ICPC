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
 
bool ans=true;
 
void bfs(vvi &adj, vb &visited, qi &q, vi &dist, vi &color) {
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        for(int u:adj[v]) {
            if(!visited[u]) {
                visited[u]=true;
                q.push(u);
                dist[u]=dist[v]+1;
                color[u]=dist[u]%2;
            }
            if(color[u]==color[v]) {
                ans=false;
                return;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,m,x,y;
    cin>>n>>m;
    vvi adj(n+1);
    vb visited(n+1,false);
    qi q;
    vi dist(n+1,0),color(n+1);
    f(i,0,m) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    f(i,1,n+1) {
        if(!visited[i]) {
            visited[i]=true;
            q.push(i);
            color[i]=0;
            bfs(adj,visited,q,dist,color);
        }
        if(!ans) break;
    }
    if(!ans) cout<<"-1";
    else {
        vi arya,pari;
        f(i,1,n+1) {
            if(color[i]==0) arya.pb(i);
            else pari.pb(i);
        }
        cout<<arya.size()<<"\n";
        for(int u:arya) cout<<u<<" ";
        cout<<"\n";
        cout<<pari.size()<<"\n";
        for(int u:pari) cout<<u<<" ";
    }
    return 0;
}
