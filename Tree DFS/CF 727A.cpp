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
 
vi ans;
bool found=false;
int steps=0;
unordered_map<int,int> m;
 
void dfs(ll a, ll b) {
    if(a%2==1) m[a]=(a-1)/10;
    else m[a]=a/2;
    if(b<a || found) return;
    if(b==a) {
        found=true;
        ans.pb(a);
        return;
    }
    dfs(2*a,b);
    dfs(10*a+1,b);
}
 
int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
    ll a,b;
    cin>>a>>b;
    dfs(a,b);
    if(!found) cout<<"NO";
    else {
        cout<<"YES\n";
        int flag=0;
        while(m[ans[flag]]!=a) {
            ans.pb(m[ans[flag]]);
            flag++;
        }
        ans.pb(a);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for(auto u:ans) cout<<u<<" ";
    }
    return 0;
}
