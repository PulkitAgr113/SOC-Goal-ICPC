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

ll ans=-1e15,M=-1e15,m=-1e15;

void dfs(vvi &adj, vb &visited, vi &a, vll &sum, vll &maxsum, int v) {
    visited[v]=true;
    sum[v]+=a[v];
    if(v!=1 && adj[v].size()==1) maxsum[v]=sum[v];
    for(auto u:adj[v]) {
        if(!visited[u]) {
            dfs(adj,visited,a,sum,maxsum,u);
            sum[v]+=sum[u];
            maxsum[v]=max(maxsum[u],maxsum[v]);
        }
    }
    maxsum[v]=max(maxsum[v],sum[v]);
}

void bfs(vvi &adj, vb &visited, qi &q, vll &maxsum) {
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        M=m=-1e15;
        for(int u:adj[v]) {
            if(!visited[u]) {
                visited[u]=true;
                q.push(u);
                if(M<=maxsum[u]) {
                    m=M;
                    M=maxsum[u];
                }
                else if(m<=maxsum[u]) m=maxsum[u];
            }
        }
        ans=max(ans,M+m);
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,x,y;
    cin>>n;
    vvi adj(n+1);
    vb visited(n+1,false);
    qi q;
    vi a(n+1);
    vll sum(n+1,0),maxsum(n+1,-1e15);
    bool c=false;
    f(i,1,n+1) cin>>a[i];
    f(i,1,n) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if(adj[1].size()>1) c=true;
    f(i,2,n+1) {
        if(adj[i].size()>2) {
            c=true;
            break;
        }
    }
    if(c) {
        dfs(adj,visited,a,sum,maxsum,1);
        f(i,1,n+1) visited[i]=false;
        q.push(1);
        visited[1]=true;
        bfs(adj,visited,q,maxsum);
        cout<<ans;
    }
    else cout<<"Impossible";
    return 0;
}
