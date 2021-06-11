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
int Max_M = 1001 ;

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
    int n,a,b,c=0;
    cin>>n;
    vpi edges,del;
    vi add;
    f(i,1,n+1) make_set(i);
    f(i,1,n) {
        cin>>a>>b;
        edges.pb(mp(a,b));
        union_sets(a,b);
    }
    f(i,1,n+1) {
        if(find_set(i)==i) {
            add.pb(i);
            c++;
        }
    }
    f(i,1,n+1) make_set(i);
    f(i,0,n-1) {
        a=edges[i].F;
        b=edges[i].S;
        if(find_set(a)!=find_set(b)) union_sets(a,b);
        else del.pb(mp(a,b));
    }
    cout<<c-1<<"\n";
    f(i,1,c) cout<<del[i-1].F<<" "<<del[i-1].S<<" "<<add[i]<<" "<<add[i-1]<<"\n";
    return 0;
}
