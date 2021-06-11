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

vi par(Max_M),rnk(Max_M);

void make_set(int v) {
    par[v]=v;
    rnk[v]=0;
}

int find_set(int v) {
    if(par[v]==v) return v;
    return par[v]=find_set(par[v]);
}

void union_sets(int a, int b) {
    a=find_set(a);
    b=find_set(b);
    if(a!=b) {
        if(rnk[a]<rnk[b]) swap(a,b);
        par[b]=a;
        if(rnk[a]==rnk[b]) rnk[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,x,y,edge=0,ind,r,root=0;
    cin>>n;
    vpi seg(n),vertices;
    set<pii> active;
    f(i,0,n) {
        cin>>x>>y;
        seg[i]=mp(x,y);
        vertices.pb(mp(x,i));
        vertices.pb(mp(y,i));
        make_set(i);
    }
    sort(vertices.begin(),vertices.end());
    for(auto u:vertices) {
        if(edge>=n) break;
        if(active.count(u)) {
            active.erase(u);
            continue;
        }
        ind=u.S;
        r=seg[ind].S;
        for(auto v:active) {
            if(v.F>=r) break;
            union_sets(v.S,ind);
            edge++;
            if(edge>=n) break;
        }
        active.insert(mp(r,ind));
    }
    f(i,0,n) {
        if(par[i]==i) root++;
    }
    if(root==1 && edge==n-1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
