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

int main() {
    int n,m,x,y,w,ind;
    cin>>n>>m;
    vvp adj(n+1);
    vb visited(n+1,false);
    vll dist(n+1,1e15);
    vi par(n+1,n);
    pqp q;
    dist[n]=0;
    q.push(mp(0,n));
    f(i,0,m) {
        cin>>x>>y>>w;
        adj[x].pb(mp(y,w));
        adj[y].pb(mp(x,w));
    }
    while(!q.empty()) {
        ind=q.top().S;
        q.pop();
        if(visited[ind]) continue;
        visited[ind]=true;
        for(pii u:adj[ind]) {
            if(!visited[u.F] && dist[u.F]>dist[ind]+u.S) {
                dist[u.F]=dist[ind]+u.S;
                par[u.F]=ind;
                q.push(mp(-dist[u.F],u.F));
            }
        }
    }
    if(dist[1]==1e15) cout<<"-1";
    else {
        ind=1;
        while(ind!=n) {
            cout<<ind<<" ";
            ind=par[ind];
        }
        cout<<n;
    }
}
