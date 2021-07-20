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
    ll n,ans=0;
    cin>>n;
    vll a(n),pow(n+1,1);
    f(i,0,n) cin>>a[i];
    f(i,1,n+1) pow[i]=(2*pow[i-1])%mod1;
    f(i,1,n+1) {
        if(i==n) ans=(ans+a[n-1])%mod1;
        else ans=(ans+(((n-i)*pow[n-i-1]+pow[n-i])%mod1*a[i-1])%mod1)%mod1;
    }
    cout<<ans;
    return 0;
}
