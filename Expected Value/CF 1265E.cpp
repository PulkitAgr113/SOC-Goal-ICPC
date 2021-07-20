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

ll power(ll x, ll y) {
    ll p=1;
    while(y>0) {
        if(y%2==1) p=(p*x)%mod1;
        y/=2;
        x=(x*x)%mod1;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    ll n;
    cin>>n;
    vll p(n),prod(n+1,1);
    f(i,0,n) {
        cin>>p[i];
        prod[i+1]=(prod[i]*p[i])%mod1;
    }
    ll num=0,den=power(prod[n],mod1-2);
    f(i,0,n) num=(num+power(100,n-i)*prod[i])%mod1;
    cout<<(num*den)%mod1;
    return 0;
}
