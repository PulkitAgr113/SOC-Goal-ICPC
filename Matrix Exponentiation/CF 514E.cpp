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
const int MAX_M = 101;
const ll MOD = mod2;

class matrix {

public:
    ll mat[MAX_M][MAX_M];

    matrix() {
        f(i,0,MAX_M) {
            f(j,0,MAX_M) mat[i][j]=0;
        }
    }

    void make_iden() {
        f(i,0,MAX_M) mat[i][i]=1;
    }

    matrix operator + (const matrix &o) const {
        matrix res;
        f(i,0,MAX_M) {
            f(j,0,MAX_M) res.mat[i][j]=(mat[i][j]+o.mat[i][j])%MOD;
        }
        return res;
    }

    matrix operator * (const matrix &o) const {
        matrix res;
        f(i,0,MAX_M) {
            f(j,0,MAX_M) {
                res.mat[i][j]=0;
                f(k,0,MAX_M) res.mat[i][j]=(res.mat[i][j]+(mat[i][k]*o.mat[k][j])%MOD)%MOD;
            }
        }
        return res;
    }
};

matrix power(matrix a, ll n) {
    matrix res;
    res.make_iden();
    while(n>0) {
        if(n&1) res=res*a;
        a=a*a;
        n>>=1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    ll n,x,y,flag=0;
    cin>>n>>x;
    matrix m;
    vll d(MAX_M),nodes(MAX_M,1);
    f(i,0,n) {
        cin>>y;
        d[y-1]++;
    }
    f(i,0,MAX_M-1) m.mat[0][i]=d[i];
    f(i,1,MAX_M-1) m.mat[i][i-1]=1;
    m.mat[MAX_M-1][MAX_M-1]=m.mat[MAX_M-1][0]=1;
    f(i,1,MAX_M) {
        nodes[i]=0;
        f(j,0,i) nodes[i]=(nodes[i]+(nodes[j]*d[i-j-1])%MOD)%MOD;
    }
    f(i,0,MAX_M-1) flag=(flag+nodes[i])%MOD;
    if(x<=100) {
        ll ans=0;
        f(i,0,x+1) ans=(ans+nodes[i])%MOD;
        cout<<ans;
    }
    else {
        m=power(m,x-99);
        ll ans=0;
        f(i,0,MAX_M-1) ans=(ans+(m.mat[MAX_M-1][i]*nodes[MAX_M-i-1])%MOD)%MOD;
        ans=(ans+(m.mat[MAX_M-1][MAX_M-1]*flag)%MOD)%MOD;
        cout<<ans;
    }
    return 0;
}
