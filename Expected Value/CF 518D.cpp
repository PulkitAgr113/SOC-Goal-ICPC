#include<bits/stdc++.h>
using namespace std;

#define f(i,x,n) for (int i=x;i<n;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long int ll ;
typedef vector<int> vi ;
typedef priority_queue<int> pqi ;
typedef priority_queue<pair<int,int>> pqp ;
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
    int n,t;
    db p;
    cin>>n>>p>>t;
    vector<vd> dp(t+1,vd(n+1,0));
    dp[0][0]=1;
    f(i,1,t+1) {
        f(j,1,n) dp[i][j]=p*dp[i-1][j-1]+(1-p)*dp[i-1][j];
        dp[i][0]=(1-p)*dp[i-1][0];
        dp[i][n]=p*dp[i-1][n-1]+dp[i-1][n];
    }
    db exp_val=0;
    f(i,1,n+1) exp_val+=i*dp[t][i];
    cout<<fixed<<setprecision(15)<<exp_val;
    return 0;
}
