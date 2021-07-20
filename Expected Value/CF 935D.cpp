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
        if(y%2==1) p=(p*x)%mod2;
        y/=2;
        x=(x*x)%mod2;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    ll n,m,zeros=0;
    cin>>n>>m;
    vll a(n),b(n),z(n+1,0);
    f(i,0,n) cin>>a[i];
    f(i,0,n) {
        cin>>b[i];
        z[i+1]=z[i];
        if(a[i]==0) z[i+1]++;
        if(b[i]==0) z[i+1]++;
    }
    ll num=0,den=power(power(m,z[n]),mod2-2);
    f(i,0,n) {
        if(a[i]==b[i]) {
            if(a[i]!=0) continue;
            num=(num+power(m,zeros+z[n]-z[i+1])*((m*m-m)/2)%mod2)%mod2;
            zeros++;
        }
        else if(a[i]==0) num=(num+power(m,zeros+z[n]-z[i+1])*(m-b[i]))%mod2;
        else if(b[i]==0) num=(num+power(m,zeros+z[n]-z[i+1])*(a[i]-1))%mod2;
        else {
            if(a[i]>b[i]) num=(num+power(m,zeros+z[n]-z[i+1]))%mod2;
            break;
        }
    }
    cout<<(num*den)%mod2;
    return 0;
}
