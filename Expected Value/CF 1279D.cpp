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

ll inverse(ll n) {
    ll p=mod1-2;
    ll pow=1;
    while(p>0) {
        if(p%2==1) pow=(pow*n)%mod1;
        n=(n*n)%mod1;
        p/=2;
    }
    return pow;
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    ll n,x,ans=0;
    cin>>n;
    vvll a(1000001);
    vll k(n);
    f(i,0,n) {
        cin>>k[i];
        f(j,0,k[i]) {
            cin>>x;
            a[x].pb(i);
        }
    }
    f(i,1,1000001) {
        for(auto u:a[i]) {
            ll flag=(a[i].size()*inverse(k[u]))%mod1;
            flag=(flag*inverse(n))%mod1;
            flag=(flag*inverse(n))%mod1;
            ans=(ans+flag)%mod1;
        }
    }
    cout<<ans;
    return 0;
}
