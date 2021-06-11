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
    int n,m,k,x,y,w,ind;
    cin>>n>>m>>k;
    vvp adj(n+1);
    vll dist(n+1,1e15),dist_train(n+1,1e15);
    pqp q;
    dist[1]=0;
    q.push(mp(0,1));
    f(i,0,m) {
        cin>>x>>y>>w;
        adj[x].pb(mp(y,w));
        adj[y].pb(mp(x,w));
    }
    f(i,0,k) {
        cin>>x>>y;
        if(dist_train[x]>y) dist_train[x]=y;
    }
    while(!q.empty()) {
        ind=q.top().S;
        w=q.top().F;
        q.pop();
        if(w!=-dist[ind]) continue;
        ll min_dist;
        if(dist[ind]>dist_train[ind]) min_dist=dist_train[ind];
        else min_dist=dist[ind];
        for(pii u:adj[ind]) {
            if(dist[u.F]>min_dist+u.S) {
                dist[u.F]=min_dist+u.S;
                q.push(mp(-dist[u.F],u.F));
            }
        }
    }
    int ans=k;
    f(i,2,n+1) {
        if(dist_train[i]<dist[i]) ans--;
    }
    cout<<ans;
}
