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
 
void bfs(vvi &adj, vb &visited, qi &q, vi &dist) {
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        for(int u:adj[v]) {
            if(!visited[u]) {
                visited[u]=true;
                q.push(u);
                dist[u]=dist[v]+1;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,m,x,y,s,t,ans=0;
    cin>>n>>m>>s>>t;
    vvi adj(n+1),adj1(n+1,vi (n+1,0));
    vb visited(n+1,false);
    qi q;
    vi dist1(n+1,1000),dist2(n+1,1000);
    f(i,0,m) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        adj1[x][y]=adj1[y][x]=1;
    }
    dist1[s]=0;
    q.push(s);
    visited[s]=true;
    bfs(adj,visited,q,dist1);
    dist2[t]=0;
    q.push(t);
    f(i,1,n+1) visited[i]=false;
    visited[t]=true;
    bfs(adj,visited,q,dist2);
    x=dist1[t];
    f(i,1,n+1) {
        f(j,i+1,n+1) {
            if(adj1[i][j]==0 && min(dist1[i]+dist2[j],dist1[j]+dist2[i])>=x-1) ans++;
        }
    }
    cout<<ans;
    return 0;
}
