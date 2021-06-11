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
int Max_M = 500001 ;

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
    int n,m,k,x,y;
    cin>>n>>m;
    f(i,1,n+1) make_set(i);
    f(i,0,m) {
        cin>>k;
        f(j,0,k) {
            cin>>x;
            if(j==0) y=x;
            else union_sets(x,y);
        }
    }
    f(i,1,n+1) cout<<sz[find_set(i)]<<" ";
    return 0;
}
