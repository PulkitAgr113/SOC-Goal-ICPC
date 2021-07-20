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

void dfs(vvi &child, vi &subtree, int v) {
    for(int u:child[v]) {
        dfs(child,subtree,u);
        subtree[v]+=subtree[u];
    }
}

void dfs1(vvi &child, vd &exp_val, vi &subtree, int v) {
    for(int u:child[v]) {
        exp_val[u]=exp_val[v]+1+(subtree[v]-subtree[u]-1)/2.0;
        dfs1(child,exp_val,subtree,u);
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,x;
    cin>>n;
    vvi child(n+1);
    vi subtree(n+1,1);
    vd exp_val(n+1,1);
    f(i,2,n+1) {
        cin>>x;
        child[x].pb(i);
    }
    dfs(child,subtree,1);
    dfs1(child,exp_val,subtree,1);
    f(i,1,n+1) cout<<setprecision(15)<<exp_val[i]<<" ";
    return 0;
}
