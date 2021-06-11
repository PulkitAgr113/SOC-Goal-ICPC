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

void dfs(vvi &adj, vd &exp_val, int v, int par) {
    for(int u:adj[v]) {
        if(u!=par) {
            dfs(adj,exp_val,u,v);
            if(v!=1) exp_val[v]+=(exp_val[u]+1)/(adj[v].size()-1);
            else exp_val[v]+=(exp_val[u]+1)/adj[v].size();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,x,y;
    cin>>n;
    vvi adj(n+1);
    vd exp_val(n+1,0);
    f(i,1,n) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(adj,exp_val,1,1);
    cout<<fixed<<setprecision(15)<<exp_val[1];
    return 0;
}
