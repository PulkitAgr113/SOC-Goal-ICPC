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

void dfs(vvi &adj, vll &l, vll &r, vll &dp_l, vll &dp_r, int v, int par) {
    for(int u:adj[v]) {
        if(u!=par) {
            dfs(adj,l,r,dp_l,dp_r,u,v);
            dp_l[v]+=max(dp_r[u]+abs(r[u]-l[v]),dp_l[u]+abs(l[u]-l[v]));
            dp_r[v]+=max(dp_r[u]+abs(r[u]-r[v]),dp_l[u]+abs(l[u]-r[v]));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int t,n,u,v;
    cin>>t;
    while(t--) {
        cin>>n;
        vll l(n+1),r(n+1),dp_l(n+1,0),dp_r(n+1,0);
        vvi adj(n+1);
        f(i,1,n+1) cin>>l[i]>>r[i];
        f(i,1,n) {
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(adj,l,r,dp_l,dp_r,1,0);
        cout<<max(dp_l[1],dp_r[1])<<"\n";
    }
    return 0;
}
