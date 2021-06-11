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

void dfs(vvi &adj, vb &visited, vi &max_subtree, vi &subtree, int v, int n) {
    visited[v]=true;
    for(int u:adj[v]) {
        if(!visited[u]) {
            dfs(adj,visited,max_subtree,subtree,u,n);
            max_subtree[v]=max(max_subtree[v],subtree[u]);
            subtree[v]+=subtree[u];
        }
    }
    max_subtree[v]=max(max_subtree[v],n-subtree[v]);
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int t,n,x,y;
    cin>>t;
    while(t--) {
        cin>>n;
        vvi adj(n+1);
        vb visited(n+1,false);
        vi max_subtree(n+1,0),subtree(n+1,1);
        f(i,1,n) {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(adj,visited,max_subtree,subtree,1,n);
        max_subtree[0]=n-1;
        int m=min_element(max_subtree.begin(),max_subtree.end())-max_subtree.begin();
        if(count(max_subtree.begin(),max_subtree.end(),max_subtree[m])==1) cout<<"1 "<<adj[1][0]<<"\n"<<"1 "<<adj[1][0]<<"\n";
        else {
            int ind;
            f(i,m+1,n+1) {
                if(max_subtree[i]==max_subtree[m] && i!=m) {
                    ind=i;
                    break;
                }
            }
            if(adj[m][0]!=ind) x=0;
            else x=1;
            cout<<adj[m][x]<<" "<<m<<"\n"<<adj[m][x]<<" "<<ind<<"\n";
        }
    }
    return 0;
}
