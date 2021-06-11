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

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    int t=1,n,m,k;
    while(t--) {
        cin>>n>>m>>k;
        vvi a(n,vi(m-1)),b(n-1,vi(m));
        f(i,0,n) {
            f(j,0,m-1) cin>>a[i][j];
        }
        f(i,0,n-1) {
            f(j,0,m) cin>>b[i][j];
        }
        if(k%2==1) {
            f(i,0,n) {
                f(j,0,m) cout<<"-1 ";
                cout<<"\n";
            }
            return 0;
        }
        vector<vvi> bore(10,vvi(n,vi(m)));
        f(c,0,10) {
            f(i,0,n) {
                f(j,0,m) {
                    if(c==0) {
                        if(j<m-1) bore[c][i][j]=a[i][j];
                        else bore[c][i][j]=a[i][j-1];
                        if(j>0) bore[c][i][j]=min(bore[c][i][j],a[i][j-1]);
                        if(i<n-1) bore[c][i][j]=min(bore[c][i][j],b[i][j]);
                        if(i>0) bore[c][i][j]=min(bore[c][i][j],b[i-1][j]);
                    }
                    else {
                        if(j<m-1) bore[c][i][j]=bore[c-1][i][j+1]+a[i][j];
                        else bore[c][i][j]=bore[c-1][i][j-1]+a[i][j-1];
                        if(j>0) bore[c][i][j]=min(bore[c][i][j],bore[c-1][i][j-1]+a[i][j-1]);
                        if(i<n-1) bore[c][i][j]=min(bore[c][i][j],bore[c-1][i+1][j]+b[i][j]);
                        if(i>0) bore[c][i][j]=min(bore[c][i][j],bore[c-1][i-1][j]+b[i-1][j]);
                    }
                }
            }
        }
        f(i,0,n) {
            f(j,0,m) cout<<2*bore[k/2-1][i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
