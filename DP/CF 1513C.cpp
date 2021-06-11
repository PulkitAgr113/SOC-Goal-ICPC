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
    int t,n,m;
    vll len0(200001,1),len1(200001,1);
    len1[9]=2;
    f(i,10,200001) {
        len0[i]=(len1[i-10]+len0[i-10])%mod2;
        len1[i]=(len0[i-9]+len1[i-9])%mod2;
    }
    cin>>t;
    while(t--) {
        cin>>n>>m;
        vll cnt(10,0);
        while(n>0) {
            cnt[n%10]++;
            n/=10;
        }
        ll x=(cnt[0]*len0[m]+cnt[1]*len1[m])%mod2;
        if(m>=8) {
            f(i,2,10) x=(x+cnt[i]*(len0[m-10+i]+len1[m-10+i]))%mod2;
        }
        else {
            f(i,2,10-m) x=(x+cnt[i])%mod2;
            f(i,10-m,10) x=(x+cnt[i]*2)%mod2;
        }
        cout<<x<<"\n";
    }
    return 0;
}
