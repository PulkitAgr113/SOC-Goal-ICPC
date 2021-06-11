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
    int t,n,x;
    cin>>t;
    while(t--) {
        cin>>n;
        vvi s(n+1);
        vvll sum(n+1);
        vll str(n+1,0);
        f(i,0,n) cin>>str[i];
        f(i,0,n) {
            cin>>x;
            s[str[i]].pb(x);
            str[i]=0;
        }
        f(i,1,n+1) {
            sort(s[i].begin(),s[i].end());
            x=s[i].size();
            f(j,0,x+1) {
                if(j==0) sum[i].pb(0);
                else sum[i].pb(sum[i][j-1]+s[i][j-1]);
            }
            f(k,1,x+1) str[k]+=sum[i][x]-sum[i][x%k];
        }
        f(k,1,n+1) cout<<str[k]<<" ";
        cout<<"\n";
    }
    return 0;
}
