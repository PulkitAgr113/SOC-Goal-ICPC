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
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        vi a(n);
        int depth=1,prev_width=1,curr_width=1,sign_changes=0;
        cin>>a[0]>>a[1];
        f(i,2,n) {
            cin>>a[i];
            curr_width++;
            if(a[i]<a[i-1]) {
                sign_changes++;
                if(sign_changes==prev_width) {
                    depth++;
                    prev_width=curr_width-1;
                    sign_changes=0;
                    curr_width=1;
                }
            }
        }
        cout<<depth<<"\n";
    }
    return 0;
}
