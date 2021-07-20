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
    int n,q,x;
    cin>>n;
    vd p(n);
    f(i,0,n) cin>>p[i];
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    if(p[0]==1) cout<<fixed<<setprecision(15)<<1;
    else {
        db sum=0,prod=1;
        f(i,0,n) {
            sum+=p[i]/(1-p[i]);
            prod*=(1-p[i]);
            if(sum>=1) break;
        }
        cout<<fixed<<setprecision(15)<<sum*prod;
    }
    return 0;
}
