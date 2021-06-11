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

void dfs(vvi &adj, vi &depth, int v, int par) {
    for(int u:adj[v]) {
        if(u!=par) {
            depth[u]=(depth[v]+1)%3;
            dfs(adj,depth,u,v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,x,y;
    cin>>n;
    vvi adj(n+1);
    vvll a(3,vll(n+1));
    vi depth(n+1,0);
    f(j,0,3) {
        f(i,1,n+1) cin>>a[j][i];
    }
    f(i,1,n) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool ans=true;
    x=0;
    f(i,1,n+1) {
        if(adj[i].size()>2) {
            ans=false;
            break;
        }
        if(adj[i].size()==1) {
            x++;
            y=i;
        }
    }
    if(x!=2) ans=false;
    if(!ans) cout<<"-1";
    else {
        dfs(adj,depth,y,y);
        vll cost(6,0);
        f(j,0,3) {
            f(i,1,n+1) cost[j]+=a[(depth[i]+j)%3][i];
        }
        f(j,3,6) {
            f(i,1,n+1) cost[j]+=a[(j-depth[i])%3][i];
        }
        cout<<*min_element(cost.begin(),cost.end())<<"\n";
        int ind=min_element(cost.begin(),cost.end())-cost.begin();
        if(ind<3) {
            f(i,1,n+1) cout<<1+(depth[i]+ind)%3<<" ";
        }
        else {
            f(i,1,n+1) cout<<1+(ind-depth[i])%3<<" ";
        }
    }
    return 0;
}
