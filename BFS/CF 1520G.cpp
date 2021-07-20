#include<bits/stdc++.h>
using namespace std;

#define f(i,x,n) for (int i=x;i<n;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long int ll ;
typedef vector<int> vi ;
typedef priority_queue<int> pqi ;
typedef priority_queue<pair<int,int>> pqp ;
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

void bfs(vvll &a, vvll &dist, vvll &portal, vector<vb> &visited, queue<pii> &q, ll &n, ll &m, ll &w) {
    while(!q.empty()) {
        pii u=q.front();
        int i=u.F,j=u.S;
        q.pop();
        if(a[i][j]>0) portal[i][j]=dist[i][j]+a[i][j];
        if(i>0) {
            if(a[i-1][j]>=0 && !visited[i-1][j]) {
                dist[i-1][j]=dist[i][j]+w;
                q.push(mp(i-1,j));
                visited[i-1][j]=true;
            }
        }
        if(j>0) {
            if(a[i][j-1]>=0 && !visited[i][j-1]) {
                dist[i][j-1]=dist[i][j]+w;
                q.push(mp(i,j-1));
                visited[i][j-1]=true;
            }
        }
        if(i<n-1) {
            if(a[i+1][j]>=0 && !visited[i+1][j]) {
                dist[i+1][j]=dist[i][j]+w;
                q.push(mp(i+1,j));
                visited[i+1][j]=true;
            }
        }
        if(j<m-1) {
            if(a[i][j+1]>=0 && !visited[i][j+1]) {
                dist[i][j+1]=dist[i][j]+w;
                q.push(mp(i,j+1));
                visited[i][j+1]=true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    ll n,m,w;
    cin>>n>>m>>w;
    vvll a(n,vll(m)),dist(n,vll(m,1e17)),portal(n,vll(m,1e17));
    vector<vb> visited(n,vb(m,false));
    queue<pii> q;
    q.push(mp(0,0));
    visited[0][0]=true;
    dist[0][0]=0;
    f(i,0,n) {
        f(j,0,m) cin>>a[i][j];
    }
    ll x=1e17,y=1e17,z=1e17;
    bfs(a,dist,portal,visited,q,n,m,w);
    x=min(x,dist[n-1][m-1]);
    f(i,0,n) {
        f(j,0,m) {
            if(a[i][j]>0) y=min(y,portal[i][j]);
            visited[i][j]=false;
            dist[i][j]=1e17;
            portal[i][j]=1e17;
        }
    }
    visited[n-1][m-1]=true;
    dist[n-1][m-1]=0;
    q.push(mp(n-1,m-1));
    bfs(a,dist,portal,visited,q,n,m,w);
    f(i,0,n) {
        f(j,0,m) {
            if(a[i][j]>0) z=min(z,portal[i][j]);
        }
    }
    if(x>=1e17 && y+z>=1e17) cout<<"-1";
    else cout<<min(x,y+z);
    return 0;
}
