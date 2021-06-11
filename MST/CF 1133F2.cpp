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
int Max_M = 200001 ;

vi par(Max_M),sz(Max_M);

void make_set(int v) {
    par[v]=v;
    sz[v]=1;
}

int find_set(int v) {
    if(par[v]==v) return v;
    return par[v]=find_set(par[v]);
}

void union_sets(int a, int b) {
    a=find_set(a);
    b=find_set(b);
    if(a!=b) {
        if(sz[a]<sz[b]) swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,m,d,x,y;
    cin>>n>>m>>d;
    vvi adj(n+1);
    seti roots;
    f(i,2,n+1) make_set(i);
    while(m--) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        if(x!=1 && y!=1) union_sets(x,y);
    }
    f(i,2,n+1) {
        if(find_set(i)==i) roots.insert(i);
    }
    if(d>=roots.size() && d<=adj[1].size()) {
        cout<<"YES\n";
        vpi edges;
        for(auto u:adj[1]) {
            auto it=roots.find(find_set(u));
            if(it!=roots.end() && find_set(u)!=u) {
                roots.erase(it);
                roots.insert(u);
            }
        }
        f(i,1,n+1) make_set(i);
        for(auto u:roots) {
            union_sets(1,u);
            edges.pb(mp(1,u));
        }
        y=d-roots.size();
        for(auto u:adj[1]) {
            if(y==0) break;
            if(roots.find(u)==roots.end()) {
                union_sets(1,u);
                edges.pb(mp(1,u));
                y--;
            }
        }
        x=d;
        f(i,2,n+1) {
            if(x==n-1) break;
            for(auto u:adj[i]) {
                if(u!=1 && find_set(i)!=find_set(u)) {
                    union_sets(i,u);
                    edges.pb(mp(i,u));
                    x++;
                }
                if(x==n-1) break;
            }
        }
        for(auto u:edges) cout<<u.F<<" "<<u.S<<"\n";
    }
    else cout<<"NO";
    return 0;
}
