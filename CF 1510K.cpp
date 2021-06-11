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
    int n;
    cin>>n;
    vi p(2*n),q(2*n),c;
    int steps=0,m;
    bool ans=false;
    f(i,0,2*n) {
        q[i]=i+1;
        cin>>p[i];
    }
    if(n%2==1) {
        f(i,0,2*n) {
            if(i%2==0) {
                for(int j=0;j<2*n;j+=2) swap(q[j],q[j+1]);
            }
            else if(i%2==1) {
                f(j,0,n) swap(q[j],q[j+n]);
            }
            steps++;
            bool v=true;
            f(j,0,2*n) {
                if(q[j]!=p[j]) {
                    v=false;
                    break;
                }
            }
            if(v) {
                ans=true;
                m=min(steps,2*n-steps);
                break;
            }
        }
    }
    else {
        f(i,0,4) {
            if(i%2==0) {
                for(int j=0;j<2*n;j+=2) swap(q[j],q[j+1]);
            }
            else if(i%2==1) {
                f(j,0,n) swap(q[j],q[j+n]);
            }
            steps++;
            bool v=true;
            f(j,0,2*n) {
                if(q[j]!=p[j]) {
                    v=false;
                    break;
                }
            }
            if(v) {
                ans=true;
                m=min(steps,4-steps);
                break;
            }
        }
    }
    if(ans) cout<<m;
    else cout<<"-1";
    return 0;
}
