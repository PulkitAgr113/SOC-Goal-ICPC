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

ll power(ll n, ll x, ll M) {
    ll p=1;
    while(x>0) {
        if(x%2==1) p=(p*n)%M;
        n=(n*n)%M;
        x/=2;
    }
    return p;
}

vvll dp(401,vll(401,1));

ll binom(ll p) {
    for(ll i=1;i<=400;i++) {
        for(ll j=1;j<=i;j++) {
            if(j>i-j) dp[i][j]=dp[i][i-j];
            else dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%p;
        }
        dp[i][i+1]=0;
    }
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    ll n,m,ans=0;
    cin>>n>>m;
    binom(m);
    for(ll k=1;k<=n;k++) {
        if(n-2*k+1<0) break;
        ll term=0;
        for(ll j=0;j<k;j++) {
            if(j%2==0) term=(term+(dp[k][j]*power(k-j,n-k+1,m))%m)%m;
            else term=(term-(dp[k][j]*power(k-j,n-k+1,m))%m)%m;
            if(term<0) term+=m;
        }
        ans+=(power(2,n-2*k+1,m)*term)%m;
    }
    ans%=m;
    cout<<ans;
    return 0;
}
