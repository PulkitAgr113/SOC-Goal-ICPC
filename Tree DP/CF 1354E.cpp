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

vpi dist_parity;

bool bfs(vvi &adj, vb &visited, vb &bipartite, qi &q, vi &dist) {
    pii p=mp(1,0);
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        for(int u:adj[v]) {
            if(!visited[u]) {
                visited[u]=true;
                q.push(u);
                dist[u]=dist[v]+1;
                if(dist[u]%2==0) p.F++;
                else {
                    p.S++;
                    bipartite[u]=true;
                }
            }
            else if(visited[u] && bipartite[u]==bipartite[v]) return false;
        }
    }
    dist_parity.pb(p);
    return true;
}

int flag=-1,color1=0;

void bfs1(vvi &adj, vb &visited, qi &q, vi &achievable, vi &dist, vi &color, int a) {
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        if(dist[v]%2==achievable[flag]) color[v]=2;
        for(int u:adj[v]) {
            if(!visited[u]) {
                visited[u]=true;
                q.push(u);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,m,x,y,a,b,c;
    cin>>n>>m>>a>>b>>c;
    vvi adj(n+1);
    vb visited(n+1,false),bipartite(n+1,false);
    vi dist(n+1,0),color(n+1,0);
    qi q;
    bool ans=true;
    f(i,0,m) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    f(i,1,n+1) {
        if(!visited[i]) {
            q.push(i);
            visited[i]=true;
            ans=bfs(adj,visited,bipartite,q,dist);
            if(!ans) break;
        }
    }
    if(ans) {
        x=dist_parity.size();
        vvi dp(x+1,vi(n+1,-1));
        dp[0][0]=0;
        f(i,0,x) {
            f(j,0,n+1)  {
                if(dp[i][j]!=-1) {
                    dp[i+1][j+dist_parity[i].F]=0;
                    dp[i+1][j+dist_parity[i].S]=1;
                }
            }
        }
        if(dp[x][b]==-1) ans=false;
        if(ans) {
            vi achievable(x);
            y=b;
            for(int i=x;i>0;i--) {
                achievable[i-1]=dp[i][y];
                if(dp[i][y]==1) y-=dist_parity[i-1].S;
                else y-=dist_parity[i-1].F;
            }
            f(i,1,n+1) visited[i]=false;
            f(i,1,n+1) {
                if(!visited[i]) {
                    flag++;
                    q.push(i);
                    visited[i]=true;
                    bfs1(adj,visited,q,achievable,dist,color,a);
                }
            }
            f(i,1,n+1) {
                if(color[i]==0) {
                    if(color1<a) {
                        color1++;
                        color[i]=1;
                    }
                    else color[i]=3;
                }
            }
        }
    }
    if(!ans) cout<<"NO";
    else {
        cout<<"YES\n";
        f(i,1,n+1) cout<<color[i];
    }
    return 0;
}
