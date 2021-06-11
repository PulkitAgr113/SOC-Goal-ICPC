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

ll total_dist(vvll &dist, int n) {
    ll total=0;
    f(i,1,n+1) {
        f(j,i+1,n+1) total+=dist[i][j];
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int n,k,a,b,c;
    cin>>n;
    vvll dist(n+1,vll(n+1,0));
    f(i,1,n+1) {
        f(j,1,n+1) cin>>dist[i][j];
    }
    cin>>k;
    while(k--) {
        cin>>a>>b>>c;
        if(dist[a][b]>c) {
            dist[a][b]=dist[b][a]=c;
            f(i,1,n+1) {
                f(j,i+1,n+1) {
                    if(dist[i][j]>dist[i][a]+c+dist[b][j]) dist[i][j]=dist[j][i]=dist[i][a]+c+dist[b][j];
                    if(dist[i][j]>dist[i][b]+c+dist[a][j]) dist[i][j]=dist[j][i]=dist[i][b]+c+dist[a][j];
                }
            }
        }
        cout<<total_dist(dist,n)<<" ";
    }
    return 0;
}
